/**
 * @file PlayerHackKeeper.h
 * @brief Contains info on the current hack (capture)
 */

#pragma once

#include <al/LiveActor/LiveActor.h>

class PlayerHackKeeper
{
    public:
        const char* getCurrentHackName() const;

        char padding[0x68];
        al::LiveActor *mCurrentHackActor;
};
