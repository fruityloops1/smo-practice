#pragma once

#include "al/scene/Scene.h"
#include "game/Amiibo/HelpAmiiboDirector.h"
#include "game/StageScene/StageSceneLayout.h"

namespace al {
class LiveActorGroup;
class Projection;
class WipeHolder;
class WipeSimple {
    public:
    void startOpen(int);
    void startClose(int);
};
class WindowConfirm;
class HtmlViewer;
class SimpleLayoutAppearWaitEnd;
class SimpleAudioUser;
class CameraTicket;
class ParabolicPath;
class DemoSyncedEventKeeper;
class ChromakeyDrawer;
class NfpDirector;
class LayoutTextureRenderer;
class LiveActor;
}

class StageSceneStateTimeBalloon;
class StageSceneStateWorldMap;
class StageSceneStateShop;
class StageSceneStateSnapShot;
class StageSceneStateGetShine;
class StageSceneStateGetShineMain;
class StageSceneStateGetShineGrand;
class StageSceneStateCollectBgm;
class StageSceneStateMiniGameRanking;
class StageSceneStatePauseMenu;
class StageSceneStateCloset;
class StageSceneStateCollectionList;
class StageSceneStateSkipDemo;
class StageSceneStateCheckpointWarp;
class StageSceneStateCarryMeat;
class TimeBalloonSequenceInfo;
class StageSceneStateTitleLogo;
class StageSceneStateMiss;
class StageSceneStateYukimaruRace;
class StageSceneStateYukimaruRaceTutorial;
class StageSceneStateRaceManRace;
class StageSceneStateRadicon;
class StageSceneStateScenarioCamera;
class StageSceneStateGetShineMainSandWorld;
class StageSceneStateRecoverLife;
class StageSceneStateTalk;
class StageSceneStateWarp;
class StageSceneStateWorldIntroCamera;
class ScenarioStartCameraHolder;
class CinemaCaption;
class MapLayout;
class CollectionList;
class TimeBalloonNpc;
class ProjectItemDirector;
class Pyramid;
class PlayGuideSkip;
class LocationNameCtrl;
class MiniGameMenu;
class NpcEventDirector;
class ControllerGuideSnapShotCtrl;
class InputSeparator;
class OpeningStageStartDemo;
class SceneAudioSystemPauseController;
class DemoSoundSynchronizer;
class ProjectSeNamedList;
class TimeBalloonDirector;
class KoopaHackFunction;
class CollectBgmRegister;
class BgmAnimeSyncDirector;
class HelpAmiiboDirector;

class StageScene : public al::Scene
{
    public:
        StageScene();

        virtual ~StageScene();
        virtual void init(const al::SceneInitInfo &);
        virtual void appear();
        virtual void kill();
        
        virtual void control();
        virtual void drawMain();

        #if SMOVER==100
        bool isEnableSave(void) const;
        bool isDefeatKoopaLv1() const;
        #endif
        #if SMOVER==130
        CVEFUN(StageScene, 0x004731A0, bool, isEnableSave);
        CVEFUN(StageScene, 0x00473080, bool, isDefeatKoopaLv1);
        #endif
        #if(SMOVER==100)
        sead::FixedSafeString<64> mCurrentStageName;
        unsigned int scenarioNo;

        // States - 0x138 to 0x208
        StageSceneStateWorldMap *mStateWorldMap;
        StageSceneStateShop *mStateShop;
        StageSceneStateSnapShot *mStateSnapShot;
        StageSceneStateGetShine *mStateGetShine;
        StageSceneStateGetShineMain *mStateGetShineMain;
        StageSceneStateGetShineGrand *mStateGetShineGrand;
        StageSceneStateCollectBgm *mStateCollectBgm;
        StageSceneStateCollectionList *mStateCollectionList;
        StageSceneStateMiniGameRanking *mStateMiniGameRanking;
        StageSceneStatePauseMenu *mStatePauseMenu;
        StageSceneStateCloset *mStateCloset;
        StageSceneStateSkipDemo *mStateSkipDemo;
        StageSceneStateCheckpointWarp *mStateCheckpointWarp;
        StageSceneStateCarryMeat *mStateCarryMeat;
        StageSceneStateTimeBalloon *mStateTimeBalloon;
        StageSceneStateTitleLogo *mStateTitleLogo;
        StageSceneStateMiss *mStateMiss;
        StageSceneStateYukimaruRace *mStateYukimaruRace;
        StageSceneStateYukimaruRaceTutorial *mStateYukimaruRaceTutorial;
        StageSceneStateRaceManRace *mStateRaceManRace;
        StageSceneStateRadicon *mStateRadicon;
        StageSceneStateScenarioCamera *mStateScenarioCamera;
        StageSceneStateRecoverLife *mStateRecoverLife;
        StageSceneStateGetShineMainSandWorld *mStateGetShineMainSandWorld;
        StageSceneStateTalk *mStateTalk;
        StageSceneStateWarp *mStateWarp;
        StageSceneStateWorldIntroCamera *mStateWorldIntroCamera;

        ScenarioStartCameraHolder *mScenarioStartCameraHolder;
        sead::FixedSafeString<64> mCostumeName;
        sead::FixedSafeString<64> mCapName;
        unsigned char gap1[0x8];
        GameDataHolderAccessor *mDataHolder;
	    al::PlacementInfo *mPlacementInfo;
	    al::LayoutTextureRenderer *mLayoutTextureRenderer;
	    PlayGuideSkip *mPlayGuideSkip;
        CinemaCaption *mCinemaCaption;
        StageSceneLayout *mStageSceneLayout;
        bool enableLayout;
	    al::SimpleLayoutAppearWaitEnd *mLayoutStartScenario;
	    al::SimpleLayoutAppearWaitEnd *mLayoutStartWorld;
	    al::SimpleLayoutAppearWaitEnd *mLayoutStartWorldRegion;
	    ControllerGuideSnapShotCtrl *mControllerGuideSnapShotCtrl;
	    InputSeparator *mInputSeparator;
	    al::WipeSimple *mWipeCircle;
        al::WipeHolder *mWipeHolder;
        LocationNameCtrl *mLocationNameCtrl;
        al::WindowConfirm *mWindowConfirm;
        MiniGameMenu *mMiniGameMenu;
        bool *hasStartedStage; // probably wrong
        unsigned char gap_360[0x10];
        MapLayout *mMapLayout;
        al::SimpleLayoutAppearWaitEnd *mMenuLayout;
        al::LiveActorGroup *mShoppingWatcher;
        CollectionList *mCollectionList;
        __int64_t unkNoIdea;
        TimeBalloonNpc *mTimeBalloonNpc; // placement for this object 004C9844
        ProjectItemDirector *mProjectItemDirector;
        Pyramid *mPyramid;
        OpeningStageStartDemo *mOpeningStageStartDemo; // can also be DemoStartWorldWaterfallStage
        __int64_t nerveExeDemoStageStart;
        SceneAudioSystemPauseController *mSceneAudioSystemPauseController;
        DemoSoundSynchronizer *mDemoSoundSynchronizer;
        al::SimpleAudioUser *mAudioStageStartAtmosSe;
        al::SimpleAudioUser *mAudioSePlayArea;
        al::SimpleAudioUser *mAudioSnapShotCameraCtrl;
        ProjectSeNamedList *mProjectSeNamedList;
        unsigned char gap_3F0[0x8];
        TimeBalloonDirector *mTimeBalloonDirector;
        TimeBalloonSequenceInfo *mTimeBalloonSequenceInfo;
        __int64_t unkSomethingElse;
        al::CameraTicket *mWarpCheckpointCamera;
        sead::Vector3f *mWarpToCheckpointCamera;
        sead::Vector3f *mWarpToCheckpointCameraPoint;
        sead::Vector3f *mWarpToCheckpointPlayerPos;
        sead::Vector3f mWarpToCheckpointDestPoint;
        unsigned char padding_43C[0x4];
        al::LiveActor *mCheckpointFlagWarp;
        al::ParabolicPath *mParabolicPath;
        KoopaHackFunction *mKoopaHackFunction;
        al::LiveActor *mShineDot;
        unsigned char gap_460[0x10];
        CollectBgmRegister *mCollectBgmRegister;
        BgmAnimeSyncDirector *mBgmAnimeSyncDirector;
        al::DemoSyncedEventKeeper *mDemoSyncedEventKeeper;
        char *activeDemoName;
        char *activeDemoType; // maybe wrong
	    NpcEventDirector *mNpcEventDirector;
        al::ChromakeyDrawer *mChromakeyDrawer;
        al::HtmlViewer *mHtmlViewer;
        al::NfpDirector *mNfpDirector;
        HelpAmiiboDirector *mHelpAmiiboDirector;
        #endif
        #if(SMOVER==130)
        spad(inherit, 0x2E0 - sizeof(al::Scene));
        GameDataHolderAccessor* mDataHolder; // 0x2E0
        spad(gap1, 0x20);
        StageSceneLayout* mStageSceneLayout; // 0x308
        #endif
};
