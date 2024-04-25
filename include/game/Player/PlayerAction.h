#pragma once

#include <sead/math/seadVector.h>
#include "al/LiveActor/LiveActor.h"
#include "game/Player/PlayerConst.h"
#include "game/Player/PlayerInput.h"
#include "game/Interfaces/IUsePlayerCollision.h"
#include "game/Interfaces/IUsePlayerHack.h"

class PlayerActionDiveInWater;
class PlayerActionTurnControl;

class PlayerActionAirMoveControl {
public:
    al::LiveActor* mActor;
    PlayerConst* mPlayerConst;
    PlayerInput* mPlayerInput;
    IUsePlayerCollision* mCollider;
    IUsePlayerHack* mHackKeeper;
    PlayerActionTurnControl* mActionTurnControl;
    bool bVar1;
    bool bVar2;
    bool bVar3;
    bool bVar4;
    int mExtendFrame;
    int iVar1;
    int iVar2;
    bool bVar5;
    bool bVar6;
    bool bVar7;
    float fVar1;
    float fVar2;
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    float fVar3;
    float fVar4;
    float mFallSpeedMax;
    bool bVar8;
    sead::Vector3f vVar3;
    float fVar5;
    sead::Vector3f vVar4;
};

class PlayerActionGroundMoveControl;
class PlayerActionCollisionSnap;
