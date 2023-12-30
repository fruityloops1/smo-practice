#pragma once

#include "al/hio/HioNode.h"
#include "types.h"

class PlayerConst : al::HioNode {
public:
    int getWallInhibitAfterPunch() const;
    float getWallHeightLowLimit() const;
    float getWallKeepDegree() const;
    float getWallCatchDegree() const;
    float getWallCatchHeightEdgeTop() const;
    float getWallCatchHeightBottom() const;
    float getCollisionRadius() const;
    float getCollisionRadiusStand() const;

};
