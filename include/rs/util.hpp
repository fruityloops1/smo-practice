#pragma once
#include "al/scene/Scene.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "sead/math/seadVector.h"
#include "al/scene/SceneObjHolder.h"

namespace al
{
    class LiveActor;
    class SensorMsg;
}

namespace rs
{
    uint32_t getStageShineAnimFrame(const al::LiveActor *, const char *);

    PlayerActorHakoniwa* getPlayerActor(const al::Scene *);

    bool isInChangeStageArea(al::LiveActor const*, sead::Vector3f const *);

    bool isInvalidChangeStage(al::LiveActor const *);

    bool isMsgCapTouchWall(al::SensorMsg const *);

    void buyCap(al::IUseSceneObjHolder const *, char const*);

    int getActiveQuestNum(al::IUseSceneObjHolder const *);
    int getActiveQuestNo(al::IUseSceneObjHolder const *);
    const char *getActiveQuestLabel(al::IUseSceneObjHolder const *);
    void requestShowHtmlViewer(al::IUseSceneObjHolder const *);

    bool isTriggerSnapShotMode(al::IUseSceneObjHolder const*);
    bool isTriggerAmiiboMode(al::IUseSceneObjHolder const*);

}
