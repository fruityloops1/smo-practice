#pragma once

#include "fl/tas.h"
#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>
#include <sead/prim/seadSafeString.h>
#include <fl/server.h>
#include <types.h>

namespace smo
{
    class Server;
    // negative numbers for outgoing, positive for incoming
    enum OutPacketType : u8
    {
        DummyInit = (u8) -1, Init = (u8) -2, Log = (u8) -3
    };

    class OutPacket
    {
    public:
        virtual u32 calcLen() {return 0;}
        virtual void construct(u8* dst) {}
    };

    enum InPacketType : u8
    {
        PlayerScriptInfo = 1, PlayerScriptData = 2, PlayerTeleport = 3, PlayerGo = 4
    };

    class InPacket
    {
    public:
        virtual void parse(const u8* data, u32 len) {}
        virtual void on(Server& server) {}
    };

    class OutPacketLog : public OutPacket
    {
    public:
        enum LogType : u8
        {
            Log = 0, Warning = 1, Error = 2, Fatal = 3
        };
        LogType type;
        char* message;
        u32 calcLen();
        void construct(u8* dst);
    };

    class InPacketPlayerScriptInfo : public InPacket
    {
        char* scriptName = nullptr;
    public:
        void parse(const u8* data, u32 len);
        void on(Server& server);
    };

    class InPacketPlayerTeleport : public InPacket
    {
        sead::Vector3f pos;
    public:
        void parse(const u8* data, u32 len);
        void on(Server& server);
    };

    class InPacketPlayerGo : public InPacket
    {
        bool startScript = false;
        s8 scenario = -1;
        char* stageName = nullptr;
        char* entrance = nullptr;
    public:
        void parse(const u8* data, u32 len);
        void on(Server& server);
    };

    class InPacketPlayerScriptData : public InPacket
    {
    public:
        void parse(const u8* data, u32 len);
        void on(Server& server);
    };
}