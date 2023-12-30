#pragma once

#include "al/hio/HioNode.h"
#include "al/iuse/ISceneObj.h"

class CapManHeroBase;
class StageTalkDemoNpcCap;

class CapManHeroDemoDirector : public al::HioNode, public al::ISceneObj {
public:
    CapManHeroBase* mCapManHero;
    StageTalkDemoNpcCap* mTalkDemoCurrent;
    StageTalkDemoNpcCap* mTalkDemoFirstMoonGet;
    StageTalkDemoNpcCap* mTalkDemoStageStart;
    StageTalkDemoNpcCap* mTalkDemoMoonRock;
};
