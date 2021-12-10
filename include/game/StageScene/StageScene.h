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

        bool isEnableSave(void) const;
        spad(inherit, 0x2D0 - sizeof(al::Scene));
        GameDataHolderAccessor* mHolder; // 0x2D0
        spad(gap1, 0x20);
        StageSceneLayout* stageSceneLayout; // 0x2F8
        spad(gap2, 0x1B8);
        HelpAmiiboDirector* mHelpAmiiboDirector;
};
