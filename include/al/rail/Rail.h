#pragma once

#include "al/actor/Placement.h"
#include <sead/math/seadVector.h>

namespace al {
class RailPart;

class Rail {
public:
    Rail();
    void init(al::PlacementInfo const&);

    void calcPos(sead::Vector3f*, float) const;
    int getIncludedSection(al::RailPart const**, float*, float) const;
    void calcDirection(sead::Vector3f*, float);
    void calcPosDir(sead::Vector3f*, sead::Vector3f*, float) const;
    float getTotalLength() const;
    float getPartLength(int) const;
    float getLengthToPoint(int) const;
    void calcRailPointPos(sead::Vector3f*, int) const;
    void calcNearestRailPointPosFast(sead::Vector3f*, unsigned int*, sead::Vector3f const&) const;
    void calcNearestRailPointNo(int*, sead::Vector3f const&) const;
    void calcNearestRailPointPos(sead::Vector3f*, sead::Vector3f const&) const;
    float normalizeLength(float) const;
    float calcNearestRailPosCoord(sead::Vector3f const&, float) const;
    float calcNearestRailPosCoord(sead::Vector3f const&, float, float*) const;
    void calcNearestRailPos(sead::Vector3f*, sead::Vector3f const&, float) const;
    bool isNearRailPoint(float, float) const;
    int calcRailPointNum(float, float) const;
    void getIncludedSectionLength(float*, float*, float) const;
    int getIncludedSectionIndex(float) const;
    bool isIncludeBezierRailPart() const;
    bool isBezierRailPart(int) const;

    al::PlacementInfo** mPlacementInfos;
    al::RailPart* mParts;
    int mPartCount;
    int mNumPoints;
    bool mIsClosed;
};
}
