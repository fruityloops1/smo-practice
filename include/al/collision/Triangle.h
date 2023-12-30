#pragma once

#include "al/byaml/ByamlIter.h"
#include "al/collision/KCPrism.h"
#include <sead/math/seadMatrix.h>
#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>

namespace al {
class CollisionParts;
class LiveActor;
class HitSensor;

class Triangle {
public:
    Triangle();
    Triangle(al::CollisionParts const&, al::KCPrismData const*, al::KCPrismHeader const*);

    sead::Vector3f* calcAndGetEdgeNormal(int);
    sead::Vector3f* calcAndGetFaceNormal();
    sead::Vector3f* calcAndGetNormal(int);
    sead::Vector3f* calcAndGetPos(int);
    void calcCenterPos(sead::Vector3f*) const;
    void calcForceMovePower(sead::Vector3f*, sead::Vector3f const&) const;
    void calcForceRotatePower(sead::Quatf*) const;
    void fill(sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);
    void fillData(al::CollisionParts const&, al::KCPrismData const*, al::KCPrismHeader const*);
    bool getAttributes(al::ByamlIter*) const;
    sead::Matrix34f* getBaseInvMtx() const;
    sead::Matrix34f* getBaseMtx() const;
    sead::Vector3f* getEdgeNormal(int) const;
    sead::Vector3f* getFaceNormal() const;
    al::LiveActor* getHostActor() const;
    void getLocalPos(sead::Vector3f*, int) const;
    sead::Vector3f* getNormal(int) const;
    sead::Vector3f* getPos(int) const;
    sead::Matrix34f* getPrevBaseMtx() const;
    al::HitSensor* getSensor() const;
    bool isHostMoved() const;
    bool isValid() const;

    al::CollisionParts* mCollisionParts;
    al::KCPrismData* mKCPrismData;
    al::KCPrismHeader* mKCPrismHeader;
    sead::Vector3f mFaceNormal;
    sead::Vector3f mEdgeNormals[3];
    sead::Vector3f mVerts[3];
};
}
