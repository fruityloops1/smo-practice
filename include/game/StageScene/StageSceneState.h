#pragma once

#include "al/nerve/NerveStateBase.h"
#include "al/scene/Scene.h"
#include "game/Layouts/ShineListLayout.h"

class HackListLayout;
class SouvenirListLayout;
class StageSceneStateStageMap;
class StageSceneStateCollectBgm;
class InputSeparator;
class CursorParts;
class FooterParts;
class RollParts;
class SceneAudioSystemPauseController;
namespace al {
class SimpleLayoutAppearWaitEnd;
}

class StageSceneStateCollectionList : public al::NerveStateBase {
public:
    al::Scene* mScene;
    ShineListLayout* mShineList;
    HackListLayout* mHackList;
    SouvenirListLayout* mSouvenirList;
    StageSceneStateStageMap* mStateStageMap;
    StageSceneStateCollectBgm* mStateCollectBgm;
    InputSeparator* mInputSeparator;
    al::SimpleLayoutAppearWaitEnd* uVar1;
    CursorParts* mCursorParts;
    al::SimpleLayoutAppearWaitEnd* uVar2;
    FooterParts* mFooterParts;
    RollParts* mRollParts;
    void* uVar3;
    unsigned char padding[0x18];
    SceneAudioSystemPauseController* mSceneAudioSystemPauseController;
};
