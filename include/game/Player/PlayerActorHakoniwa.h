#pragma once
/**
 * @file PlayerActorBase.h
 * @brief Main Class for the PlayerActor (Mario)
 * Player Pose: TQGMSV
*  Vtable loc: 1D780C0
*/

#include "PlayerActorBase.h"
#include "game/Interfaces/IUseDimension.h"
#include "PlayerInput.h"
#include "PlayerAnimator.h"
#include "HackCap.h"
#include "PlayerModelKeeper.h"
#include "PlayerRecoverySafetyPoint.h"
#include "game/Player/PlayerDamageKeeper.h"
#include "game/Player/PlayerHackKeeper.h"

#define PACTORSIZE 0xC8

class PlayerActorHakoniwa : public PlayerActorBase , public IUseDimension {
    public: 
        int *getPortNo(void) const;
        void startDemoMainShineGet();
        void endDemoMainShineGet();
        void startDemoPuppetable();
        void endDemoPuppetable();
        void startDemoShineGet();
        void tryActionStartSpinAttack();
        unsigned char padding_E8[0xE8 - PACTORSIZE];
        int portNo; // 0xE8
        unsigned char padding_138[0x48];
        PlayerInput *mPlayerInput; //0x138 
        unsigned char padding_148[0x08];
        HackCap *mHackCap; // 0x148
        unsigned char padding_158[0x06];
        PlayerModelKeeper *mPlayerModelKeeper; // 0x158
        unsigned char padding_168[0x08];
        PlayerAnimator *mPlayerAnimator; // 0x168
        undefined padding_270[0x28];
        PlayerDamageKeeper* mDamageKeeper;
        spad(gap, 0x68);
        PlayerHackKeeper* mHackKeeper;
        spad(gap2, 0x5F);
        PlayerRecoverySafetyPoint *mPlayerRecoverPoint; // 0x270
};