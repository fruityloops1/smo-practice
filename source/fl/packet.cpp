#include "al/util.hpp"
#include "fl/tas.h"
#include "fl/ui.h"
#include "fl/util.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "game/StageScene/ChangeStageInfo.h"
#include "nn/mem.h"
#include "rs/util.hpp"
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

    void InPacketPlayerScriptInfo::parse(const u8* data, u32 len)
    {
        fl::TasHolder& h = fl::TasHolder::instance();
        if (h.isRunning) return;
        scriptName = (char*) alloc(len + 1);
        fl::memcpy(scriptName, data, len);
        scriptName[len] = '\0';
    }

    void InPacketPlayerScriptInfo::on(Server &server)
    {
        fl::TasHolder& h = fl::TasHolder::instance();
        if (h.isRunning) return;
        h.setScriptName(scriptName);
        if (h.frames)
        {
            dealloc(h.frames);
            h.frames = nullptr;
        }
        h.frameCount = 0;
    }

    void InPacketPlayerTeleport::parse(const u8* data, u32 len)
    {
        pos.x = *(float*) &data[0];
        pos.y = *(float*) &data[4];
        pos.z = *(float*) &data[8];
        rot.w = *(float*) &data[12];
        rot.x = *(float*) &data[16];
        rot.y = *(float*) &data[20];
        rot.z = *(float*) &data[24];
    }

    void InPacketPlayerTeleport::on(Server &server)
    {
        StageScene* stageScene = fl::PracticeUI::instance().getStageScene();
        if (!stageScene) return;
        PlayerActorHakoniwa* player = rs::getPlayerActor(stageScene);
        player->startDemoPuppetable();
        al::setTrans(player, pos);
        al::updatePoseQuat(player, rot);
        player->endDemoPuppetable();
    }

    void InPacketPlayerGo::parse(const u8* data, u32 len)
    {
        nn::mem::StandardAllocator* m = nn::init::GetAllocator();

        scenario = *(signed char*) &data[0];
        u8 stageLength = data[1];
        u8 entranceLength = data[2];

        stageName = (char*) m->Allocate(stageLength + 1);
        fl::memcpy(stageName, &data[3], stageLength);
        stageName[stageLength] = '\0';

        entrance = (char*) m->Allocate(entranceLength + 1);
        fl::memcpy(entrance, &data[3 + stageLength], entranceLength);
        entrance[entranceLength] = '\0';

        startScript = data[len - 1];
    }

    void InPacketPlayerGo::on(Server& server)
    {
        nn::mem::StandardAllocator* m = nn::init::GetAllocator();
        StageScene* stageScene = fl::PracticeUI::instance().getStageScene();
        if (!stageScene)
        {
            if (entrance) m->Free(entrance);
            if (stageName) m->Free(stageName);
        }
        
        ChangeStageInfo info = ChangeStageInfo(stageScene->mHolder, entrance, stageName, false, scenario, {0});
        stageScene->mHolder->changeNextStage(&info, 0);

        if (entrance) m->Free(entrance);
        if (stageName) m->Free(stageName);

        if (startScript && fl::TasHolder::instance().frames) fl::TasHolder::instance().startPending = true;
    }

    void InPacketPlayerScriptData::parse(const u8* data, u32 len)
    {
        fl::TasHolder& h = fl::TasHolder::instance();
        if (h.isRunning) return;
        size_t cur = h.frameCount;
        if (h.frames)
        {
            h.frameCount += len / sizeof(fl::TasFrame);
            h.frames = (fl::TasFrame*) realloc(h.frames, h.frameCount * sizeof(fl::TasFrame));
        }
        else
        {
            h.frames = (fl::TasFrame*) alloc(len);
            h.frameCount = len / sizeof(fl::TasFrame);
        }
        fl::memcpy(&h.frames[cur], data, len);
    }

    void InPacketPlayerScriptData::on(Server& server) {}

    void InPacketChangePage::parse(const u8* data, u32 len)
    {
        page = data[0];
    }

    void InPacketChangePage::on(Server &server)
    {
        fl::PracticeUI::instance().curPage = (fl::PracticeUI::Page) page;
    }
}