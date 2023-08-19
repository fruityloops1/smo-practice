#pragma once
/**
 * @file PlayerActorBase.h
 * @brief Main Class for the PlayerActor (Mario)
 * Player Pose: TQGMSV
*  Vtable loc: 1D780C0
*/

#include "PlayerActorBase.h"
#include "game/Interfaces/IUseDimension.h"
#include "PlayerInput.h"
#include "PlayerAnimator.h"
#include "HackCap.h"
#include "PlayerModelKeeper.h"
#include "PlayerRecoverySafetyPoint.h"
#include "game/Player/PlayerDamageKeeper.h"
#include "game/Player/PlayerHackKeeper.h"

#include <fl/efun.h>

#define PACTORSIZE 0xC8

namespace al {
    class WaterSurfaceFinder;
    class FootPrintHolder;
}

class PlayerStainControl;
class PlayerColliderHakoniwa;
class PlayerInfo;
class PlayerConst;

class PlayerTrigger;
        class HackCap;
        class ActorDimensionKeeper;
        class PlayerModelKeeper;
        class PlayerModelChangerHakoniwa;
        class PlayerAnimator;
        class PlayerColliderHakoniwa;
        class PlayerPuppet;
        class PlayerAreaChecker;
        class PlayerDamageKeeper;
        class PlayerDemoActionFlag;
        class PlayerCapActionHistory;
        class PlayerCapManHeroEyesControl;
        class PlayerContinuousJump;
        class PlayerContinuousLongJump;
        class PlayerCounterAfterUpperPunch;
        class PlayerCounterForceRun;
        class PlayerCounterIceWater;
        class PlayerCounterQuickTurnJump;
        class PlayerWallActionHistory;
        class PlayerBindKeeper;
        class PlayerCarryKeeper;
        class PlayerEquipmentUser;
        class PlayerHackKeeper;
        class PlayerFormSensorCollisionArranger;
        class PlayerJumpMessageRequest;
        class PlayerSandSinkAffect;
        class PlayerSpinCapAttack;
        class PlayerActionDiveInWater;
        class PlayerEffect;
        class PlayerEyeSensorHitHolder;
        class PlayerPushReceiver;
        class PlayerHitPush;
        class PlayerJointControlKeeper;
        class PlayerPainPartsKeeper;
        class PlayerRecoverySafetyPoint;
        class PlayerRippleGenerator;
        class PlayerSeparateCapFlag;
        class PlayerWetControl;
        class PlayerStainControl;
        class GaugeAir;
        class WaterSurfaceShadow;
        class WorldEndBorderKeeper;
        class PlayerSeCtrl;
        class PlayerStateWait;
        class PlayerStateSquat;
        class PlayerStateRunHakoniwa2D3D;
        class PlayerStateSlope;
        class PlayerStateRolling;
        class PlayerStateSpinCap;
        class PlayerStateJump;
        class PlayerStateCapCatchPop;
        class PlayerStateWallAir;
        class PlayerStateGrabCeil;
        class PlayerStatePoleClimb;
        class PlayerStateHipDrop;
        class PlayerStateHeadSliding;
        class PlayerStateLongJump;
        class PlayerStateFallHakoniwa;
        class PlayerStateSandSink;
        class ActorStateSandGeyser;
        class PlayerStateRise;
        class PlayerStateSwim;
        class PlayerStateDamageLife;
        class PlayerStateDamageSwim;
        class PlayerStateDamageFire;
        class PlayerStatePress;
        class PlayerStateBind;
        class PlayerStateHack;
        class PlayerStateEndHack;
        class PlayerStateCameraSubjective;
        class PlayerStateAbyss;
        class PlayerJudgeAirForceCount;
        class PlayerJudgeCameraSubjective;
        class PlayerJudgeCapCatchPop;
        class PlayerJudgeDeadWipeStart;
        class PlayerJudgeDirectRolling;
        class PlayerJudgeForceLand;
        class PlayerJudgeForceSlopeSlide;
        class PlayerJudgeForceRolling;
        class PlayerJudgeGrabCeil;
        class PlayerJudgeInWater;
        class PlayerJudgeInWater;
        class PlayerJudgeInWater;
        class PlayerJudgeInWater;
        class PlayerJudgeInvalidateInputFall;
        class PlayerJudgeLongFall;
        class PlayerJudgeOutInWater;
        class PlayerJudgeRecoveryLifeFast;
        class PlayerJudgeSandSink;
        class PlayerJudgeSpeedCheckFall;
        class PlayerJudgeStartHipDrop;
        class PlayerJudgeStartRise;
        class PlayerJudgeStartRolling;
        class PlayerJudgeStartRun;
        class PlayerJudgeStartSquat;
        class PlayerJudgeStartWaterSurfaceRun;
        class PlayerJudgeSlopeSlide;
        class PlayerJudgePoleClimb;
        class PlayerJudgePreInputJump;
        class PlayerJudgePreInputCapThrow;
        class PlayerJudgePreInputHackAction;
        class HackCapJudgePreInputHoveringJump;
        class HackCapJudgePreInputSeparateThrow;
        class HackCapJudgePreInputSeparateJump;
        class PlayerJudgeWallCatch;
        class PlayerJudgeWallCatchInputDir;
        class PlayerJudgeWallHitDown;
        class PlayerJudgeWallHitDownForceRun;
        class PlayerJudgeWallHitDownRolling;
        class PlayerJudgeWallKeep;

class PlayerActorHakoniwa : public PlayerActorBase , public IUseDimension {
    public: 
        int *getPortNo(void) const;
        void startDemoMainShineGet();
        void endDemoMainShineGet();
        #if(SMOVER==100)
        void startDemoPuppetable();
        void endDemoPuppetable();
        #endif
        #if(SMOVER==130)
        VVCEFUN(PlayerActorHakoniwa, 0x003C4840, startDemoPuppetable);
        VVCEFUN(PlayerActorHakoniwa, 0x003C4AA0, endDemoPuppetable);
        #endif
        void startDemoShineGet();
        void tryActionStartSpinAttack();
        unsigned char padding_E8[0xE8 - PACTORSIZE];
        int portNo; // 0xE8
        unsigned char padding_138[0x38];
        PlayerInfo* mPlayerInfo;
        PlayerConst* mPlayerConst;
        PlayerInput *mPlayerInput; //0x138 
        PlayerTrigger* mPlayerTrigger;
        HackCap* mHackCap;
        ActorDimensionKeeper* mActorDimensionKeeper;
        PlayerModelKeeper* mModelKeeper;
        PlayerModelChangerHakoniwa* mModelChangerHakoniwa;
        PlayerAnimator* mAnimator;
        PlayerColliderHakoniwa* mColliderHakoniwa;
        PlayerPuppet* mPuppet;
        PlayerAreaChecker* mAreaChecker;
        al::WaterSurfaceFinder* mWaterSurfaceFinder;
        void* gap1;
        PlayerDamageKeeper* mDamageKeeper;
        PlayerDemoActionFlag* mDemoActionFlag;
        PlayerCapActionHistory* mCapActionHistory;
        PlayerCapManHeroEyesControl* mCapManHeroEyesControl;
        PlayerContinuousJump* mContinuousJump;
        PlayerContinuousLongJump* mContinuousLongJump;
        PlayerCounterAfterUpperPunch* mCounterAfterUpperPunch;
        PlayerCounterForceRun* mCounterForceRun;
        PlayerCounterIceWater* mCounterIceWater;
        PlayerCounterQuickTurnJump* mCounterQuickTurnJump;
        PlayerWallActionHistory* mWallActionHistory;
        PlayerBindKeeper* mBindKeeper;
        PlayerCarryKeeper* mCarryKeeper;
        PlayerEquipmentUser* mEquipmentUser;
        PlayerHackKeeper* mHackKeeper;
        PlayerFormSensorCollisionArranger* mFormSensorCollisionArranger;
        PlayerJumpMessageRequest* mJumpMessageRequest;
        PlayerSandSinkAffect* mSandSinkAffect;
        PlayerSpinCapAttack* mSpinCapAttack;
        PlayerActionDiveInWater* mActionDiveInWater;
        PlayerEffect* mPlayerEffect;
        PlayerEyeSensorHitHolder* mEyeSensorHitHolder;
        PlayerPushReceiver* mPushReceiver;
        PlayerHitPush* mHitPush;
        void* gap2;
        PlayerJointControlKeeper* mJointControlKeeper;
        PlayerPainPartsKeeper* mPainPartsKeeper;
        PlayerRecoverySafetyPoint* mRecoverPoint;
        PlayerRippleGenerator* mRippleGenerator;
        PlayerSeparateCapFlag* mSeparateCapFlag;
        PlayerWetControl* mWetControl;
        PlayerStainControl* mStainControl;
        al::FootPrintHolder* mFootPrintHolder;
        GaugeAir* mGaugeAir;
        WaterSurfaceShadow* mWaterSurfaceShadow;
        WorldEndBorderKeeper* mWorldEndBorderKeeper;
        void* gap3;
        PlayerSeCtrl* mSeCtrl;
        al::HitSensor* mHitSensorBody;
        bool* mIsLongShadow;
        PlayerStateWait* mStateWait;
        PlayerStateSquat* mStateSquat;
        PlayerStateRunHakoniwa2D3D* mStateRunHakoniwa2D3D;
        PlayerStateSlope* mStateSlope;
        PlayerStateRolling* mStateRolling;
        PlayerStateSpinCap* mStateSpinCap;
        PlayerStateJump* mStateJump;
        PlayerStateCapCatchPop* mStateCapCatchPop;
        PlayerStateWallAir* mStateWallAir;
        void* gap4;
        PlayerStateGrabCeil* mStateGrabCeil;
        PlayerStatePoleClimb* mStatePoleClimb;
        PlayerStateHipDrop* mStateHipDrop;
        PlayerStateHeadSliding* mStateHeadSliding;
        PlayerStateLongJump* mStateLongJump;
        PlayerStateFallHakoniwa* mStateFallHakoniwa;
        PlayerStateSandSink* mStateSandSink;
        ActorStateSandGeyser* mStateSandGeyser;
        PlayerStateRise* mStateRise;
        PlayerStateSwim* mStateSwim;
        PlayerStateDamageLife* mStateDamageLife;
        PlayerStateDamageSwim* mStateDamageSwim;
        PlayerStateDamageFire* mStateDamageFire;
        PlayerStatePress* mStatePress;
        PlayerStateBind* mStateBind;
        PlayerStateHack* mStateHack;
        PlayerStateEndHack* mStateEndHack;
        PlayerStateCameraSubjective* mStateCameraSubjective;
        PlayerStateAbyss* mStateAbyss;
        PlayerJudgeAirForceCount* mJudgeAirForceCount;
        PlayerJudgeCameraSubjective* mJudgeCameraSubjective;
        PlayerJudgeCapCatchPop* mJudgeCapCatchPop;
        PlayerJudgeDeadWipeStart* mJudgeDeadWipeStart;
        PlayerJudgeDirectRolling* mJudgeDirectRolling;
        void* gap5;
        PlayerJudgeForceLand* mJudgeForceLand;
        PlayerJudgeForceSlopeSlide* mJudgeForceSlopeSlide;
        PlayerJudgeForceRolling* mJudgeForceRolling;
        PlayerJudgeGrabCeil* mJudgeGrabCeil;
        PlayerJudgeInWater* mJudgeInWater1;
        PlayerJudgeInWater* mJudgeInWater2;
        PlayerJudgeInWater* mJudgeInWater3;
        PlayerJudgeInWater* mJudgeInWater4;
        PlayerJudgeInvalidateInputFall* mJudgeInvalidateInputFall;
        PlayerJudgeLongFall* mJudgeLongFall;
        PlayerJudgeOutInWater* mJudgeOutInWater;
        PlayerJudgeRecoveryLifeFast* mJudgeRecoveryLifeFast;
        PlayerJudgeSandSink* mJudgeSandSink;
        PlayerJudgeSpeedCheckFall* mJudgeSpeedCheckFall;
        PlayerJudgeStartHipDrop* mJudgeStartHipDrop;
        PlayerJudgeStartRise* mJudgeStartRise;
        PlayerJudgeStartRolling* mJudgeStartRolling;
        PlayerJudgeStartRun* mJudgeStartRun;
        PlayerJudgeStartSquat* mJudgeStartSquat;
        PlayerJudgeStartWaterSurfaceRun* mJudgeStartWaterSurfaceRun;
        PlayerJudgeSlopeSlide* mJudgeSlopeSlide;
        PlayerJudgePoleClimb* mJudgePoleClimb;
        PlayerJudgePreInputJump* mJudgePreInputJump;
        PlayerJudgePreInputCapThrow* mJudgePreInputCapThrow;
        PlayerJudgePreInputHackAction* mJudgePreInputHackAction;
        HackCapJudgePreInputHoveringJump* mHackCapJudgePreInputHoveringJump;
        HackCapJudgePreInputSeparateThrow* mHackCapJudgePreInputSeparateThrow;
        HackCapJudgePreInputSeparateJump* mHackCapJudgePreInputSeparateJump;
        PlayerJudgeWallCatch* mJudgeWallCatch;
        PlayerJudgeWallCatchInputDir* mJudgeWallCatchInputDir;
        PlayerJudgeWallHitDown* mJudgeWallHitDown;
        PlayerJudgeWallHitDownForceRun* mJudgeWallHitDownForceRun;
        PlayerJudgeWallHitDownRolling* mJudgeWallHitDownRolling;
        PlayerJudgeWallKeep* mJudgeWallKeep;
};
