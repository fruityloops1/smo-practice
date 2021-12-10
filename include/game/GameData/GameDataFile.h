/**
 * @file GameDataFile.h
 * @brief Holds data for an individual save file.
 */

#pragma once

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
        bool isGotShine(const ShineInfo*) const;

        unsigned char padding_6A8[0x6A8];
        GameProgressData *mGameProgressData; // 0x6A8
        undefined padding_9F0[0x340];
        int curWorldId;
};