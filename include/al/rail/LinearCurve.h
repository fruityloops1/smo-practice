#pragma once

#include <sead/math/seadVector.h>

namespace al {
class LinearCurve {
public:
    LinearCurve();
    void set(sead::Vector3f const&, sead::Vector3f const&);

    void calcPos(sead::Vector3f*, float) const;
    void calcVelocity(sead::Vector3f*, float) const;
    float calcLength(float, float) const;
    float calcCurveParam(float) const;
    float calcNearestParam(sead::Vector3f const&) const;
    float calcNearestLength(float*, sead::Vector3f const&, float) const;
    void calcNearestPos(sead::Vector3f*, sead::Vector3f const&) const;
    void calcStartPos(sead::Vector3f*) const;
    void calcEndPos(sead::Vector3f*) const;

    sead::Vector3f mStartPos;
    sead::Vector3f mVector;
    float mLength;
};
}
