#pragma once

#include "al/hio/HioNode.h"
#include "al/iuse/IUseAreaObj.h"
#include "al/iuse/IUseAudioKeeper.h"
#include "al/iuse/IUseCollision.h"
#include "al/iuse/IUseName.h"
#include "al/iuse/IUseNerve.h"
#include "al/iuse/IUseRail.h"

#include <sead/math/seadMatrix.h>
#include <sead/math/seadVector.h>

namespace al {
class CameraPoserSceneInfo;
class CameraViewInfo;
class CameraPoserFlag;
class CameraVerticalAbsorber;
class CameraAngleCtrlInfo;
class CameraAngleSwingInfo;
class CameraArrowCollider;
class CameraOffsetCtrlPreset;
class LocalInterpole;
class LookAtInterpole;
class CameraParamMoveLimit;
class CameraTargetAreaLimitter;
class GyroCameraCtrl;
class RailKeeper;
class OrthoProjectionParam;

class SnapShotCameraCtrl;

class CameraPoser : public al::HioNode, public al::IUseAreaObj, public al::IUseAudioKeeper, public al::IUseCollision, public al::IUseName, public al::IUseNerve, public al::IUseRail {
public:
    const char* mName;
    float fVar1;
    sead::Vector3f mPosition;
    sead::Vector3f mTargetTrans;
    sead::Vector3f mCameraUp;
    float mFovyDegree;
    float mNearClipDistance;
    sead::Matrix34f mViewMtx;
    bool bVar1;
    al::CameraPoserSceneInfo* mPoserSceneInfo;
    al::CameraViewInfo* mViewInfo;
    al::CameraPoserFlag* mFlag;
    al::CameraVerticalAbsorber* mVerticalAbsorber;
    al::CameraAngleCtrlInfo* mAngleCtrlInfo;
    al::CameraAngleSwingInfo* mAngleSwingInfo;
    al::CameraArrowCollider* mArrowCollider;
    al::CameraOffsetCtrlPreset* mOffsetCtrlPreset;
    al::LocalInterpole* mLocalInterpole;
    al::LookAtInterpole* mLookAtInterpole;
    al::CameraParamMoveLimit* mParamMoveLimit;
    al::CameraTargetAreaLimitter* mTargetAreaLimitter;
    al::GyroCameraCtrl* mGyroCameraCtrl;
    al::SnapShotCameraCtrl* mSnapShotCameraCtrl;
    al::AudioKeeper* mAudioKeeper;
    al::NerveKeeper* mNerveKeeper;
    al::RailKeeper* mRailKeeper;
    void* gap1;
    void* gap2;
    al::OrthoProjectionParam* mOrthoProjectionParam;
};
}
