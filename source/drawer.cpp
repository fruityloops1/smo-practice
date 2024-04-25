#include "drawer.h"
#include "al/area/AreaObj.h"
#include "al/area/AreaShape.h"
#include "al/collision/CollisionParts.h"
#include "al/collision/KCollisionServer.h"
#include "al/collision/Triangle.h"
#include "al/collision/HitInfo.h"
#include "al/LiveActor/LiveActorGroup.h"
#include "al/LiveActor/LiveActorKit.h"
#include "al/util.hpp"
#include "constants.h"

bool enableFadeoff = true;

float calcFadeoff(al::LiveActor const* actor, sead::Vector3f const& pos2)
{
    if (enableFadeoff == false)
        return constants::maxAlpha;
    return (constants::maxDist - al::calcDistance(actor, pos2)) / constants::maxDist * constants::maxAlpha;
}

void drawAreaObjGroup(sead::PrimitiveRenderer* renderer, al::AreaObjGroup const* group, bool isDrawSolid, sead::Color4f wire, sead::Color4f solid, sead::Color4f cyl) {
    for (int i = 0; i < group->mAreaCount; ++i) {
        drawAreaObj(renderer, group->mAreas[i], isDrawSolid, wire, solid, cyl);
    }
}

void drawAreaObj(sead::PrimitiveRenderer* renderer, al::AreaObj const* area, bool isDrawSolid, sead::Color4f wire, sead::Color4f solid, sead::Color4f cyl) {
    const char* shapeType;
    al::tryGetAreaObjStringArg(&shapeType, area, "ModelName");

    sead::Vector3f scale = area->mAreaShape->mScale;
    sead::Vector3f pos;
    area->mAreaShape->calcTrans(&pos);
    renderer->setModelMatrix(area->mAreaMtx);

    if (al::isEqualString(shapeType, "AreaCubeBase")) {
        sead::PrimitiveRenderer::CubeArg shapeArea(sead::Vector3f(0.0f, scale.y * 500.0f, 0.0f), scale * 1000.f, wire);
        if (isDrawSolid)
            renderer->drawCube(shapeArea);
        renderer->drawWireCube(shapeArea);
    }
    else if (al::isEqualString(shapeType, "AreaCubeCenter")) {
        sead::PrimitiveRenderer::CubeArg shapeArea(sead::Vector3f(0.0f, 0.0f, 0.0f), scale * 1000.0f, wire);
        if (isDrawSolid)
            renderer->drawCube(shapeArea);
        renderer->drawWireCube(shapeArea);
    }
    else if (al::isEqualString(shapeType, "AreaCubeTop")) {
        sead::PrimitiveRenderer::CubeArg shapeArea(sead::Vector3f(0.0f, -scale.y * 500.0f, 0.0f), scale * 1000.0f, wire);
        if (isDrawSolid)
            renderer->drawCube(shapeArea);
        renderer->drawWireCube(shapeArea);
    }
    else if (al::isEqualString(shapeType, "AreaCylinder")) {
        renderer->drawCylinder32(sead::Vector3f(0.0f, scale.y * 250.0f, 0.0f), scale.x * 500.0f, scale.y * 500.0f, cyl);
    }
    else if (al::isEqualString(shapeType, "AreaCylinderCenter")) {
        renderer->drawCylinder32(sead::Vector3f(0.0f, 0.0f, 0.0f), scale.x * 500.0f, scale.y * 500.0f, cyl);
    }
    else if (al::isEqualString(shapeType, "AreaCylinderTop")) {
        renderer->drawCylinder32(sead::Vector3f(0.0f, -scale.y * 250.0f, 0.0f), scale.x * 500.0f, scale.y * 500.0f, cyl);
    }
    else if (al::isEqualString(shapeType, "AreaSphere")) {
        renderer->drawSphere8x16(sead::Vector3f(0.0f, 0.0f, 0.0f), scale.x * 1000.0f, cyl);
    }
}

void drawWireTriangle(sead::PrimitiveRenderer* renderer, al::Triangle const& tri, sead::Color4f wire, sead::Color4f colorNormal, bool drawNormal) {
    sead::Vector3f v1 = tri.mVerts[0];
    sead::Vector3f v2 = tri.mVerts[1];
    sead::Vector3f v3 = tri.mVerts[2];

    renderer->drawLine(v1, v2, wire);
    renderer->drawLine(v2, v3, wire);
    renderer->drawLine(v3, v1, wire);

    if (drawNormal) {
        sead::Vector3f normal = tri.mFaceNormal * 50;
        sead::Vector3f center = (v1 + v2 + v3) / 3;
        renderer->drawLine(center, center + normal, colorNormal);
    }
}


void drawHitInfo(sead::PrimitiveRenderer* renderer, al::HitInfo const* hitInfo, sead::Color4f wire, sead::Color4f solid) {
    drawWireTriangle(renderer, hitInfo->mTri, wire, {1.0f, 0.5f, 0.0f, 0.8f}, true);

    renderer->drawSphere8x16(hitInfo->vVar1, 20.0f, {0.0f, 1.0f, 0.0f, 0.5f});
    renderer->drawSphere8x16(hitInfo->mCollisionHitPos, 15.0f, {1.0f, 0.0f, 0.0f, 0.5f});
    // renderer->drawSphere8x16(hitInfo->mCollisionMovingReaction, 15.0f, {0.0f, 0.0f, 1.0f, 0.5f});
}


void drawAllCollision(sead::PrimitiveRenderer* renderer, al::LiveActorKit const& liveActorKit) {
    sead::PtrArray<al::LiveActor> actors = liveActorKit.mAllActors->mActors;

    for (int actorIdx = 0; actorIdx < actors.capacity(); actorIdx++) {
        al::LiveActor* actor = actors[actorIdx];
        al::CollisionParts* collisionParts = actor->mCollisionParts;
        if (!collisionParts) continue;

        // iterate through TList too?

        al::KCollisionServer* kCollisionServer = collisionParts->mKCollisionServer;
        al::KCPrismHeader* prismHeader = kCollisionServer->mPrismHeaders[0];
        // prismHeader->
    }
}
