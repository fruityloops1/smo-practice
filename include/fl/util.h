#pragma once

#include "sead/math/seadQuat.h"
#include "sead/math/seadVector.h"

#define RAD(deg) (deg * (M_PI / 180))
#define DEG(rad) (rad * (180 / M_PI))

namespace fl
{
    sead::Vector3f QuatToEuler(sead::Quatf *quat);
}