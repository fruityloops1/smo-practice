#pragma once

#include <sead/math/seadVector.h>

class IUsePlayerCollision;

class PlayerWallActionHistory {
public:
    void recordWallJump(IUsePlayerCollision *, sead::Vector3f *);
    void recordWallJump(sead::Vector3f *, sead::Vector3f *);
    void recordWallLeave(sead::Vector3f *, sead::Vector3f *);
    void reset(void);
    void update(IUsePlayerCollision *);

    bool mHasJumped = false;
    sead::Vector3f mWallJumpPos;
    sead::Vector3f mWallJumpNormal;
    bool mHasLeft = false;
    sead::Vector3f mWallLeavePos;
    sead::Vector3f mWallLeaveNormal;
};
