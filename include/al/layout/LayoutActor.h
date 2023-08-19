#pragma once

#include "al/layout/IUseLayout.h"
#include "al/hio/HioNode.h"
#include "al/nerve/Nerve.h"
#include "al/camera/CameraDirector.h"
#include "al/audio/AudioKeeper.h"
#include "al/effect/EffectKeeper.h"
#include "al/iuse/IUseSceneObjHolder.h"
#include "al/message/IUseMessageSystem.h"

namespace al {
    class LayoutActionKeeper;
class LayoutKeeper;
class LayoutTextPaneAnimator;
class LayoutExecuteInfo;
class HitReactionKeeper;
class LayoutSceneInfo;
class LayoutPartsActorKeeper;

    class IUseLayoutAction {
public:
    virtual al::LayoutActionKeeper* getLayoutActionKeeper() const = 0;
};

    class LayoutActor : public al::IUseHioNode, public al::IUseNerve, public al::IUseLayout, public al::IUseLayoutAction, public al::IUseMessageSystem, public al::IUseCamera, public al::IUseAudioKeeper, public al::IUseEffectKeeper, public al::IUseSceneObjHolder {
        public:
    virtual al::NerveKeeper* getNerveKeeper() const override;
    virtual void appear();
    virtual void kill();
    virtual void movement();
    virtual void calcAnim(bool);
    virtual const char* getName() const override;
    virtual al::EffectKeeper* getEffectKeeper() const override;
    virtual al::AudioKeeper* getAudioKeeper() const override;
    virtual al::LayoutActionKeeper* getLayoutActionKeeper() const override;
    virtual al::LayoutKeeper* getLayoutKeeper() const;
    virtual al::CameraDirector* getCameraDirector() const override;
    virtual al::SceneObjHolder* getSceneObjHolder() const override;
    virtual al::MessageSystem* getMessageSystem() const override;
    virtual void control();

    sead::FixedSafeString<128> mName;
    al::NerveKeeper* mNerveKeeper;
    al::LayoutKeeper* mLayoutKeeper;
    al::LayoutActionKeeper* mLayoutActionKeeper;
    al::LayoutTextPaneAnimator* mTextPaneAnimator;
    al::EffectKeeper* mEffectKeeper;
    al::AudioKeeper* mAudioKeeper;
    al::LayoutExecuteInfo* mExecuteInfo;
    al::HitReactionKeeper* mHitReactionKeeper;
    al::LayoutSceneInfo* mSceneInfo;
    al::LayoutPartsActorKeeper* mPartsActorKeeper;
    bool mIsAlive;
    };
}
