#pragma once

#include "al/LiveActor/LiveActor.h"
#include "game/Interfaces/IUsePlayerHack.h"
#include "al/iuse/IEventFlowEventReceiver.h"
#include "al/event/EventFlowExecutor.h"
#include <sead/math/seadVector.h>
#include <sead/math/seadMatrix.h>
#include <sead/container/seadPtrArray.h>
#include "al/iuse/IUseNerve.h"
#include "al/nerve/NerveKeeper.h"

class CapTargetInfo;
class EnemyStateHackStart;
class PlayerPushReceiver;

namespace al {

class ActorCameraTarget;
class CameraTicket;

class JointControllerBase : public al::HioNode {
public:
    unsigned char padding[0x8];
    sead::PtrArrayImpl mArray;
    void* gap1;
    void* gap2;
};

}

class JugemFishingSurfaceCheckInfo {

};

class JugemFishingFloatOffsetCtrl : public al::JointControllerBase, public al::IUseNerve {
public:
    al::LiveActor* mActor;
    JugemFishingSurfaceCheckInfo* mSurfaceCheckInfo;
    al::NerveKeeper* mNerveKeeper;
    sead::Matrix34f* mMat1;
    sead::Matrix34f mMat2;
    float fVar1;
    float fVar2;
};

class JugemFishingHookOffsetCtrl : public al::JointControllerBase, public al::IUseNerve {
public:
    al::NerveKeeper* mNerveKeeper;
    JugemFishingSurfaceCheckInfo* mSurfaceCheckInfo;
};


class JugemFishing : public al::LiveActor, public al::IEventFlowEventReceiver, public IUsePlayerHack {
public:
    CapTargetInfo* mCapTargetInfo;
    al::EventFlowExecutor* mEventFlowExecutor;
    unsigned char padding[0x8];
    EnemyStateHackStart* mStateHackStart;
    void* gap1;
    JugemFishingFloatOffsetCtrl* mFloatOffsetCtrl;
    JugemFishingHookOffsetCtrl* mHookOffsetCtrl;
    void* gap2;
    void* gap3;
    JugemFishingSurfaceCheckInfo* mSurfaceCheckInfo;
    void* gap4;
    PlayerPushReceiver* mPlayerPushReceiver;
    unsigned char padding1[0xc];
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    unsigned char padding2[0x4];
    bool bVar1;
    bool bVar2;
    bool bVar3;
    bool bVar4;
    int iVar1;
    int iVar2;
    int iVar3;
    al::CameraTicket* mTicket1;
    al::CameraTicket* mTicket2;
    al::ActorCameraTarget* mCameraTarget;


};
