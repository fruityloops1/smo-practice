#pragma once

#include "debugMenu.hpp"
#include <game/Player/PlayerActorHakoniwa.h>
#include <game/StageScene/StageScene.h>
#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>

namespace fl
{

class PracticeUI
{
private:
    sead::Vector3f savedTrans;
    sead::Quatf savedQuat;
    bool saved = false;
    bool teleportEnabled = false;
    s8 reloadStageForPos = -1;
    sead::Vector3f reloadStagePos;
    sead::Quatf reloadStageQuat;
    StageScene* stageScene;

    bool inputEnabled = true;
    bool hideShineCounter = false;
    bool nextFrameNoLeftInput = false;
    bool nextFrameNoRightInput = false;

    #if(SMOVER==130)
    char textBuffer[4096];
    u32 printPos;
    #endif

    void savePosition(PlayerActorHakoniwa& player);
    void loadPosition(PlayerActorHakoniwa& player);
public:
    static inline PracticeUI& instance() {static PracticeUI ui; return ui;}
    void update(StageScene& stageScene);
    #if(SMOVER==100)
    void menu(sead::TextWriter& p);
    #endif
    #if(SMOVER==130)
    void menu();
    #endif

    inline StageScene* getStageScene() {return stageScene;}

    bool shineRefresh = false;
    bool gotShineRefresh = false;
    bool alwaysWarp = false;
    bool disableAutoSave = false;
    bool skipBowser = false;

    bool isModeDiverOrJungleGymRom = false;
    bool isModeDiverRom = false;
    bool isModeE3LiveRom = false;
    bool isModeE3MovieRom = false;
    bool isModeEpdMovieRom = false;
    bool isModeJungleGymRom = false;
};

}