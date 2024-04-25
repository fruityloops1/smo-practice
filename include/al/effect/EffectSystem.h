#pragma once

#include "al/effect/EffectSystemInfo.h"
#include <sead/heap/seadHeap.h>

namespace al {
class EffectSystem {
public:
    sead::Heap* mHeap;
    al::EffectSystemInfo mEffectSystemInfo;
};
}
