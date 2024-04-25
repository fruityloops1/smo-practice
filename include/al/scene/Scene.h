#pragma once

#include "game/GameData/GameDataHolderAccessor.h"
#include <al/nerve/NerveExecutor.h>
#include "al/audio/AudioKeeper.h"
#include "al/camera/CameraDirector.h"
#include "al/iuse/IUseSceneObjHolder.h"
#include "SceneInitInfo.h"

namespace al
{
    class LiveActorKit;
    class StageResourceKeeper;
    class LayoutKit;
    class SceneStopCtrl;
    class SceneMsgCtrl;
    class SceneCoverCtrl;
    class SceneObjHolder;
    class AudioDirector;
    class AudioKeeper;
    struct DrawSystemInfo;

    class Scene : public al::NerveExecutor, public al::IUseAudioKeeper, public al::IUseCamera, public al::IUseSceneObjHolder
    {
    public:
        Scene(const char *);

        virtual ~Scene();
        //virtual void init(const al::SceneInitInfo &);
        virtual void appear();
        virtual void kill();
        virtual void movement();
        virtual void control();
        virtual void drawMain();
        virtual void drawSub();
        virtual al::AudioKeeper* getAudioKeeper();
        virtual al::SceneObjHolder* getSceneObjHolder();
        virtual al::CameraDirector* getCameraDirector(); 
        
        bool mIsAlive;
        sead::FixedSafeString<64> mName;
        StageResourceKeeper* mStageResourceKeeper;
        LiveActorKit* mLiveActorKit;
        LayoutKit* mLayoutKit;
        SceneObjHolder* mSceneObjHolder;
        SceneStopCtrl* mSceneStopCtrl;
        SceneMsgCtrl* mSceneMsgCtrl;
        SceneCoverCtrl* mSceneCoverCtrl;
        AudioDirector* mAudioDirector;
        AudioKeeper* mAudioKeeper;
        DrawSystemInfo* mDrawSystemInfo;
    };
};
