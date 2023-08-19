#pragma once

#include "al/actor/WaterSurfaceFinder.h"
#include "al/LiveActor/LiveActor.h"
#include <sead/container/seadListImpl.h>

class CapTargetInfo;
class EnemyStateSwoon;
class EnemyStateReset;
class EnemyStateWander;
class ActorStateSandGeyser;
class EnemyStateBlowDown;
class JointSpringControllerHolder;
class EnemyCap;
class CollisionPartsFilterBase;
class PlayerPushReceiver;
class CollisionMultiShape;
class CollisionShapeKeeper;
class PlayerCeilingCheck;
class DisregardReceiver;

class KuriboStateHack {

};

class KuriboHack : public al::LiveActor {
public:
    CapTargetInfo* mCapTargetInfo;
    EnemyStateSwoon* mStateSwoon;
    EnemyStateReset* mStateReset;
    EnemyStateWander* mStateWander;
    ActorStateSandGeyser* mStateSandGeyser;
    KuriboStateHack* mStateHack;
    EnemyStateBlowDown* mStateBlowDown;
    JointSpringControllerHolder* mJointSpringControllerHolder;
    bool bVar1;
    EnemyCap* mEnemyCap;
    bool bVar2;
    KuriboHack* mChild;
    bool mIsGold;
    int iVar1;
    CollisionPartsFilterBase* mCollisionPartsFilter;
    sead::Vector3f vVar1;
    float fVar1;
    PlayerPushReceiver* mPushReceiver;
    CollisionMultiShape* mCollisionMultiShape;
    CollisionShapeKeeper* mCollisionShapeKeeper;
    unsigned char padding[0x4];
    int iVar2;
    int iVar3;
    int iVar4;
    unsigned int uVar1;
    int iVar5;
    int iVar6;
    float fVar2;
    PlayerCeilingCheck* mCeilingCheck;
    bool bVar3;
    sead::Vector3f mEndHackTargetPos;
    int iVar7;
    const char* mJointName;
    sead::Matrix34f mVar1;
    sead::Matrix34f mVar2;
    unsigned char padding1[0x14];
    int iVar8;
    al::HitSensor* mSensor1;
    sead::Vector3f vVar2;
    int iVar9;
    al::WaterSurfaceFinder* mWaterSurfaceFinder;
    sead::Matrix34f mVar3;
    sead::Matrix34f mVar4;
    bool bVar4;
    sead::ListImpl mKuriboList;
    unsigned char padding2[0x10];
    DisregardReceiver* mDisregardReceiver;
    unsigned char padding3[0x8];

};
