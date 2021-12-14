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
    enum OutPacketType : u8
    {
        DummyInit = 0, Init = 1, Log = 2
    };

    class OutPacket
    {
    public:
        virtual u32 calcLen() {return 0;}
        virtual void construct(u8* dst) {}
    };

    enum InPacketType : u8
    {
        PlayerStartScript = 0
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

    class InPacketPlayerStartScript : public InPacket
    {
        fl::TasFrame* frames;
        u32 count;
    public:
        void parse(const u8* data, u32 len);
        void on(Server& server);
    };
}