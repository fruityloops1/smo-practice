#pragma once

#include "al/iuse/IUseAudioKeeper.h"
#include "al/nerve/NerveExecutor.h"

#include <sead/math/seadVector.h>

struct CameraParam {
    bool bVar;
    float fVar1;
    float fVar2;
};

namespace al {
class SnapShotCameraSceneInfo;

class SnapShotCameraCtrl : public al::NerveExecutor, public al::IUseAudioKeeper {
public:
    al::SnapShotCameraSceneInfo* mCameraSceneInfo;
    CameraParam* mParam;
    bool mIsValidLookAtOffset;
    sead::Vector3f mLookAtOffset;
    sead::Vector3f vVar1;
    bool mIsValidZoomFovy;
    float fVar1;
    float fVar2;
    float fVar3;
    float mMaxZoomOutFovyDegree;
    bool mIsValidRoll;
    float mRollDegree;
    float mRollTarget;
    unsigned int uVar2;
    bool bVar1;
};
}
