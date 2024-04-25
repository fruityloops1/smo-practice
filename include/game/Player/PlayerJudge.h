#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/actor/WaterSurfaceFinder.h"
#include "game/Interfaces/IJudge.h"
#include "game/Player/PlayerCollider.h"
#include "game/Player/PlayerConst.h"
#include "game/Player/PlayerCounter.h"
#include "game/Player/PlayerExternalVelocity.h"
#include "game/Player/PlayerInput.h"
#include "game/Player/PlayerTrigger.h"
#include <sead/math/seadVector.h>

class IPlayerModelChanger;
class PlayerCarryKeeper;
class PlayerAreaChecker;

class PlayerJudgeAbyssDeadStatus;
class PlayerJudgeActiveCameraSubjective;
class PlayerJudgeAirForceCount;
class PlayerJudgeCameraInWater;
class PlayerJudgeCameraSubjective;
class PlayerJudgeCapCatch;
class PlayerJudgeCapCatchPop;
class PlayerJudgeCollideWall;
class PlayerJudgeDead;
class PlayerJudgeDeadSceneEnd;
class PlayerJudgeDeadWipeStart;
class PlayerJudgeDirectRolling;
class PlayerJudgeDiveInWater;
class PlayerJudgeDrawForward;
class PlayerJudgeEnableGuideArrow;
class PlayerJudgeEnablePeachAmiibo;
class PlayerJudgeEnableStandUp;
class PlayerJudgeFailureCameraSubjective;
class PlayerJudgeForceRolling;
class PlayerJudgeForceSlopeSlide;
class PlayerJudgeGrabCeil;
class PlayerJudgeInvalidateInputFall;

class PlayerJudgeInWater : public IJudge {
public:
    al::LiveActor* mActor;
    PlayerConst* mPlayerConst;
    IUsePlayerCollision* mCollider;
    PlayerAreaChecker* mAreaChecker;
    al::WaterSurfaceFinder* mWaterSurfaceFinder;
    IUsePlayerHeightCheck* mHeightCheck;
    PlayerCounterForceRun* mCounterForceRun;
    bool bVar1;
    bool bVar2;
    bool bVar3;
};

class PlayerJudgeIsNerve;
class PlayerJudgeNormalFall;
class PlayerJudgeOr;
class PlayerJudgeOutInWater;
class PlayerJudgePlaySwitchOnAreaWaitAnim;

class PlayerJudgePoleClimb : public IJudge {
public:
    al::LiveActor* mActor;
    PlayerConst* mPlayerConst;
    IUsePlayerCollision* mCollider;
    IPlayerModelChanger* mModelChanger;
    PlayerCarryKeeper* mCarryKeeper;
    PlayerExternalVelocity* mExternalVelocity;
    PlayerInput* mPlayerInput;
    PlayerTrigger* mPlayerTrigger;
    bool mIsClimbing;
    al::CollisionParts* uVar1;
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    sead::Vector3f vVar3;
    float fVar1;
    float fVar2;
    char* mMaterialName;
};

class PlayerJudgePreInputCapThrow;
class PlayerJudgePreInputHackAction;
class PlayerJudgePreInputJump;

class PlayerJudgePreInputPoleClimbSwing : public IJudge {
public:
    PlayerConst* mPlayerConst;
    PlayerInput* mPlayerInput;
    int mSwingDelay;
};

class PlayerJudgeRecoveryLifeFast;
class PlayerJudgeReduceOxygen;
class PlayerJudgeSafetyPointRecovery;
class PlayerJudgeSameNerve;
class PlayerJudgeSandSink;
class PlayerJudgeSleep;
class PlayerJudgeSlopeSlide;
class PlayerJudgeSlopeSlideRun;
class PlayerJudgeSpeedCheckFall;
class PlayerJudgeStartDash;
class PlayerJudgeStartGroundSpin;
class PlayerJudgeStartHipDrop;
class PlayerJudgeStartJumpHakoniwa;
class PlayerJudgeStartRise;
class PlayerJudgeStartRolling;
class PlayerJudgeStartRun;
class PlayerJudgeStartRunOld;
class PlayerJudgeStartSquat;
class PlayerJudgeStartSwimJump;
class PlayerJudgeStartWaterSurfaceRun;
class PlayerJudgeStatusPoleClimb;
class PlayerJudgeTalkGround;
class PlayerJudgeTalkSwim;
class PlayerJudgeTouchMove;
class PlayerJudgeWallHitDown;
class PlayerJudgeWallHitDownForceRun;
class PlayerJudgeWallHitDownRolling;
class PlayerJudgeWallPush;
class PlayerJudgeWaterSurfaceRun;

class PlayerJudgeForceLand : public IJudge {};

class PlayerJudgeLongFall : public IJudge {};

class PlayerJudgeWallKeep : public IJudge {
public:
    unsigned char padding[0x58];
    bool bVar1;
};

class PlayerJudgeWallCatch : public IJudge {
public:
    al::LiveActor* mActor;
    PlayerConst* mPlayerConst;
    IUsePlayerCollision* mCollider;
    IPlayerModelChanger* mModelChanger;
    PlayerCarryKeeper* mCarryKeeper;
    PlayerExternalVelocity* mExternalVelocity;
    PlayerInput* mPlayerInput;
    PlayerTrigger* mPlayerTrigger;
    PlayerCounterForceRun* mCounterForceRun;
    bool bVar1;
    unsigned char padding1[0xf];
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    sead::Vector3f vVar3;
};

class PlayerJudgeWallCatchInputDir : public IJudge {

};
