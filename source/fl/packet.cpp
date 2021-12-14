#include "fl/tas.h"
#include "fl/util.h"
#include "sead/prim/seadSafeString.h"
#include <fl/packet.h>
#include <str.h>
#include <mem.h>
#include <nn/init.h>

namespace smo
{
    u32 OutPacketLog::calcLen()
    {
        return strlen(message) + 1;
    }

    void OutPacketLog::construct(u8* dst)
    {
        *dst = type;
        strcpy((char*) dst + 1, message);
    }

    void InPacketPlayerStartScript::parse(const u8* data, u32 len)
    {
        frames = (fl::TasFrame*) nn::init::GetAllocator()->Allocate(len);
        this->count = len / sizeof(fl::TasFrame);
        fl::memcpy(frames, data, len);
    }

    void InPacketPlayerStartScript::on(Server &server)
    {
        fl::TasHolder& h = fl::TasHolder::instance();
        h.start(frames, count);
    }
}