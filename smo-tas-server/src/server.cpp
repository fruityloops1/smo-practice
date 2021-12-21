#include "common.h"
#include "script.h"
#include "tas.h"
#include "types.h"
#include <chrono>
#include <ratio>
#include <server.h>
#include <packet.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>

#include <thread>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>
#include <sstream>
#include <vector>
#include <deque>
#include <filesystem>

#define MAX_PACKET_SIZE 0x400

#define IN_PACKET(TYPE) case smo::InPacketType::TYPE: {\
                InPacket##TYPE p;\
                p.parse(data + 1, length - 1);\
                p.on(*this, *parent);\
                break;}

namespace smo
{
    void smo::Client::connect()
    {
        struct in_addr ip;
        ip.s_addr = uid;
        std::cout << "Client connected from " << inet_ntoa(ip) << std::endl;
    }

    void smo::Client::handlePacket(Server* parent, u8* data, s32 length)
    {
        if (length < 1) return;
        switch ((InPacketType) data[0])
        {
            case smo::InPacketType::DummyInit:
            {
                break;
            }
            case smo::InPacketType::Init:
            {
                connect();
                break;
            }
            IN_PACKET(Log)
            default: break;
        }
    }

    void smo::Client::sendPacket(Server* parent, smo::OutPacket& packet, smo::OutPacketType type)
    {
        u32 len = packet.calcLen();
        u8* packetData = new u8[len + 1];
        packet.construct(packetData + 1);
        packetData[0] = (u8) type;
        sendto(parent->getSocket(), packetData, len + 1, 0, (struct sockaddr*) &client, sizeof(client));
        delete[] packetData;
    }

    bool smo::Server::disconnect(u64 uid)
    {return false;}

    u8 smo::Server::start(u16 port)
    {
        struct sockaddr_in addr, cli;

        socketfd = socket(AF_INET, SOCK_DGRAM, 0);

        if (socketfd == -1) return 1;

        setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, nullptr, sizeof(int));

        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr.sin_port = htons(port);

        int rval = bind(socketfd, (struct sockaddr*) &addr, sizeof(addr));
        if (rval != 0) return 2;

        listen(socketfd, 2);

        u8 buf[12288];
        s32 size = 0;

        std::thread loop(&smo::Server::loopThread, this);
        loop.detach();

        while (true)
        {
            s32 length = sizeof(cli);

            struct sockaddr_in client;
            socklen_t addrSize;

            if ((size = recvfrom(socketfd, buf, sizeof(buf), 0, (struct sockaddr *) &client, &addrSize)) < 0) continue;
            u64 uid = client.sin_addr.s_addr + client.sin_port;
            
            c.uid = uid;
            c.addr = client.sin_addr.s_addr;
            c.client = client;
            c.handlePacket(this, buf, size);
        }

        return 0;
    }

    void smo::Server::loopThread()
    {
        using namespace std::chrono_literals;
        const std::unordered_map<std::string, std::function<void(std::deque<std::string>&)>> cmd = {
            {"tp", [this](std::deque<std::string>& args)
            {
                if (args.size() != 3)
                {
                    std::cout << "tp <X> <Y> <Z>" << std::endl;
                    return;
                }
                Vector3f pos;
                try
                {
                    pos.x = std::stof(args[0]);
                    pos.y = std::stof(args[1]);
                    pos.z = std::stof(args[2]);
                }
                catch (std::invalid_argument e)
                {
                    std::cout << "Invalid Number" << std::endl;
                    return;
                }
                OutPacketPlayerTeleport p;
                p.pos = pos;
                c.sendPacket(this, p, smo::OutPacketType::PlayerTeleport);
            }},
            {"go", [this](std::deque<std::string>& args)
            {
                if (args.size() == 0)
                {
                    std::cout << "go <stage name> <scenario> <entrance>" << std::endl;
                    return;
                }
                std::string entrance = "start";
                s8 scenario = -1;
                if (args.size() >= 2)
                {
                    try
                    {
                        scenario = std::stoi(args[1]);
                    } catch(std::invalid_argument e)
                    {
                        std::cout << "Invalid Number" << std::endl;
                        return;
                    }
                    if (scenario == 0)
                    {
                        std::cout << "Scenario cannot be 0" << std::endl;
                        return;
                    }
                }
                if (args.size() == 3) entrance = args[2];
                const std::vector<std::string>& stages = getStages();
                if (std::find(stages.begin(), stages.end(), args[0]) == stages.end())
                {
                    std::cout << "Stage doesn't exist" << std::endl;
                    return;
                }
                OutPacketPlayerGo p;
                p.scenario = scenario;
                p.stageName = args[0];
                p.entrance = entrance;
                c.sendPacket(this, p, smo::OutPacketType::PlayerGo);
            }},
            {"script", [this](std::deque<std::string>& args)
            {
                if (args.size() != 1)
                {
                    std::cout << "script <script file>" << std::endl;
                    return;
                }
                if (!std::filesystem::exists(args[0]))
                {
                    std::cout << "Specified script file does not exist" << std::endl;
                    return;
                }
                std::ifstream scriptFile(args[0]);
                fl::TasScript script = fl::script::fromText(scriptFile);
                scriptFile.close();

                OutPacketPlayerScriptInfo p;
                p.scriptName = args[0];
                c.sendPacket(this, p, smo::OutPacketType::PlayerScriptInfo);

                std::this_thread::sleep_for(std::chrono::milliseconds(32));

                OutPacketPlayerScriptData pD;
                {
                    u32 i = 0;
                    for (fl::TasFrame& f : script.frames)
                    {         
                        pD.script.frames.push_back(f);               
                        i++;
                        if (i >= 1500)
                        {
                            c.sendPacket(this, pD, smo::OutPacketType::PlayerScriptData);
                            pD.script.frames.clear();
                            i = 0;
                            std::this_thread::sleep_for(std::chrono::milliseconds(script.frames.size() / 10000));
                        }
                    }
                    if (i != 0)
                    {
                        c.sendPacket(this, pD, smo::OutPacketType::PlayerScriptData);
                    }
                }
            }},
            {"help", [this](std::deque<std::string>& args)
            {
                std::cout << "tp <X> <Y> <Z>\n  Teleport Player to position" << std::endl;
                std::cout << "go <stage name> <entrance> <scenario>\n  Teleport Player to stage" << std::endl;
                std::cout << "script <script file>\n  Start script" << std::endl;
            }}
        };
        std::deque<std::string> lastCommand;
        while (true)
        {
            std::cout << "> " << std::flush;
            std::string command;
            getline(std::cin, command);
            std::deque<std::string> args = fl::split(command, ' ');
            if (args[0] == "l") args = lastCommand;
            else lastCommand = args;
            if (cmd.find(args[0]) != cmd.end())
            {
                std::function<void(std::deque<std::string>&)> fun = cmd.at(args[0]);
                args.pop_front();
                fun(args);
            }
            else if (command != "")
            {
                std::cout << "Unknown Command. Type \"help\" for a list of commands." << std::endl;
            }
        }
    }

    s32 smo::Server::getSocket() {return socketfd;}
}