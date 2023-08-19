#include "al/util.hpp"
#include "fl/tas.h"
#include "fl/ui/ui.h"
#include "fl/util.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "game/StageScene/ChangeStageInfo.h"
#include "nn/mem.h"
#include "rs/util.hpp"
#include "sead/prim/seadSafeString.h"
#include <fl/packet.h>
#include <mem.h>
#include <nn/init.h>
#include <str.h>

namespace smo {
u32 OutPacketLog::calcLen() const
{
    return strlen(message) + 1;
}

void OutPacketLog::construct(u8* dst) const
{
    *dst = type;
    strcpy((char*)dst + 1, message);
}

void InPacketPlayerScriptInfo::parse(const u8* data, u32 len)
{
    fl::TasHolder& h = fl::TasHolder::instance();
    if (h.isRunning)
        return;
    scriptName = (char*)alloc(len + 1);
    fl::memcpy(scriptName, data, len);
    scriptName[len] = '\0';
}

void InPacketPlayerScriptInfo::on(Server& server)
{
    fl::TasHolder& h = fl::TasHolder::instance();
    if (h.isRunning)
        return;
    h.setScriptName(scriptName);
    if (h.frames) {
        dealloc(h.frames);
        h.frames = nullptr;
    }
    h.frameCount = 0;
}

void InPacketPlayerTeleport::parse(const u8* data, u32 len)
{
    pos.x = *(float*)&data[0];
    pos.y = *(float*)&data[4];
    pos.z = *(float*)&data[8];
}

void InPacketPlayerTeleport::on(Server& server)
{
    StageScene* stageScene = fl::ui::PracticeUI::instance().getStageScene();
    if (!stageScene)
        return;
    PlayerActorHakoniwa* player = rs::getPlayerActor(stageScene);
    player->startDemoPuppetable();
    al::setTrans(player, pos);
    player->endDemoPuppetable();
}

void InPacketPlayerGo::parse(const u8* data, u32 len)
{
    scenario = *(signed char*)&data[0];
    u8 stageLength = data[1];
    u8 entranceLength = data[2];

    stageName = (char*)alloc(stageLength + 1);
    fl::memcpy(stageName, &data[3], stageLength);
    stageName[stageLength] = '\0';

    entrance = (char*)alloc(entranceLength + 1);
    fl::memcpy(entrance, &data[3 + stageLength], entranceLength);
    entrance[entranceLength] = '\0';

    startScript = data[len - 1];
}

void InPacketPlayerGo::on(Server& server)
{
    StageScene* stageScene = fl::ui::PracticeUI::instance().getStageScene();
    if (!stageScene) {
        if (entrance)
            free(entrance);
        if (stageName)
            free(stageName);
        return;
    }

    ChangeStageInfo info = ChangeStageInfo(stageScene->mDataHolder, entrance, stageName, false, scenario, { 0 });
    stageScene->mDataHolder->changeNextStage(&info, 0);

    if (entrance)
        free(entrance);
    if (stageName)
        free(stageName);

    if (startScript && fl::TasHolder::instance().frames)
        fl::TasHolder::instance().startPending = true;
}

void InPacketPlayerScriptData::parse(const u8* data, u32 len)
{
    fl::TasHolder& h = fl::TasHolder::instance();
    if (h.isRunning)
        h.stop();
    size_t cur = h.frameCount;
    if (h.frames) {
        h.frameCount += len / sizeof(fl::TasFrame);
        h.frames = (fl::TasFrame*)realloc(h.frames, h.frameCount * sizeof(fl::TasFrame));
    } else {
        h.frames = (fl::TasFrame*)alloc(len);
        h.frameCount = len / sizeof(fl::TasFrame);
    }
    fl::memcpy(&h.frames[cur], data, len);
}

void InPacketPlayerScriptData::on(Server& server) { }

void InPacketSelect::parse(const u8* data, u32 len)
{
    option = data[0];
}

void InPacketSelect::on(Server& server)
{
    auto& ui = fl::ui::PracticeUI::instance();
    ui.curLine = option;
}

void InPacketUINavigation::parse(const u8* data, u32 len)
{
    inputMask = *((long*)data);
}

void InPacketUINavigation::on(Server& server)
{
    auto& ui = fl::ui::PracticeUI::instance();
    ext_input |= inputMask;
}

void InPacketPlayerScriptState::parse(const u8* data, u32 len)
{
    state = data[0];
}

void InPacketPlayerScriptState::on(Server& server)
{
    auto& tas = fl::TasHolder::instance();
    if(state == 1) {
        if (tas.frames)
            tas.start();
    } else if(state == 0) {
        tas.stop();
    }
}
}
