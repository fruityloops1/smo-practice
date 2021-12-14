#pragma once

#include <fl/packet.h>
#include <nn/socket.h>
#include <types.h>

namespace smo
{
    class OutPacket;
    enum OutPacketType : u8;
    class Server
    {
    private:
        bool connected = false;
    public:
        u8 connect(const char* ip, u16 port);
        void disconnect();
        void sendPacket(OutPacket& packet, OutPacketType type);
        bool isConnected();
        void handlePacket();
        static Server& instance() {static Server s; return s;}
        s32 socket = -1;
        sockaddr server = {0};
    };
}