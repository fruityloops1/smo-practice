#pragma once

#include "tas.h"
#include <string>
#include <types.h>
#include <unordered_map>
#include <vector>
#include <server.h>

namespace smo
{
    class Client;
    class Server;
    // negative numbers for incoming, positive for outgoing
    enum class InPacketType : u8
    {
        DummyInit = (u8) -1, Init = (u8) -2, Log = (u8) -3
    };
    
    class InPacket
    {
    public:
        virtual void parse(const u8* data, u32 len) {}
        virtual void on(smo::Client& sender, smo::Server& server) {}
    };

    enum class OutPacketType : u8
    {
        PlayerScriptInfo = 1, PlayerScriptData = 2, PlayerTeleport = 3, PlayerGo = 4
    };
    
    class OutPacket
    {
    public:
        virtual u32 calcLen() {return 0;}
        virtual void construct(u8* dst) {}
    };

    class InPacketLog : public InPacket
    {
        enum LogType : u8
        {
            Log = 0, Warning = 1, Error = 2, Fatal = 3
        };
        LogType type;
        std::string message;
    public:
        void parse(const u8* data, u32 len);
        void on(smo::Client& sender, smo::Server& server);
    };

    class OutPacketPlayerScriptInfo : public OutPacket
    {
    public:
        std::string scriptName;

        u32 calcLen();
        void construct(u8* dst);
    };

    class OutPacketPlayerTeleport : public OutPacket
    {
    public:
        Vector3f pos;
        Quatf rot;

        u32 calcLen();
        void construct(u8* dst);
    };

    class OutPacketPlayerGo : public OutPacket
    {
    public:
        bool startScript = false;
        s8 scenario;
        std::string stageName;
        std::string entrance;

        u32 calcLen();
        void construct(u8* dst);
    };

    class OutPacketPlayerScriptData : public OutPacket
    {
    public:
        fl::TasScript script;

        u32 calcLen();
        void construct(u8* dst);
    };
}