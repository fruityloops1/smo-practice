#pragma once

#include "types.h"

#include "al/scene/Scene.h"
#include "al/audio/AudioDirector.h"
#include "al/layout/LayoutKit.h"
#include "al/layout/LayoutInitInfo.h"
#include "al/sequence/Sequence.h"
#include "al/sequence/SequenceInitInfo.h"
#include "al/gamepad/util.h"

#include "game/StageScene/StageScene.h"
#include "game/WorldList/WorldResourceLoader.h"
#include "game/GameData/GameDataHolderAccessor.h"

#include "HakoniwaStateDeleteScene.h"
#include "HakoniwaStateDemoOpening.h"
#include "HakoniwaStateDemoEnding.h"
#include "HakoniwaStateDemoWorldWarp.h"
#include "HakoniwaStateSimpleDemo.h"
#include "HakoniwaStateBootLoadData.h"

namespace al
{
    class WipeHolder;
    class ScreenCaptureExecutor;
    class BootLayout;
} // namespace al

class HakoniwaSequence : public al::Sequence {
    public:

        HakoniwaSequence(const char *);
        bool isDisposable(void);
        void updatePadSystem(void);
        void destroySceneHeap(bool);
        void init(al::SequenceInitInfo const &);
        void initSystem(void);
        void update(void);
        bool isEnableSave(void);
        void drawMain(void);
        al::Scene *getCurrentScene(void) const; // {return this->curScene}

        undefined padding[0x90];
        al::Scene *curScene; // 0xB0
        GameDataHolder *mGameDataHolder; // 0xB8
        al::GamePadSystem *mGamepadSys; // 0xC0
        HakoniwaStateDemoOpening *mDemoOpening; // 0xC8
        HakoniwaStateDemoEnding *mDemoEnding; // 0xD0
        HakoniwaStateDemoWorldWarp *mDemoWorldWarp; // 0xD8
        HakoniwaStateSimpleDemo *mSimpleDemo; // 0xE0
        HakoniwaStateBootLoadData *mBootLoadData; // 0xE8
        HakoniwaStateDeleteScene *mDeleteScene; // 0xF0
        al::LayoutKit *mLytKit; // 0xF8

        // undefined * * field_0x0;
        // undefined padding_120[0x120];
        //                     al::Scene * curScene;
        // undefined padding_8[0x8];
        //                     al::AudioDirector * field_0x90;
        // undefined padding_24[0x24];
        //                     StageScene * stageScene;
        //                     GameDataHolderAccessor *gameDataHolder;
        // undefined padding_024[0x24];
        //                     HakoniwaStateDemoWorldWarp * stateDemoWorldWarp;
        // undefined padding_192[0x192];
        //                     int nextScenarioNo;
        // undefined padding_12[0x12];
        //                     al::WipeHolder * field_0x1b0;
        // undefined padding_0024[0x24];
        //                     long * field_0x1d0;
        // undefined padding_48[0x48];
        //                     WorldResourceLoader * worldResourceLoader;
        // undefined padding_0x16[0x16];
        // undefined * field_0x220;
        // undefined padding_0x144[0x144];
        // undefined * field_0x2b8;
        // undefined padding_0x160[0x160];
        // undefined8 field_0x360;
};