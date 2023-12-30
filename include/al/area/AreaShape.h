#pragma once

#include "al/hio/HioNode.h"
#include <sead/math/seadBoundBox.h>
#include <sead/math/seadMatrix.h>
#include <sead/math/seadVector.h>

namespace al {

class AreaShape : al::HioNode {
public:
    AreaShape();

    virtual bool isInVolume(sead::Vector3f const&) const;
    virtual bool isInVolumeOffset(sead::Vector3f const&, float) const;
    virtual bool calcNearestEdgePoint(sead::Vector3f*, sead::Vector3f const&) const;
    virtual bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const&, sead::Vector3f const&) const;
    virtual bool calcLocalBoundingBox(sead::BoundBox3f*) const;

    bool calcLocalPos(sead::Vector3f*, sead::Vector3f const &) const;
    bool calcTrans(sead::Vector3f*) const;
    bool calcWorldDir(sead::Vector3f*, sead::Vector3f const &) const;
    bool calcWorldPos(sead::Vector3f*, sead::Vector3f const &) const;
    void setBaseMtxPtr(sead::Matrix34f const *);
    void setScale(sead::Vector3f const &);

    sead::Matrix34f* mBaseMtx;
    sead::Vector3f mScale;

};

class AreaShapeCube : public AreaShape {
private:
    enum OriginType { center, base, top };
public:
    AreaShapeCube(al::AreaShapeCube::OriginType);
    bool isInVolume(sead::Vector3f const &) const override;
    bool isInVolumeOffset(sead::Vector3f const &, float) const override;
    bool calcNearestEdgePoint(sead::Vector3f*, sead::Vector3f const &) const override;
    bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const &, sead::Vector3f const &) const override;
    bool calcLocalBoundingBox(sead::BoundBox3f*) const override;
    bool isInLocalVolume(sead::Vector3f const &) const;

    OriginType mOriginType;
};

class AreaShapeCylinder : public AreaShape {
private:
    enum OriginType { center, base, top };
public:
    AreaShapeCylinder(al::AreaShapeCylinder::OriginType);
    bool isInVolume(sead::Vector3f const &) const override;
    bool isInVolumeOffset(sead::Vector3f const &, float) const override;
    bool calcNearestEdgePoint(sead::Vector3f*, sead::Vector3f const &) const override;
    bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const &, sead::Vector3f const &) const override;
    bool calcLocalBoundingBox(sead::BoundBox3f*) const override;

    OriginType mOriginType;
};

class AreaShapeInfinite : public AreaShape {
public:
    AreaShapeInfinite();
    bool isInVolume(sead::Vector3f const &) const override;
    bool isInVolumeOffset(sead::Vector3f const &, float) const override;
    bool calcNearestEdgePoint(sead::Vector3f*, sead::Vector3f const &) const override;
    bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const &, sead::Vector3f const &) const override;
    bool calcLocalBoundingBox(sead::BoundBox3f*) const override;

};

class AreaShapeOval : public AreaShape {
public:
    AreaShapeOval();
    bool isInVolume(sead::Vector3f const &) const override;
    bool isInVolumeOffset(sead::Vector3f const &, float) const override;
    bool calcNearestEdgePoint(sead::Vector3f*, sead::Vector3f const &) const override;
    bool checkArrowCollision(sead::Vector3f*, sead::Vector3f*, sead::Vector3f const &, sead::Vector3f const &) const override;
    bool calcLocalBoundingBox(sead::BoundBox3f*) const override;

    float fVar1;
    float fVar2;
};

}
