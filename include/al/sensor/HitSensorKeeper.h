#pragma once

#include "sead/container/seadPtrArray.h"

namespace al {
class HitSensor;

class HitSensorKeeper {
public:
    sead::PtrArray<al::HitSensor> mSensors;
};
}
