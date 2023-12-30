#pragma once

#include "al/iuse/IUseFluidSurface.h"
#include <sead/container/seadPtrArray.h>

namespace al {
class FluidSurfaceHolder {
public:
    bool calcIsInFluid(sead::Vector3f const&, const char*);

    sead::PtrArray<al::IUseFluidSurface> mSurfaces;
    al::IUseFluidSurface* uVar1;
    float fVar1;
};
}
