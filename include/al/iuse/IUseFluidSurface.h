#pragma once

#include <sead/math/seadVector.h>

namespace al {
class IUseFluidSurface {
public:
    virtual bool calcIsInArea(sead::Vector3f const&) const = 0;
    virtual void calcPos(sead::Vector3f*, sead::Vector3f const&) const = 0;
    virtual void calcPosFlat(sead::Vector3f*, sead::Vector3f const&) const = 0;
    virtual void calcDisplacementPos(sead::Vector3f*, sead::Vector3f const&) const = 0;
    virtual void calcNormal(sead::Vector3f*, sead::Vector3f const&) const = 0;
    virtual bool tryAddRipple(sead::Vector3f const&, float, float) = 0;
    virtual bool tryAddRippleWithRange(sead::Vector3f const&, float, float, float, float) = 0;
    virtual bool tryAddQuadRipple(sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, float) = 0;
    virtual const char* getTypeName() const = 0;
    virtual void setFieldScale(float) = 0;
};
}
