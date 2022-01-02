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
    void Server::sendInit() {
            OutPacketType dummy = OutPacketType::DummyInit;
            nn::socket::SendTo(socket, &dummy, 1, 0, (struct sockaddr*) &server, sizeof(server));
            dummy = OutPacketType::Init;
            nn::socket::SendTo(socket, &dummy, 1, 0, (struct sockaddr*) &server, sizeof(server));
    }

    u8 Server::connect(const char* ipS, u16 port)
    {
        if (connected)
        {
            sendInit();
            return 4;
        }
        in_addr ip = {0};

        nn::nifm::Initialize();
        nn::nifm::SubmitNetworkRequest();

        while (nn::nifm::IsNetworkRequestOnHold()) {}

        if ((socket = nn::socket::Socket(AF_INET, SOCK_DGRAM, 0)) < 0) return 2;

        nn::socket::InetAton(ipS, &ip);

        int timeout = 100;
        nn::socket::SetSockOpt(socket, 0xffff, 0x1006, (const char*)&timeout, sizeof(timeout));

        server.port = nn::socket::InetHtons(port);
        server.family = 2;
        server.address = ip;

        sendInit();

        connected = true;

        if (!thread)
        {
            thread = (nn::os::ThreadType*) nn::init::GetAllocator()->Allocate(sizeof(nn::os::ThreadType));
            threadStack = aligned_alloc(0x1000, 0x15000);
            nn::os::CreateThread(thread, threadFunc, this, threadStack, 0x15000, 16, 0);
            nn::os::SetThreadName(thread, "UDP Thread");
            nn::os::StartThread(thread);
        }

        if (!nn::nifm::IsNetworkAvailable()) return 1;

        return 0;
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

    void Server::sendPacket(OutPacket& packet, OutPacketType type)
    {
        u32 len = packet.calcLen();
        
        u8 data[len + 1];
        data[0] = type;
        packet.construct(data + 1);
        nn::socket::SendTo(socket, data, len + 1, 0, (struct sockaddr*) &server, sizeof(server));
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
            default: break;
        }
    }

    bool Server::isConnected()
    {
        return connected;
    }
}

#undef IN_PACKET