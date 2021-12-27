#pragma once

#include "al/scene/Scene.h"
#include "game/Amiibo/HelpAmiiboDirector.h"
#include "game/StageScene/StageSceneLayout.h"

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
        spad(inherit, 0x2D0 - sizeof(al::Scene));
        GameDataHolderAccessor* mHolder; // 0x2D0
        spad(gap1, 0x20);
        StageSceneLayout* stageSceneLayout; // 0x2F8
        spad(gap2, 0x1B8);
        HelpAmiiboDirector* mHelpAmiiboDirector;
        #endif
        #if(SMOVER==130)
        spad(inherit, 0x2E8 - sizeof(al::Scene));
        GameDataHolderAccessor* mHolder; // 0x2E8
        spad(gap1, 0x18);
        StageSceneLayout* stageSceneLayout; // 0x308
        #endif
};
