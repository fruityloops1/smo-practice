/**
 * @file GameDataFile.h
 * @brief Holds data for an individual save file.
 */

#pragma once

#include "game/Player/PlayerHitPointData.h"
#include "types.h"
#include "game/StageScene/ChangeStageInfo.h"
#include "GameProgressData.h"

class ChangeStageInfo;
class ShineInfo;
class GameDataFile
{
    public:
        void wearCostume(char const *);
        void wearCap(char const *);
        void changeNextStage(ChangeStageInfo const*, int);
        void setGotShine(const ShineInfo*);
        #if(SMOVER==100)
        PlayerHitPointData* getPlayerHitPointData() const;
        bool isGotShine(const ShineInfo*) const;
        #endif
        #if(SMOVER==130)
        CVEFUN(GameDataFile, 0x004C8530, PlayerHitPointData*, getPlayerHitPointData);
        CEFUN(GameDataFile, 0x004C9880, bool, isGotShine, EFUN_ARGS(const ShineInfo* shineInfo), EFUN_ARGS(shineInfo));
        #endif

        unsigned char padding_6A8[0x6A8];
        GameProgressData *mGameProgressData; // 0x6A8
        undefined padding_9F0[0x340];
        int curWorldId;
};