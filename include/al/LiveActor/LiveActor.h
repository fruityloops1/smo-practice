#pragma once

#include "al/actor/ActorInitInfo.h"
#include "al/area/AreaObjDirector.h"
#include "al/audio/AudioKeeper.h"
#include "al/camera/CameraDirector.h"
#include "al/collision/CollisionDirector.h"
#include "al/effect/EffectKeeper.h"
#include "al/hio/HioNode.h"
#include "al/nerve/Nerve.h"
#include "al/pose/ActorPoseKeeper.h"
#include "al/rail/RailKeeper.h"
#include "al/rail/RailRider.h"
#include "al/scene/SceneObjHolder.h"
#include "al/screen/ScreenPointKeeper.h"
#include "al/sensor/HitSensorKeeper.h"
#include "al/sensor/HitSensor.h"
#include "al/switch/StageSwitchKeeper.h"

// vtable for LiveActor: 1C4EB58

namespace al
{
    class HitSensor;
    class SensorMsg;
    class ScreenPointer;
    class ScreenPointTarget;
    class LiveActor : public al::IUseNerve, public al::IUseEffectKeeper, public al::IUseAudioKeeper, public al::IUseStageSwitch, public al::IUseSceneObjHolder, public al::IUseAreaObj, public al::IUseCamera, public al::IUseCollision, public al::IUseRail, public al::IUseHioNode
    {
    public:
        LiveActor(const char *);

        virtual NerveKeeper* getNerveKeeper() const override;
        virtual void init(const ActorInitInfo&);
        virtual void initAfterPlacement();
        virtual void appear();
        virtual void makeActorAlive();
        virtual void kill();
        virtual void makeActorDead();
        virtual void movement();
        virtual void calcAnim();
        virtual void draw() const;
        virtual void startClipped();
        virtual void endClipped();
        virtual void attackSensor(HitSensor*, HitSensor*);
        virtual bool receiveMsg(const SensorMsg*, HitSensor*, HitSensor*);  // NOTE: return type unknown
        virtual bool receiveMsgScreenPoint(const SensorMsg*, ScreenPointer*,
                                       ScreenPointTarget*);  // NOTE: return type unknown
        virtual const char* getName() const override;
        virtual void* getBaseMtx() const;  // NOTE: return type unknown
        virtual EffectKeeper* getEffectKeeper() const override;
        virtual AudioKeeper* getAudioKeeper() const override;
        virtual StageSwitchKeeper* getStageSwitchKeeper() const override;
        virtual RailRider* getRailRider() const override;
        virtual SceneObjHolder* getSceneObjHolder() const override;
        virtual CollisionDirector* getCollisionDirector() const override;
        virtual AreaObjDirector* getAreaObjDirector() const override;
        virtual CameraDirector* getCameraDirector() const override;
        virtual void initStageSwitchKeeper() override;
        virtual void control();
        virtual void updateCollider();
        
        const char* mActorName; // _48
        al::ActorPoseKeeperBase* mPoseKeeper; // _50
        char _58[0x90-0x58];
        al::NerveKeeper* mNerveKeeper; // _90
        al::HitSensorKeeper* mHitSensorKeeper; // _98
        al::ScreenPointKeeper* mScreenPointKeeper; // _A0
        al::EffectKeeper* mEffectKeeper; // _A8
        al::AudioKeeper* mAudioKeeper; // _B0

        al::StageSwitchKeeper* mStageSwitchKeeper; // _C0
        al::RailKeeper* mRailKeeper; // _C8
    };
};