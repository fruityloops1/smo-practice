#include "al/util.hpp"
#include "game/Layouts/MapLayout.h"
#include "rs/util.hpp"
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
    return showMenu ? false : rs::isTriggerSnapShotMode(objHolder);
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