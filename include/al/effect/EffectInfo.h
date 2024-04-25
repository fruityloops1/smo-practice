#pragma once

#include <sead/gfx/seadColor.h>
#include <sead/math/seadVector.h>

namespace al {
class EffectResourceInfo;
class ActionEffectData;

class EffectInfo {
public:
    const char* mName;
    int mResourceCount;
    int iVar1;
    al::EffectResourceInfo* mResourceInfo;
    void* gap1;
    const char* mJointName;
    sead::Vector3f mPosOffset;
    sead::Vector3f mRotate;
    float mScale;
    float mParticleScale;
    float mEmitRatio;
    float mFarClipDistance;
    int mForceCalcFrame;
    int mHandleNum;
    sead::Color4f mColor;
    bool mIsEmitBillboard;
    bool mIsEmitYBillboard;
    bool mIsEmitCamera;
    bool mIsDeleteAtClipping;
    bool mIsOneTimeFade;
    bool mIsEmitIgnoreRotate;
    bool mIsEmitIgnoreScale;
    bool mIsFollowPos;
    bool mIsFollowMtx;
    bool mIsEmitTrans;
    bool mIsEmitRotate;
    bool mIsEmitScale;
    bool mIsFollowTrans;
    bool mIsFollowRotate;
    bool mIsFollowScale;
    bool mIsNeedProgramInfo;
    bool bVar1;
    bool mIsSetMtxPtr;
    bool mIsDirectPos;
    bool mIsNonZeroPosOffset;
    bool mIsNonZeroRotate;
    bool mIsWhite;
    bool mIsBindWorldAxisX;
    bool mIsBindWorldAxisY;
    bool mIsBindWorldAxisZ;
    bool mIsNoEmitAtNoCollide;
    bool mIsFollowScaleByFovy;
    unsigned char gap2[0x5];
    int mActionEffectDataCount;
    int iVar2;
    al::ActionEffectData* mActionEffectData;
    int mHitReactionCount;
};
}
