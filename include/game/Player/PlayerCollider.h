#pragma once

#include "al/collision/CollisionDirector.h"
#include "al/LiveActor/LiveActor.h"
#include "game/Interfaces/IUsePlayerCollision.h"
#include <sead/math/seadVector.h>
#include <sead/math/seadMatrix.h>
#include <sead/container/seadPtrArray.h>

namespace al {
    class HitInfo;
}


class PlayerCeilingCheck;
class CollisionShapeKeeper;
class CollisionPartsFilterOnlySpecialPurpose;
class CollisionMultiShape;
class CollisionPartsFilterBase;

class IUsePlayerCeilingCheck {
public:
    virtual bool isEnableStandUp() const;
    virtual bool isEnableHoldUp() const;
    virtual bool isPressedCeil() const;
    virtual float getSafetyCeilSpace() const;
    virtual float getCeilCheckHeight() const;
};

class IUsePlayerHeightCheck {
public:
    virtual bool isAboveGround() const;
    virtual float getGroundHeight() const;
    virtual float getShadowDropHeight() const;
};

class IUsePlayerFallDistanceCheck {
public:
    virtual float getFallDistance() const;
};


class PlayerCollider {
public:
    virtual al::CollisionDirector* getCollisionDirector() const;

    enum WallBorderCheckType {
        cNone, cNoFace, cAll
    };

    al::CollisionDirector* mCollisionDirector;
    sead::Matrix34f* mVar1;
    sead::Vector3f* vVar1;
    sead::Vector3f* vVar2;
    sead::Vector3f vVar3;
    float fVar1;
    sead::Matrix34f mVar2;
    al::HitInfo* mHitFloor;
    float fVar2;
    al::HitInfo* mHitWall;
    float fVar3;
    al::HitInfo* mHitCeil;
    float fVar4;
    void* gap1;
    bool bVar1;
    bool bVar2;
    sead::Vector3f vVar4;
    sead::Vector3f vVar5;
    unsigned char gap2[0x4];
    sead::Matrix34f mVar3;
    CollisionShapeKeeper* mCollisionShapeKeeper;
    float mCollisionShapeScale;
    CollisionMultiShape* uVar2;
    unsigned char gap3[0x4];
    bool mIsFastMoveCollisionArea;
    bool bVar3;
    bool bVar4;
    sead::Vector3f vVar6;
    WallBorderCheckType mWallBorderCheckType;
    CollisionPartsFilterBase* mCollisionPartsFilter;
    sead::PtrArrayImpl arr1;
    sead::PtrArrayImpl arr2;
    sead::PtrArrayImpl arr3;
    al::HitInfo (*uVar3)[64];
    unsigned int uVar4;
    sead::PtrArray<al::HitInfo> arr4;
    sead::PtrArrayImpl arr5;
    sead::PtrArrayImpl arr6;
    sead::Vector3f vVar7;
    sead::Vector3f vVar8;
    float fVar5;
};

class PlayerConst;

class PlayerColliderHakoniwa : public IUsePlayerCollision, public IUsePlayerCeilingCheck, public IUsePlayerHeightCheck, public IUsePlayerFallDistanceCheck {
public:
    al::LiveActor* mPlayer;
    PlayerConst* mPlayerConst;
    PlayerCollider* mCollider;
    PlayerCeilingCheck* mCeilingCheck;
    bool mIsAboveGround;
    float mGroundHeight;
    float mShadowDropHeight;
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    float mFallDistance;
    int iVar1;
    al::HitSensor* uVar1;
    CollisionShapeKeeper* uVar2;
    CollisionShapeKeeper* uVar3;
    CollisionShapeKeeper* uVar4;
    CollisionShapeKeeper* uVar5;
    CollisionShapeKeeper* uVar6;
    CollisionShapeKeeper* uVar7;
    CollisionShapeKeeper* uVar8;
    CollisionShapeKeeper* uVar9;
    CollisionPartsFilterOnlySpecialPurpose* mFilter2DOnly;
};
