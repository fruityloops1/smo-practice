#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/nerve/NerveExecutor.h"
#include <sead/math/seadVector.h>
#include "al/area/AreaObj.h"

class WorldEndBorderKeeper : public al::NerveExecutor {
public:
    void exeInside(void);
    void exeOutside(void);
    void exePullBack(void);
    void exeWaitBorder(void);
    void reset(void);
    void update(sead::Vector3f const&, sead::Vector3f const&, bool);

    al::LiveActor* mPlayer;
    sead::Vector3f mPlayerTrans;
    sead::Vector3f mPlayerVel;
    bool mIsAirborne;
    al::AreaObj* uVar1;
    sead::Vector3f mBorderPoint; // closest point to the player that's inside the border
    float mOscillateFrame; // goes to 240, only while the player is airborne
    float mDistIntoBorder; // distance travelled into border before it starts to pull you back
    sead::Vector3f mPullVel; // varies sinusoidally by 300 as oscillation does
};
