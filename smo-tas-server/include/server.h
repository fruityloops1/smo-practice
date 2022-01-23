#pragma once
#include <arpa/inet.h>
#include <string>
#include <types.h>
#include <unordered_map>
#include <packet.h>
#include <deque>

namespace smo
{
    class OutPacket;
    class Server;
    enum class OutPacketType : u8;
    class Client
    {
    private:
        void connect();
    public:
        void sendPacket(Server* parent, smo::OutPacket& packet, smo::OutPacketType type);
        void handlePacket(Server* parent, u8* data, s32 length);

        u64 uid;
        u32 addr;
        struct sockaddr_in client;
        std::string name;
    };

    class Server
    {
    private:
        s32 socketfd;
        void handleScript(std::deque<std::string> args);
        void loopThread();
    public:
        u8 start(u16 port);
        bool disconnect(u64 uid);
        s32 getSocket();
        Client c;
    };
}