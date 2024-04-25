#pragma once

#include "al/area/AreaObjGroup.h"
#include "al/collision/KCPrism.h"
#include "al/PlayerHolder/PlayerHolder.h"
#include "al/scene/Scene.h"
#include "al/util.hpp"
#include "game/StageScene/StageScene.h"

#include <sead/gfx/seadPrimitiveRenderer.h>
#include <agl/DrawContext.h>

namespace al {
    class AreaObj;
    class Triangle;
    class HitInfo;
    class LiveActorKit;
}


float calcFadeoff(al::LiveActor const *actor, sead::Vector3f pos2);
// bool tryDrawAreaGroup(al::Scene *curScene, char const *area, bool isDrawSolid, sead::Color4f wire, sead::Color4f solid, sead::Color4f cyl);
void drawWireTriangle(sead::PrimitiveRenderer* renderer, al::Triangle const& tri, sead::Color4f wire, sead::Color4f colorNormal, bool drawNormal);
void drawAreaObjGroup(sead::PrimitiveRenderer* renderer, al::AreaObjGroup const* group, bool isDrawSolid = false, sead::Color4f wire = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f), sead::Color4f solid = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f), sead::Color4f cyl = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f));
void drawAreaObj(sead::PrimitiveRenderer* renderer, al::AreaObj const* area, bool isDrawSolid = false, sead::Color4f wire = sead::Color4f(0.0f, 1.0f, 0.0f, 0.5f), sead::Color4f solid = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f), sead::Color4f cyl = sead::Color4f(0.0f, 1.0f, 0.0f, 0.1f));
void drawHitInfo(sead::PrimitiveRenderer* renderer, al::HitInfo const* hitInfo, sead::Color4f wire = sead::Color4f(0.96f, 0.96f, 0.86f, 0.8f), sead::Color4f solid = sead::Color4f(1.0f, 0.1f, 0.1f, 0.3f));
void drawAllCollision(sead::PrimitiveRenderer* renderer, al::LiveActorKit const& liveActorKit);
