#pragma once

#include "al/nerve/NerveExecutor.h"
#include "al/LiveActor/LiveActor.h"
#include "al/sensor/HitSensor.h"
#include "game/Player/PlayerAnimator.h"

class IPlayerModelChanger;
class IUsePlayerCeilingCheck;
class PlayerJointParamHandLegAngle;
class IUsePlayerCollision;
class PlayerPushReceiver;
class PlayerActorHakoniwa;

class PlayerCarryKeeper : public al::NerveExecutor {
public:
    PlayerCarryKeeper(al::LiveActor const*, al::HitSensor*, PlayerAnimator*, IPlayerModelChanger const*, IUsePlayerCeilingCheck const*, PlayerJointParamHandLegAngle*);
    ~PlayerCarryKeeper();

    bool endCameraSubjective();
    void endDemoShineGet();
    void exeCarry();
    void exeRelease();
    void exeStart();
    void exeThrow();
    void exeWait();
    const char* getCarryAnimName() const;
    const char* getCarryStartAnimName() const;
    const char* getCarryThrowAnimName() const;
    const char* getThrowReleaseFrame() const;
    bool isCarry() const;
    bool isCarryFront() const;
    bool isCarryUp() const;
    bool isCarryWallKeep() const;
    bool isThrow() const;
    bool isThrowHandR() const;
    bool isThrowHold() const;
    bool isThrowRelease() const;
    bool sendPlayerWarp();
    bool startCameraSubjective();
    void startCancelAndRelease();
    bool startCarry(al::HitSensor*);
    bool startDemoKeepCarry();
    void startDemoShineGet();
    void startRelease();
    void startReleaseDamage();
    void startReleaseDead();
    void startReleaseDemo();
    bool startThrow(bool);
    void update();
    bool updateCollideLockUp(IUsePlayerCollision const*, PlayerPushReceiver const*);
    void updateHandJointAngle();

    PlayerActorHakoniwa* mPlayer;
    PlayerAnimator* mAnimator;
    al::HitSensor* mSensorPlayer;
    al::HitSensor* mSensorHeld;
    IPlayerModelChanger* mModelChanger;
    IUsePlayerCeilingCheck* mCeilingCheck;
    PlayerJointParamHandLegAngle* mJointParamHandLegAngle;
    int iVar1;
    bool mIsCarryUp;
    bool bVar1;
    sead::Vector3f vVar1;
    float fVar1;
    sead::Vector3f vVar2;

};
