#pragma once

#include "al/camera/CameraTicket.h"
#include "al/nerve/NerveExecutor.h"

#include <sead/gfx/seadCamera.h>

namespace al {
class SceneCameraInfo;
class CameraViewFlag;
class Projection;
class CameraSwitcher;
class CameraStartParamCtrl;
class CameraStopJudge;
class CameraParamTransfer;
class CameraInterpole;
class CameraShaker;

class CameraPoseUpdater : public al::NerveExecutor {
public:
    int mSnapShotOrientationRotate;
    al::SceneCameraInfo* mSceneCameraInfo;
    void* gap1;
    al::CameraViewInfo* mCameraViewInfo;
    al::CameraViewFlag* mCameraViewFlag;
    bool bVar1;
    int iVar1;
    sead::LookAtCamera mLookAtCamera;
    al::CameraTicket* mTicket;
    al::Projection* mProjection;
    void* gap2;
    float mNearClipDistance;
    float fVar1;
    float fVar2;
    float fVar3;
    al::CameraSwitcher* mCameraSwitcher;
    al::CameraStartParamCtrl* mCameraStartParamCtrl;
    al::CameraStopJudge* mCameraStopJudge;
    al::CameraParamTransfer* mCameraParamTransfer;
    const char* sVar1;
    al::CameraInterpole* mCameraInterpole;
    al::CameraShaker* mCameraShaker;
};
}
