#include "al/util.hpp"
#include "fl/packet.h"
#include "game/Layouts/CoinCounter.h"
#include "nn/init.h"
#include "nn/os.hpp"
#include "types.h"
#include <fl/server.h>
#include <mem.h>
#include <nn/nifm.h>
#include <nn/socket.h>
#include <sead/basis/seadNew.hpp>

#define IN_PACKET(TYPE) case smo::InPacketType::TYPE: {\
                InPacket##TYPE p;\
                p.parse(buf + 1, len - 1);\
                p.on(*this);\
                break;}

void threadFunc(void* args)
{
    smo::Server* server = (smo::Server*) args;
    nn::TimeSpan w = nn::TimeSpan::FromNanoSeconds(1000000);
    u8* buf = (u8*) nn::init::GetAllocator()->Allocate(30720);
    while (true)
    {
        server->handlePacket(buf, 30720);
        nn::os::YieldThread();
        nn::os::SleepThread(w);
    }
    nn::init::GetAllocator()->Free(buf);
}

namespace smo
{
    void Server::sendInit(const char* ipS) {
        in_addr ip = {0};
        nn::socket::InetAton(ipS, &ip);

        server.port = nn::socket::InetHtons(SERVER_PORT);
        server.family = 2;
        server.address = ip;

        OutPacketType dummy = OutPacketType::DummyInit;
        nn::socket::SendTo(socket, &dummy, 1, 0, (struct sockaddr*) &server, sizeof(server));
        dummy = OutPacketType::Init;
        nn::socket::SendTo(socket, &dummy, 1, 0, (struct sockaddr*) &server, sizeof(server));
        
        connected = true;
    }

    void Server::start() {
        nn::nifm::Initialize();
        nn::nifm::SubmitNetworkRequest();

        while (nn::nifm::IsNetworkRequestOnHold()) {}

        if ((socket = nn::socket::Socket(AF_INET, SOCK_DGRAM, 0)) < 0) return;

        int timeout = 100;
        nn::socket::SetSockOpt(socket, 0xffff, 0x1006, (const char*)&timeout, sizeof(timeout));

        sockaddr client = {0};
        client.port = nn::socket::InetHtons(CLIENT_PORT);
        client.family = 2;
        nn::socket::Bind(socket, &client, sizeof(client));

        if (!thread)
        {
            thread = (nn::os::ThreadType*) nn::init::GetAllocator()->Allocate(sizeof(nn::os::ThreadType));
            threadStack = aligned_alloc(0x1000, 0x15000);
            nn::os::CreateThread(thread, threadFunc, this, threadStack, 0x15000, 16, 0);
            nn::os::SetThreadName(thread, "UDP Thread");
            nn::os::StartThread(thread);
        }

        started = true;
    }

    void Server::connect(const char* ipS)
    {
        if (!started)
            start();

        sendInit(ipS);
    }

    void Server::disconnect()
    {
        if (thread)
        {
            nn::os::SuspendThread(thread);
            nn::os::DestroyThread(thread);
            /*free(thread);
            if (threadStack) free(threadStack);
            thread = nullptr;
            threadStack = nullptr;*/
        }
        if (socket != -1)
        {
            nn::socket::Close(socket);
            socket = -1;
        }
        connected = false;
    }

    void Server::sendPacket(const OutPacket& packet, OutPacketType type)
    {
        u32 len = packet.calcLen();
        
        u8 data[len + 1];
        data[0] = type;
        packet.construct(data + 1);
        nn::socket::SendTo(socket, data, len + 1, 0, (struct sockaddr*) &server, sizeof(server));
    }

    void Server::log(const char* fmt, ...) {
        char buf[0x100];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buf, sizeof(buf), fmt, args);
        va_end(args);
        const auto& packet = OutPacketLog(buf);
        sendPacket(packet, OutPacketType::Log);
    }

    void Server::handlePacket(u8* buf, size_t bufSize)
    {
        if (!connected) return;
        static int i = 0;
        i++;
        u32 size = sizeof(server);
        u32 len = nn::socket::RecvFrom(socket, buf, bufSize, 0, &server, &size);
        switch ((InPacketType) buf[0])
        {
            case 0: break; //timeout
            IN_PACKET(PlayerScriptInfo);
            IN_PACKET(PlayerTeleport);
            IN_PACKET(PlayerGo);
            IN_PACKET(PlayerScriptData);
            IN_PACKET(ChangePage);
            default: break;
        }
    }

    bool Server::isConnected()
    {
        return connected;
    }
}

#undef IN_PACKET
