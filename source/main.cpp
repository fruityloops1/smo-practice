#include "al/input/JoyPadAccelPoseAnalyzer.h"
#include "al/util.hpp"
#include "game/Layouts/CommonVerticalList.h"
#include "al/layout/RollParts.h"
#include "fl/tas.h"
#include "game/Layouts/MapLayout.h"
#include "game/Layouts/ShineListLayout.h"
#include "rs/util.hpp"
#include "sead/math/seadVector.h"
#include <fl/server.h>
#include <fl/ui/ui.h>
#include <mem.h>
#include <nn/init.h>
#include <nn/atk/SoundStartable.h>
#include "game/Player/PlayerJointControlKeeper.h"
#include "game/Actors/Megane.h"
#include "al/execute/ExecuteTableHolder.h"

#include <fl/nerve.h>

void sequenceDrawHook(al::Sequence* sequence)
{
    bool shouldRender = fl::ui::PracticeUI::instance().options.shouldRender;
    if(shouldRender)
        sequence->drawMain();
}

void tasDrawKitHook(const al::Scene* scene, const char* kitName) {
    fl::TasHolder::instance().update();

    al::drawKit(scene, kitName);
}

bool bgmStartSoundHook(nn::atk::SoundStartable* self, nn::atk::SoundHandle* a1, const char* a2, const nn::atk::SoundStartable::StartInfo* a3) {
    if (fl::ui::PracticeUI::instance().options.muteBgm)
        return false;
    return self->StartSound(a1, a2, a3);
}

int koopaHatRandomizerHook(int a1, int a2, int level, int* arr, int arrLength) {
    int val = ((int(*)(int,int,int,int*,int)) uintptr_t(fl::__module_start__) + 0x000A34E4)(a1, a2, level, arr, arrLength);
    return fl::ui::PracticeUI::instance().options.overrideBowserHat0 ? 0 : val;
}

int koopaHatRandomHook(int param) {
    return fl::ui::PracticeUI::instance().options.overrideBowserHat0 ? param-1 : al::getRandom(param);
}

void stageSceneControlHook()
{
    __asm("MOV X19, X0");

    StageScene* stageScene;
    __asm("MOV %[result], X0"
          : [result] "=r"(stageScene));

    fl::ui::PracticeUI::instance().update(stageScene);

    __asm("MOV X0, %[input]"
          : [input] "=r"(stageScene));
}

void stageSceneKillHook() {
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    ui.kill();
    fl::TasHolder::instance().onStageKill();

    __asm("MOV X0, X19");
}

void setGotShineVar(GameDataHolderWriter writer, const ShineInfo* shineInfo)
{
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    if (!ui.options.shineRefresh)
        writer.mPlayingFile->setGotShine(shineInfo);
}

void setPlayerJointUpdate(PlayerJointControlKeeper* keeper)
{
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    // if (!ui.options.gravityChanged)
        keeper->update();
}


void executeTableHolderDrawCtor(al::ExecuteTableHolderDraw* table) {
    table->debug_Enabled = true;
    // __asm("STR X23, [X0, #0x88]");
    // memset(&table->mListAll, 0, 0x68);
    __asm("ADD X0, X0, #0x18");
}

void executeTableHolderDrawExecute(al::ExecuteTableHolderDraw* table) {
    if (table->arr1.size() <= 0 || !table->debug_Enabled) return;
    int idx = 0;
    while (idx < table->arr1.size()) {
        table->arr1[idx]->executeList();
        idx++;
    }
}

void shineListLayoutListHook(ShineListLayout* lyt) {
    if (al::isFirstStep(lyt))
        al::startAction(lyt, "Wait", nullptr);

    if (lyt->mRollParts->isJustChangeRoll()) {
        lyt->mWorldIdx = lyt->mRollParts->iVar1;
        lyt->updateWorldInfo();
    }

    lyt->mTopIndices[lyt->getSelectedWorldId()] = lyt->mVerticalList->mTopIdx;
    lyt->mCursorIndices[lyt->getSelectedWorldId()] = lyt->mVerticalList->mCursorIdx;

    int input = lyt->mInput;
    if (input < 3) {

    }
}

int fgetPadAccelerationDeviceNum(int port)
{
    return fl::TasHolder::instance().isRunning ? 2 : al::getPadAccelerationDeviceNum(port);
}

bool isGotShineVar(GameDataHolderAccessor accessor, const ShineInfo* shineInfo)
{
    return fl::ui::PracticeUI::instance().options.gotShineRefresh ? false : accessor.mPlayingFile->isGotShine(shineInfo);
}

bool isEnableCheckpointWarpVar(MapLayout* layout)
{
    return fl::ui::PracticeUI::instance().options.alwaysWarp ? true : layout->isEnableCheckpointWarp();
}

bool isEnableSaveVar(StageScene* stageScene)
{
    return fl::ui::PracticeUI::instance().options.disableAutoSave ? false : stageScene->isEnableSave();
}

bool isDefeatKoopaLv1Var(StageScene* stageScene)
{
#if SMOVER == 100
    return fl::ui::PracticeUI::instance().options.skipBowser ? true : stageScene->isDefeatKoopaLv1();
#endif
#if SMOVER == 130
    static int functionCalls = 0;
    if (!fl::ui::PracticeUI::instance().options.skipBowser) {
        functionCalls = 0;
        return stageScene->isDefeatKoopaLv1();
    }

    // When debugging, returning true right away will skip Lost and go straight to (Day!) Metro with a broken Odyssey back in Wooded.
    // Since isDefeatKoopaLv1 is called multiple times, we can return false the first time, then return true the second time, which
    // seems to correctly skip the Bowser fight. This is a very hacky way of skipping the Bowser fight, so if there is some way to
    // deduce from other game variables which function call we're in, that would be ideal. It would eliminate the need to introduce
    // our own variable to keep track of the number of isDefeatKoopaLv1 calls.
    functionCalls++;
    if (functionCalls == 2) {
        functionCalls = 0;
        return true;
    }

    return false;
#endif
}

bool isTriggerRollingRestartSwingVar(PlayerInput* playerInput) {
    return fl::ui::PracticeUI::instance().options.buttonMotionRoll ? true : playerInput->isTriggerRollingRestartSwing();
}

void setLoadDataSelectingCurrentVar() {
    __asm ("LDR W20, [X8, #0x3C]");

    GameDataHolder* holder;
    __asm ("MOV %[result], X0" : [result] "=r" (holder));

    s32 fileId = fl::ui::PracticeUI::instance().options.loadCurrentFile ? 5 : holder->getPlayingFileId();

    __asm ("MOV X0, %[input]" : [input] "=r" (fileId));
}

void setLoadDataSelectingConfirmVar() {
    if (fl::ui::PracticeUI::instance().options.loadFileConfirm)
        __asm ("ADD X9, X8, #0x78");
    else
        __asm ("ADD X9, X8, #0x70");
}

void setRepeatCapBounceVar() {
    if (fl::ui::PracticeUI::instance().options.repeatCapBounce)
        __asm ("MOV W8, #1");
    else
        __asm ("LDRB W8, [X8, #0x38]");
}

void setRepeatRainbowSpinVar() {
    if (fl::ui::PracticeUI::instance().options.repeatRainbowSpin)
        __asm ("MOV W8, #1");
    else
        __asm ("LDRB W8, [X8, #0x39]");
}

void setWallJumpCapBounceVar() {
    if (fl::ui::PracticeUI::instance().options.wallJumpCapBounce)
        __asm ("MOV W8, WZR");
    else
        __asm ("LDRB W8, [X8]");
}

void setDamageVar(PlayerHitPointData* hitPointData) {
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    if (!ui.options.noDamageLife)
        hitPointData->damage();
}

int findUnlockShineNumVar(GameDataHolder* holder, bool* param_1, int param_2) {
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    if (ui.options.disableShineNumUnlock) {
        return 0;
    }
    return holder->findUnlockShineNum(param_1, param_2);
}

void nerveKeeperUpdateVar() {
    // __asm ("LDR W8, [X18, #0x18]");
    al::NerveKeeper* nerveKeeper;
    __asm ("MOV %[result], X19" : [result] "=r" (nerveKeeper));

    nerveKeeper->mStep++;

    __asm ("MOV X19, %[input]" : [input] "=r" (nerveKeeper));
}

bool setPlayerEnableToSeeOddSpaceVar(al::LiveActor const* actor) {
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    if (ui.options.showOddSpace)
        return true;

    PlayerActorHakoniwa* player = al::getPlayerActor(actor, 0);
    if(!player) return false;
    PlayerHackKeeper* hackKeeper = player->getPlayerHackKeeper();
    if (!hackKeeper || !al::isEqualString(hackKeeper->getCurrentHackName(), "Megane"))
        return false;

    Megane* megane = static_cast<Megane*>(hackKeeper->mCurrentHackActor);
    return megane->isWearingGlasses();
}

bool isTriggerSnapShotModeVar(const al::IUseSceneObjHolder* objHolder)
{
    return showMenu || fl::TasHolder::instance().isRunning ? false : rs::isTriggerSnapShotMode(objHolder);
}

bool isTriggerAmiiboModeVar(const al::IUseSceneObjHolder* objHolder)
{
    return showMenu ? false : rs::isTriggerAmiiboMode(objHolder);
}

bool fisModeDiverOrJungleGymRom()
{
    return fl::ui::PracticeUI::instance().modes.isModeDiverOrJungleGymRom;
}

bool fisModeDiverRom()
{
    return fl::ui::PracticeUI::instance().modes.isModeDiverRom;
}

bool fisModeJungleGymRom()
{
    return fl::ui::PracticeUI::instance().modes.isModeJungleGymRom;
}

bool fisModeE3LiveRom()
{
    return fl::ui::PracticeUI::instance().modes.isModeE3LiveRom;
}

bool fisModeE3MovieRom()
{
    return fl::ui::PracticeUI::instance().modes.isModeE3MovieRom;
}

bool fisModeEpdMovieRom()
{
    return fl::ui::PracticeUI::instance().modes.isModeEpdMovieRom;
}

bool fisPadTriggerLMotion(int port)
{
    return fl::TasHolder::instance().isRunning ? false : al::isPadTriggerL(port);
}

void motionUpdate(al::JoyPadAccelPoseAnalyzer* dis)
{
    if (!fl::TasHolder::instance().isRunning) {
        dis->update();
        return;
    }
    fl::TasHolder& h = fl::TasHolder::instance();
    int controllerPort;
    if (dis->mControllerPort < 0)
        controllerPort = al::getMainControllerPort();
    else
        controllerPort = al::getPlayerControllerPort(dis->mControllerPort);
    dis->mAccelDeviceNum = al::getPadAccelerationDeviceNum(controllerPort);

    if (al::isPadTriggerL(controllerPort)) {
        if (h.oldMotion) {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = { 0.0f, 1.0f };
            dis->mAccelRightVel = { 0.0f, 1.0f };
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        } else if (al::isPadTriggerUp(controllerPort)) {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = { 0.0f, 1.0f };
            dis->mAccelRightVel = { 0.0f, 1.0f };
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        } else if (al::isPadTriggerDown(controllerPort)) {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = { 0.0f, -1.0f };
            dis->mAccelRightVel = { 0.0f, -1.0f };
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        } else if (al::isPadTriggerLeft(controllerPort)) {
            dis->mSwingRight = false;
            dis->mSwingLeft = true;
            dis->mSwingAny = true;
            dis->mAccelLeftAccel = { -1.0f, 0.0f };
            dis->mAccelLeftVel = { -1.0f, 0.0f };
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
        } else if (al::isPadTriggerRight(controllerPort)) {
            dis->mSwingRight = true;
            dis->mSwingLeft = false;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = { 1.0f, 0.0f };
            dis->mAccelRightVel = { 1.0f, 0.0f };
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        } else {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = { 0.0f, 1.0f };
            dis->mAccelRightVel = { 0.0f, 1.0f };
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
    } else {
        if (al::isPadTriggerUp(controllerPort)) {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = { 0.0f, 1.0f };
            dis->mAccelLeftAccel = { 0.0f, 1.0f };
            dis->mAccelRightAccel = { 0.0f, 1.0f };
            dis->mAccelLeftVel = { 0.0f, 1.0f };
            dis->mAccelRightVel = { 0.0f, 1.0f };
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        } else if (al::isPadTriggerLeft(controllerPort)) {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = { -1.0f, 0.0f };
            dis->mAccelLeftAccel = { -1.0f, 0.0f };
            dis->mAccelRightAccel = { -1.0f, 0.0f };
            dis->mAccelLeftVel = { -1.0f, 0.0f };
            dis->mAccelRightVel = { -1.0f, 0.0f };
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        } else if (al::isPadTriggerRight(controllerPort)) {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = { 1.0f, 0.0f };
            dis->mAccelLeftAccel = { 1.0f, 0.0f };
            dis->mAccelRightAccel = { 1.0f, 0.0f };
            dis->mAccelLeftVel = { 1.0f, 0.0f };
            dis->mAccelRightVel = { 1.0f, 0.0f };
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        } else if (al::isPadTriggerDown(controllerPort)) {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = { 0.0f, -1.0f };
            dis->mAccelLeftAccel = { 0.0f, -1.0f };
            dis->mAccelRightAccel = { 0.0f, -1.0f };
            dis->mAccelLeftVel = { 0.0f, -1.0f };
            dis->mAccelRightVel = { 0.0f, -1.0f };
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        } else {
            dis->mSwingLeft = false;
            dis->mSwingRight = false;
            dis->mSwingAny = false;
            dis->mAccelCombinedVel = { 0.0f, 0.0f };
            dis->mAccelLeftAccel = { 0.0f, 0.0f };
            dis->mAccelRightAccel = { 0.0f, 0.0f };
            dis->mAccelLeftVel = { 0.0f, 0.0f };
            dis->mAccelRightVel = { 0.0f, 0.0f };
            dis->mHistoryLeft.hist0 = 0.0f;
            dis->mHistoryRight.hist0 = 0.0f;
            dis->mHistoryLeft.hist1 = 0.0f;
            dis->mHistoryRight.hist1 = 0.0f;
        }
    }
}

bool isPatternReverse()
{
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    bool b = al::isHalfProbability();
    if (ui.curPattern != fl::ui::PracticeUI::Random)
        b = ui.mPatternEntries[ui.curPattern].reverse == 1;
    return b;
}

int getMofumofuTarget(int a)
{
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    int r = al::getRandom(a);
    if (ui.curPattern != fl::ui::PracticeUI::Random)
        r = ui.mPatternEntries[ui.curPattern].target;
    return r;
}
