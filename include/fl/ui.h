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

    void savePosition(PlayerActorHakoniwa& player);
    void loadPosition(PlayerActorHakoniwa& player);
public:
    static inline PracticeUI& instance() {static PracticeUI ui; return ui;}
    void update(StageScene& stageScene);
    void print(sead::TextWriter& p);

    bool shineRefresh = false;
    bool gotShineRefresh = false;
    bool alwaysWarp = false;
    bool disableAutoSave = false;
};

}