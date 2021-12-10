/**
 * @file GameDataHolderAccessor.h
 * @brief Wrapper class for GameDataHolder.
 */

#pragma once

#include "al/scene/Scene.h"
#include "al/scene/SceneInitInfo.h"
#include "game/GameData/GameDataFile.h"
#include "types.h"
#include "GameDataHolderWriter.h"
namespace al{struct SceneInitInfo;class IUseSceneObjHolder; class SceneObjHolder;}
class GameDataHolderAccessor : public GameDataHolderWriter
{
    public:
        GameDataHolderAccessor(al::IUseSceneObjHolder const *);
        GameDataHolderAccessor(al::SceneObjHolder const *);
};