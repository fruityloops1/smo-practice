#pragma once
#include "al/scene/Scene.h"
#include "al/scene/SceneObjHolder.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "sead/math/seadVector.h"
#include <fl/efun.h>

namespace al {
class LiveActor;
class SensorMsg;
}

namespace rs {
uint32_t getStageShineAnimFrame(const al::LiveActor*, const char*);

#if (SMOVER == 100)
PlayerActorHakoniwa* getPlayerActor(const al::Scene*);
bool isTriggerSnapShotMode(al::IUseSceneObjHolder const*);
bool isTriggerAmiiboMode(al::IUseSceneObjHolder const*);
#endif
#if (SMOVER == 130)
EFUN(0x00479670, PlayerActorHakoniwa*, getPlayerActor, EFUN_ARGS(const al::Scene*));
EFUN(0x0051ED30, bool, isTriggerSnapShotMode, EFUN_ARGS(const al::IUseSceneObjHolder*));
EFUN(0x0051EDB0, bool, isTriggerAmiiboMode, EFUN_ARGS(const al::IUseSceneObjHolder*));
#endif

bool isInChangeStageArea(al::LiveActor const*, sead::Vector3f const*);

bool isInvalidChangeStage(al::LiveActor const*);

bool isMsgCapTouchWall(al::SensorMsg const*);

void buyCap(al::IUseSceneObjHolder const*, char const*);

int getActiveQuestNum(al::IUseSceneObjHolder const*);
int getActiveQuestNo(al::IUseSceneObjHolder const*);
const char* getActiveQuestLabel(al::IUseSceneObjHolder const*);
void requestShowHtmlViewer(al::IUseSceneObjHolder const*);

#if (SMOVER == 100)
int getPlayerJumpCount(GameDataHolder const*);
int getPlayerThrowCapCount(GameDataHolder const*);
int getTotalCoinNum(GameDataHolder const*);
#endif
#if (SMOVER == 130)
EFUN(0x004ED610, int, getPlayerJumpCount, EFUN_ARGS(const GameDataHolder*));
EFUN(0x004ED640, int, getPlayerThrowCapCount, EFUN_ARGS(const GameDataHolder*));
EFUN(0x004ED410, int, getTotalCoinNum, EFUN_ARGS(const GameDataHolder*));
#endif

}