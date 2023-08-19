#pragma once

#include "al/LiveActor/LiveActor.h"
#include <sead/math/seadVector.h>

namespace al {
class WaterSurfaceFinder {
public:
    bool isNearSurface(float) const;

    al::LiveActor* mActor;
    bool mIsNearSurface;
    float mDistBelowSurface;
    sead::Vector3f mSurfacePoint;
    sead::Vector3f vVar2;
    sead::Vector3f vVar3;
};
}
