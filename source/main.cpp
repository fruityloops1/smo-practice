#include "al/input/JoyPadAccelPoseAnalyzer.h"
#include "al/util.hpp"
#include "fl/tas.h"
#include "game/Layouts/MapLayout.h"
#include "rs/util.hpp"
#include "sead/math/seadVector.h"
#include <fl/server.h>
#include <fl/ui/ui.h>
#include <mem.h>
#include <nn/init.h>

void sequenceDrawHook(al::Sequence* sequence)
{
    bool shouldRender = fl::ui::PracticeUI::instance().shouldRender;
    if(shouldRender)
        sequence->drawMain();
}

void tasDrawKitHook(const al::Scene* scene, const char* kitName) {
    fl::TasHolder::instance().update();

    al::drawKit(scene, kitName);
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

void setGotShineVar(GameDataHolderWriter writer, const ShineInfo* shineInfo)
{
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    if (!ui.shineRefresh)
        writer.mGameDataFile->setGotShine(shineInfo);
}

int fgetPadAccelerationDeviceNum(int port)
{
    return fl::TasHolder::instance().isRunning ? 2 : al::getPadAccelerationDeviceNum(port);
}

bool isGotShineVar(GameDataHolderAccessor accessor, const ShineInfo* shineInfo)
{
    return fl::ui::PracticeUI::instance().gotShineRefresh ? false : accessor.mGameDataFile->isGotShine(shineInfo);
}

bool isEnableCheckpointWarpVar(MapLayout* layout)
{
    return fl::ui::PracticeUI::instance().alwaysWarp ? true : layout->isEnableCheckpointWarp();
}

bool isEnableSaveVar(StageScene* stageScene)
{
    return fl::ui::PracticeUI::instance().disableAutoSave ? false : stageScene->isEnableSave();
}

bool isDefeatKoopaLv1Var(StageScene* stageScene)
{
#if SMOVER == 100
    return fl::ui::PracticeUI::instance().skipBowser ? true : stageScene->isDefeatKoopaLv1();
#endif
#if SMOVER == 130
    static int functionCalls = 0;
    if (!fl::ui::PracticeUI::instance().skipBowser) {
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
    return fl::ui::PracticeUI::instance().isModeDiverOrJungleGymRom;
}

bool fisModeDiverRom()
{
    return fl::ui::PracticeUI::instance().isModeDiverRom;
}

bool fisModeJungleGymRom()
{
    return fl::ui::PracticeUI::instance().isModeJungleGymRom;
}

bool fisModeE3LiveRom()
{
    return fl::ui::PracticeUI::instance().isModeE3LiveRom;
}

bool fisModeE3MovieRom()
{
    return fl::ui::PracticeUI::instance().isModeE3MovieRom;
}

bool fisModeEpdMovieRom()
{
    return fl::ui::PracticeUI::instance().isModeEpdMovieRom;
}

#if SMOVER == 100
bool fisPadTriggerLMotion(int port)
{
    return fl::TasHolder::instance().isRunning ? false : al::isPadTriggerL(port);
}
#endif

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
