#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/actor/Placement.h"
#include "al/nerve/NerveStateBase.h"
#include "al/sensor/HitSensor.h"
#include "game/RouteGuide/RouteGuidePoint.h"

#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>

namespace al {
class CollisionPartsConnector;
class FlashingCtrl;
}
class SaveObjInfo;
class PlayerHoldObjTutorialController;
class MapObjStatePlayerHold;
class GrowSeedStateRevival;

class GrowSeedStateWait : public al::ActorStateBase {
public:
    class Param {
    public:
        float fVar1;
        float fVar2;
        float fVar3;
        float fVar4;
        float fVar5;
    };

    al::CollisionPartsConnector* mCollisionPartsConnector;
    sead::Vector3f vVar1;
    al::FlashingCtrl* mFlashingCtrl;
    GrowSeedStateWait::Param* mParam;
    sead::Quatf* qVar1;
    int iVar1;
    al::HitSensor* mSensor;
    bool bVar1;
    bool bVar2;
    bool bVar3;
    sead::Vector3f vVar2;
};

class GrowPlantSeed : public al::LiveActor, public RouteGuidePoint {
public:
    al::PlacementId* mPlacementId;
    SaveObjInfo* mSaveObjInfo;
    unsigned char gap1[0x30];
    MapObjStatePlayerHold* mStatePlayerHold;
    GrowSeedStateWait* mStateWait;
    GrowSeedStateWait* mStateWaitWater;
    GrowSeedStateRevival* mStateRevival;
    sead::Quatf qVar1;
    int iVar1;
    int iVar2;
    bool mIsSave;
    bool bVar1;
    bool bVar2;
    sead::Vector3f vVar1;
    int iVar3;
    bool bVar3;
    bool bVar4;
    bool bVar5;
    int iVar4;
    bool bVar6;
    PlayerHoldObjTutorialController* mHoldObjTutorialController;
    bool bVar7;
};
