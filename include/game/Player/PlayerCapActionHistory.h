#pragma once

#include "al/LiveActor/LiveActor.h"
#include "game/Player/PlayerConst.h"
#include "game/Player/PlayerTrigger.h"


class IUsePlayerCollision;


class PlayerCounterAfterCapCatch {
public:
    bool isCapCatch(void);
    void update(PlayerTrigger *);

    PlayerConst* mPlayerConst;
    PlayerTrigger* mPlayerTrigger;
    int mCapCatch;
};

class PlayerCapActionHistory {
public:
    void clearCapJump(void);
    void clearLandLimit(void);
    void clearLandLimitStandAngle(void);
    void clearLimitHeight(void);
    void clearWallAirLimit(void);
    bool isOverLimitHeight(void);
    void recordLimitHeight(void);
    void update(void);

    al::LiveActor* mPlayer;
    PlayerConst* mPlayerConst;
    PlayerTrigger* mPlayerTrigger;
    IUsePlayerCollision* mPlayerCollider;
    PlayerCounterAfterCapCatch* mCounterCapCatch;
    bool mLimitHeight = false;
    sead::Vector3f mCapThrowPos;
    bool mCapJump = true;
    bool mRainbowSpin = true;
};
