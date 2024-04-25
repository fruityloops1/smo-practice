#pragma once

#include <sead/math/seadVector.h>

namespace al {
class BezierCurve {
public:
    BezierCurve();
    void set(sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);

    float calcLength(float, float, int) const;
    void calcPos(sead::Vector3f*, float) const;
    void calcVelocity(sead::Vector3f*, float) const;
    float calcDeltaLength(float) const;
    float calcCurveParam(float) const;
    float calcNearestParam(sead::Vector3f const&) const;
    float calcNearestLength(float*, sead::Vector3f const&, float) const;
    void calcNearestPos(sead::Vector3f*, sead::Vector3f const&) const;
    void calcStartPos(sead::Vector3f*) const;
    void calcCtrlPos1(sead::Vector3f*) const;
    void calcCtrlPos2(sead::Vector3f*) const;
    void calcEndPos(sead::Vector3f*) const;

    sead::Vector3f mStartPos;
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    sead::Vector3f vVar3;
    float mLength;
};
}
