#pragma once
/**
 * @file HackCap.h
 * @brief Main Class for HackCap (Cappy)
* Vtable loc: 1D75520
*/

#include "al/LiveActor/LiveActor.h"

namespace al {
class PadRumbleKeeper;
class WaterSurfaceFinder;
class ActorDitherAnimator;
}
class IUsePlayerCollision;
class PlayerAreaChecker;
class PlayerSeparateCapFlag;
class IUsePlayerHeightCheck;
class PlayerWetControl;
class PlayerJointControlKeeper;
class PlayerColliderHackCap;
class HackCapTrigger;
class HackCapAboveGroundChecker;
class HackCapThrowParam;
class CapTargetInfo;
class PlayerEyeSensorHitHolder;
class HackCapJointControlKeeper;
class PlayerWallActionHistory;
class PlayerCapActionHistory;

#define HACKSIZE sizeof(al::LiveActor)

class HackCap : public al::LiveActor {
    public: 

        void calcReturnTargetPos(sead::Vector3f *);

        void hide(bool);
        void forcePutOn(void);

        void startPuppet();
        void setupThrowStart();

        bool isFlying(void) const;

        unsigned char padding_108[0x108 - HACKSIZE];
        al::LiveActor* mActorDisplayHat;
        al::LiveActor* mActorDepthShadow;
        al::LiveActor* mActorEyes;
        al::LiveActor* mActorThrownEyes;
        al::LiveActor* mPlayerActor;
        IUsePlayerCollision* mPlayerCollision;
        char* mCapModelName;
        PlayerAreaChecker* mJudgeInWater;
        PlayerSeparateCapFlag* mSeparateCapFlag;
        IUsePlayerHeightCheck* mPlayerHeightCheck;
        PlayerWetControl* mPlayerWetControl;
        PlayerJointControlKeeper* mPlayerJointControlKeeper;
        PlayerColliderHackCap* mPlayerColliderHackCap;
        al::WaterSurfaceFinder* mWaterSurfaceFinder;
        al::PadRumbleKeeper* mPadRumbleKeeper;
        PlayerWetControl* mHackCapWetControl;
        HackCapTrigger* mHackCapTrigger;
        al::ActorDitherAnimator* mDitherAnimator;
        HackCapAboveGroundChecker* mAboveGroundChecker;
        al::LiveActor** uVar1;
        int iVar1;
        int iVar2;
        int iVar3;
        al::LiveActor** uVar2;
        int iVar4;
        int iVar5;
        int iVar6;
        al::HitSensor* uVar3;
        al::HitSensor* mSensorAttack;
        sead::Vector3f mSensorTail1;
        sead::Vector3f mSensorTail2;
        sead::Vector3f mSensorTail3;
        sead::Vector3f mSensorTail4;
        sead::Vector3f mSensorTail5;
        HackCapThrowParam* mThrowParam;
        CapTargetInfo* gap3;
        CapTargetInfo* mCapTargetInfo;
        void* uVar4;
        sead::Vector3f vVar1;
        sead::Vector3f vVar2;
        sead::Vector3f vVar3;
        float fVar1;
        float fVar2;
        float fVar3;
        float fVar4;
        float fVar5;
        int iVar7;
        int iVar8;
        float fVar6;
        int iVar9;
        int iVar10;
        int iVar11;
        int iVar12;
        int iVar13;
        bool bVar1;
        bool bVar2;
        bool bVar3;
        bool bVar4;
        bool bVar5;
        bool bVar6;
        bool bVar7;
        bool bVar8;
        bool bVar9;
        bool bVar10;
        bool bVar11;
        bool bVar12;
        bool bVar13;
        bool bVar14;
        bool bVar15;
        bool bVar16;
        bool bVar17;
        bool bVar18;
        PlayerWallActionHistory* mWallActionHistory;
        PlayerCapActionHistory* mCapActionHistory;
        PlayerInput* mPlayerInput;
        PlayerEyeSensorHitHolder* mPlayerEyeSensorHitHolder1;
        PlayerEyeSensorHitHolder* mPlayerEyeSensorHitHolder2;
        sead::Vector3f mPos1;
        sead::Vector3f mPos2;
        sead::Vector3f mPos3;
        sead::Vector3f mPos4;
        bool bVar19;
        bool bVar20;
        bool bVar21;
        HackCapJointControlKeeper* mJointControlKeeper;
};
