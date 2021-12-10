#pragma once

#include "al/scene/Scene.h"
#include "game/StageScene/StageSceneLayout.h"

#define INHERITSIZE sizeof(al::Scene)

class StageScene : public al::Scene
{
    public:
        undefined padding[0x2F8 - INHERITSIZE];
        StageSceneLayout *stageSceneLayout; // 0x2F8
};
