#pragma once

#include <sead/math/seadMatrix.h>
#include <sead/math/seadVector.h>
#include "al/LiveActor/LiveActor.h"
#include "al/sensor/SensorHitGroup.h"

namespace al {
    class LiveActor;
class HitSensor {
public:
    HitSensor(al::LiveActor*, const char*, unsigned int, float, unsigned short,
              const sead::Vector3<float>*, const sead::Matrix34<float>*,
              const sead::Vector3<float>&);

    bool trySensorSort();
    void setFollowPosPtr(const sead::Vector3<float>*);
    void setFollowMtxPtr(const sead::Matrix34<float>*);
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();
    void update();
    void addHitSensor(al::HitSensor*);

    const char* mName;
    unsigned int mType;
    sead::Vector3f vVar1;
    float mRadius;
    unsigned short mMaxSensorCount;
    unsigned short mSensorCount;
    al::HitSensor** mSensors;
    unsigned long _28;
    al::SensorHitGroup* mHitGroup;
    bool mIsValidBySystem;
    bool mIsValid;
    al::LiveActor* mHost;
    const sead::Vector3<float>* mFollowPos;
    const sead::Matrix34<float>* mFollowMtx;
    sead::Vector3f vVar2;
};
};  // namespace al
