#include "al/util.hpp"
#include "fl/packet.h"
#include "game/Layouts/CoinCounter.h"
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

namespace smo
{
    u8 Server::connect(const char* ipS, u16 port)
    {
        if (connected) return 4;
        in_addr ip = {0};

        nn::nifm::Initialize();
        nn::nifm::SubmitNetworkRequest();

        while (nn::nifm::IsNetworkRequestOnHold()) {}

        if ((socket = nn::socket::Socket(AF_INET, SOCK_DGRAM, 0)) < 0) return 2;

        nn::socket::InetAton(ipS, &ip);

        server.port = nn::socket::InetHtons(port);
        server.family = 2;
        server.address = ip;

        OutPacketType dummy = OutPacketType::DummyInit;

        nn::socket::SendTo(socket, &dummy, 1, 0, (struct sockaddr*) &server, sizeof(server));
        dummy = OutPacketType::Init;
        nn::socket::SendTo(socket, &dummy, 1, 0, (struct sockaddr*) &server, sizeof(server));

        connected = true;
        if (!nn::nifm::IsNetworkAvailable()) return 1;

        return 0;
    }

    void Server::disconnect()
    {
        if (socket != -1)
        {
            nn::socket::Close(socket);
            socket = -1;
        }
        connected = false;
    }

    void Server::sendPacket(OutPacket& packet, OutPacketType type)
    {
        u32 len = packet.calcLen();
        
        u8 data[len + 1];
        data[0] = type;
        packet.construct(data + 1);
        nn::socket::SendTo(socket, data, len + 1, 0, (struct sockaddr*) &server, sizeof(server));
    }

    void Server::handlePacket()
    {
        if (!connected) return;
        static int i = 0;
        i++;
        u8 buf[4096];
        u32 size = sizeof(server);
        u32 len = nn::socket::RecvFrom(socket, buf, sizeof(buf), 0, &server, &size);
        switch ((InPacketType) buf[0])
        {
            IN_PACKET(PlayerStartScript);
            default: break;
        };
    }

    bool Server::isConnected()
    {
        return connected;
    }
}

#undef IN_PACKET