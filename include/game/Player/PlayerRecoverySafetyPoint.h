#pragma once

#include "sead/math/seadVector.h"
#include <fl/efun.h>

class PlayerRecoverySafetyPoint {
    public:
        #if(SMOVER==100)
        sead::Vector3f *getSafetyPoint(void) const;
        #endif
        #if(SMOVER==130)
        CVEFUN(PlayerRecoverySafetyPoint, 0x00403AF0, sead::Vector3f*, getSafetyPoint);
        #endif
        sead::Vector3f *getSafetyPointGravity(void) const;
        sead::Vector3f *getSafetyPointArea(void) const;
};