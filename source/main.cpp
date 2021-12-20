#include "al/input/JoyPadAccelPoseAnalyzer.h"
#include "al/util.hpp"
#include "fl/input.h"
#include "fl/tas.h"
#include "game/Layouts/MapLayout.h"
#include "rs/util.hpp"
#include "sead/math/seadVector.h"
#include <fl/ui.h>
#include <fl/server.h>
#include <nn/init.h>
#include <mem.h>

void stageSceneControlHook() {
    __asm ("MOV X19, X0");

    StageScene* stageScene;
    __asm ("MOV %[result], X0" : [result] "=r" (stageScene));
    
    fl::PracticeUI::instance().update(*stageScene);

    __asm ("MOV X0, %[input]" : [input] "=r" (stageScene));
}

void setGotShineVar(GameDataHolderWriter writer, const ShineInfo* shineInfo)
{
    fl::PracticeUI& ui = fl::PracticeUI::instance();
    if (!ui.shineRefresh)
        writer.mGameDataFile->setGotShine(shineInfo);
}

int fgetPadAccelerationDeviceNum(int port)
{
    return fl::TasHolder::instance().isRunning ? 2 : al::getPadAccelerationDeviceNum(port);
}

bool isGotShineVar(GameDataHolderAccessor accessor, const ShineInfo* shineInfo)
{
    return fl::PracticeUI::instance().gotShineRefresh ? false : accessor.mGameDataFile->isGotShine(shineInfo);
}

bool isEnableCheckpointWarpVar(MapLayout* layout)
{
    return fl::PracticeUI::instance().alwaysWarp ? true : layout->isEnableCheckpointWarp();
}

bool isEnableSaveVar(StageScene* stageScene)
{
    return fl::PracticeUI::instance().disableAutoSave ? false : stageScene->isEnableSave();
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
    return fl::PracticeUI::instance().isModeDiverOrJungleGymRom;
}

bool fisModeDiverRom()
{
    return fl::PracticeUI::instance().isModeDiverRom;
}

bool fisModeJungleGymRom()
{
    return fl::PracticeUI::instance().isModeJungleGymRom;
}

bool fisModeE3LiveRom()
{
    return fl::PracticeUI::instance().isModeE3LiveRom;
}

bool fisModeE3MovieRom()
{
    return fl::PracticeUI::instance().isModeE3MovieRom;
}

bool fisModeEpdMovieRom()
{
    return fl::PracticeUI::instance().isModeEpdMovieRom;
}

#if SMOVER==100
bool fisPadTriggerLMotion(int port)
{
    return fl::TasHolder::instance().isRunning ? false : al::isPadTriggerL(port);
}
#endif

void motionUpdate(al::JoyPadAccelPoseAnalyzer* dis)
{
    if (!fl::TasHolder::instance().isRunning) {dis->update(); return;}
    fl::TasHolder& h = fl::TasHolder::instance();
    int controllerPort;
    if (dis->mControllerPort < 0)
        controllerPort = al::getMainControllerPort();
    else controllerPort = al::getPlayerControllerPort(dis->mControllerPort);
    dis->mAccelDeviceNum = al::getPadAccelerationDeviceNum(controllerPort);

    if (fisPadTriggerL(controllerPort))
    {
        if (h.oldMotion)
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerUp(controllerPort))
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerDown(controllerPort))
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, -1.0f};
            dis->mAccelRightVel = {0.0f, -1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerLeft(controllerPort))
        {
            dis->mSwingRight = false;
            dis->mSwingLeft = true;
            dis->mSwingAny = true;
            dis->mAccelLeftAccel = {-1.0f, 0.0f};
            dis->mAccelLeftVel = {-1.0f, 0.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
        }
        else if (fisPadTriggerRight(controllerPort))
        {
            dis->mSwingRight = true;
            dis->mSwingLeft = false;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {1.0f, 0.0f};
            dis->mAccelRightVel = {1.0f, 0.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
    }
    else
    {
        if (fisPadTriggerUp(controllerPort))
        {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = {0.0f, 1.0f};
            dis->mAccelLeftAccel = {0.0f, 1.0f};
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelLeftVel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerLeft(controllerPort))
        {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = {-1.0f, 0.0f};
            dis->mAccelLeftAccel = {-1.0f, 0.0f};
            dis->mAccelRightAccel = {-1.0f, 0.0f};
            dis->mAccelLeftVel = {-1.0f, 0.0f};
            dis->mAccelRightVel = {-1.0f, 0.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerRight(controllerPort))
        {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = {1.0f, 0.0f};
            dis->mAccelLeftAccel = {1.0f, 0.0f};
            dis->mAccelRightAccel = {1.0f, 0.0f};
            dis->mAccelLeftVel = {1.0f, 0.0f};
            dis->mAccelRightVel = {1.0f, 0.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerDown(controllerPort))
        {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = {0.0f, -1.0f};
            dis->mAccelLeftAccel = {0.0f, -1.0f};
            dis->mAccelRightAccel = {0.0f, -1.0f};
            dis->mAccelLeftVel = {0.0f, -1.0f};
            dis->mAccelRightVel = {0.0f, -1.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = false;
            dis->mSwingAny = false;
            dis->mAccelCombinedVel = {0.0f, 0.0f};
            dis->mAccelLeftAccel = {0.0f, 0.0f};
            dis->mAccelRightAccel = {0.0f, 0.0f};
            dis->mAccelLeftVel = {0.0f, 0.0f};
            dis->mAccelRightVel = {0.0f, 0.0f};
            dis->mHistoryLeft.hist0 = 0.0f;
            dis->mHistoryRight.hist0 = 0.0f;
            dis->mHistoryLeft.hist1 = 0.0f;
            dis->mHistoryRight.hist1 = 0.0f;
        }
    }
}