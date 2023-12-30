#pragma once

#include "al/actor/WaterSurfaceFinder.h"
#include "al/nerve/NerveStateBase.h"
#include "al/sensor/HitSensor.h"
#include "game/Interfaces/IUseDimension.h"
#include "game/Player/PlayerAction.h"
#include "game/Player/PlayerAnimator.h"
#include "game/Player/PlayerConst.h"
#include "game/Player/PlayerInput.h"
#include "game/Player/PlayerJudge.h"
#include "game/Player/PlayerTrigger.h"
#include "game/Player/PlayerWallActionHistory.h"
#include <sead/math/seadVector.h>

class IUsePlayerCeilingCheck;
class IUsePlayerCollision;
class PlayerSpinCapAttack;
class PlayerJointControlKeeper;;
class PlayerJointParamCapThrow;
class PlayerJointParamGrab;
class PlayerJointParamHandLegAngle;
class PlayerModelHolder;
class PlayerContinuousJump;
class HackCap;
class HackCapJudgeHoldHoveringJump;

class PlayerStateAbyss;
class PlayerStateAutoDash;
class PlayerStateBind;
class PlayerStateCameraSubjective;
class PlayerStateCapCatchPop;
class PlayerStateCeilingKeep;
class PlayerStateDamageFire;

class PlayerStateDamageLife : public al::ActorStateBase {
public:
    PlayerConst* mPlayerConst;
    IUsePlayerCollision* mPlayerCollider;
    IUsePlayerCeilingCheck* mCeilingCheck;

};

class PlayerStateDamageSwim;
class PlayerStateEndHack;
class PlayerStateFallHakoniwa;
class PlayerStateFreeRun;

class PlayerStateGrabCeil : public al::ActorStateBase {
public:
    PlayerConst* mPlayerConst;
    PlayerInput* mPlayerInput;
    PlayerModelHolder* mModelHolder;
    PlayerTrigger* mPlayerTrigger;
    IUsePlayerCollision* mCollider;
    PlayerAnimator* mAnimator;
    PlayerJudgePreInputJump* mJudgePreInputJump;
    al::HitSensor* mSensor;
    PlayerJointParamGrab* mJointParamGrab;
    PlayerActionAirMoveControl* mActionAirMoveControl;
    PlayerActionCollisionSnap* mActionCollisionSnap;
    bool bVar1;
    bool bVar2;
    int iVar1;
    bool bVar3;
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    int iVar2;
    float fVar5;
    int iVar3;
    float fVar6;
    int iVar4;
    float fVar7;
};

class PlayerStateGroundSpin;
class PlayerStateHack;
class PlayerStateHeadSliding;
class PlayerStateHipDrop;

class PlayerStateJump : public al::ActorStateBase {
public:
    PlayerConst* mPlayerConst;
    IPlayerModelChanger* mModelChanger;
    IUseDimension* mDimensionKeeper;
    PlayerJumpMessageRequest* mJumpMessageRequest;
    PlayerJudgeCapCatch* mJudgeCapCatch;
    PlayerCounterForceRun* mCounterForceRun;
    PlayerJointControlKeeper* mJointControlKeeper;
    IUsePlayerCollision* mCollider;
    PlayerAnimator* mAnimator;
    PlayerContinuousJump* mContinuousJump;
    PlayerTrigger* mPlayerTrigger;
    PlayerActionDiveInWater* mActionDiveInWater;
    PlayerActionAirMoveControl* mActionAirMoveControl;
    HackCap* mHackCap;
    HackCapJudgeHoldHoveringJump* mHackCapJudgeHoldHoveringJump;
    bool bVar1;
    int mExtendFrame;
    float mJumpPower;
    float mJumpMoveSpeedMax;
    float mGravity;
    int iVar1;
    unsigned int mContinuousJumpCount;
    bool bVar2;
    bool bVar3;
    bool bVar4;
    bool bVar5;
    bool bVar6;
    bool bVar7;
    bool mIsHoldCapSeparateJump;
    sead::Vector3f vVar1;
    const char* mJumpName;
    const char* sVar1;
    PlayerInput* mPlayerInput;
    sead::Vector3f vVar2;
    int iVar2;
    bool bVar8;


};

class PlayerStateJump2D3D;
class PlayerStateLongJump;
class PlayerStateNormalFall;
class PlayerStateNormalJump;
class PlayerStateNormalWait;

class PlayerStateNormalWallJump : public al::ActorStateBase {
public:
    void appear(void);
    void exeJump(void);

    PlayerConst* mPlayerConst;
    IUsePlayerCollision* mPlayerCollider;
    PlayerInput* mPlayerInput;
    PlayerTrigger* mPlayerTrigger;
    PlayerAnimator* mPlayerAnimator;
    PlayerActionDiveInWater* mDiveInWater;
    PlayerActionAirMoveControl* mAirMoveControl;
    const char* mName;  // value = "WallJump"
    sead::Vector3f mPos;
    bool gap1;  // value = false
};

class PlayerStateNormalWallSlide;

class PlayerStatePoleClimb : public al::ActorStateBase {
private:
    enum ClimbType {
        Climb, ClimbFast, ClimbSwing
    };

public:
    PlayerConst* mPlayerConst;
    PlayerInput* mPlayerInput;
    PlayerModelHolder* mModelHolder;
    IUsePlayerCollision* mCollider;
    PlayerAnimator* mAnimator;
    PlayerJointParamHandLegAngle* mJointParamHandLegAngle;
    PlayerJudgePreInputJump* mJudgePreInputJump;
    PlayerStateNormalWallJump* mStateNormalWallJump1;
    PlayerStateNormalWallJump* mStateNormalWallJump2;
    PlayerWallActionHistory* mWallActionHistory;
    PlayerActionCollisionSnap* mActionCollisionSnap;
    PlayerJudgePreInputPoleClimbSwing* mJudgePreInputPoleClimbSwing;
    char* mMaterialName;
    float fVar1;
    float fVar2;
    float fVar3;
    ClimbType mClimbType;
    int mClimbDelay;
    sead::Vector2f mPoleMoveInput;
    bool mHasJustTurned;
    bool mIsInputReverse;
    sead::Vector2f mStickMoveRaw;
    int mClimbDownKeepTime;
    bool bVar3;
    sead::Vector2f mLeftStickInit;
};

class PlayerStatePress;
class PlayerStateRecoveryDead;
class PlayerStateRise;
class PlayerStateRolling;
class PlayerStateRun;
class PlayerStateRun2D;
class PlayerStateRun2D3D;
class PlayerStateRunHakoniwa;
class PlayerStateRunHakoniwa2D3D;
class PlayerStateSandSink;
class PlayerStateSlope;

class PlayerStateSpinCap : public al::ActorStateBase {
public:
    PlayerConst* mPlayerConst;
    PlayerInput* mPlayerInput;
    PlayerCounterForceRun* mPlayerCounterForceRun;
    al::WaterSurfaceFinder* mWaterSurfaceFinder;
    IUsePlayerCollision* mPlayerCollider;
    PlayerTrigger* mPlayerTrigger;
    PlayerSpinCapAttack* mPlayerSpinCapAttack;
    PlayerAnimator* mPlayerAnimator;
    PlayerJointParamCapThrow* mPlayerJointParamCapThrow;
    PlayerActionAirMoveControl* mPlayerActionAirMoveControl;
    PlayerActionGroundMoveControl* mPlayerActionGroundMoveControl;
    bool bVar1;
    PlayerJudgeWaterSurfaceRun* mPlayerJudgeWaterSurfaceRun;
    bool bVar2;
    bool bVar3;
    int iVar1;
    int iVar2;
};

class PlayerStateSquat;
class PlayerStateSwim;
class PlayerStateSwordAttack;
class PlayerStateTargetJump;
class PlayerStateTouchMove;
class PlayerStateWait;
class PlayerStateWallAir;
class PlayerStateWallCatch;
