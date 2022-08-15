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
        #if(SMOVER==100)
        PlayerHitPointData* getPlayerHitPointData() const;
        bool isGotShine(const ShineInfo*) const;
        void setGotShine(const ShineInfo*);
        void addCoin(int amount);
        #endif
        #if(SMOVER==130)
        CEFUN(GameDataFile, 0x004C65F0, s32, getScenarioNo, EFUN_ARGS(int worldId), EFUN_ARGS(worldId));
        CVEFUN(GameDataFile, 0x004C8530, PlayerHitPointData*, getPlayerHitPointData);
        CEFUN(GameDataFile, 0x004C9700, bool, isGotShine, EFUN_ARGS(const ShineInfo* shineInfo), EFUN_ARGS(shineInfo));
        VCEFUN(GameDataFile, 0x004C9880, setGotShine, EFUN_ARGS(const ShineInfo* info), EFUN_ARGS(info));
        VCEFUN(GameDataFile, 0x004CC1C0, addCoin, EFUN_ARGS(int amount), EFUN_ARGS(amount));
        #endif

        #if SMOVER==100
        unsigned char padding_30[0x30];
        sead::FixedSafeString<128> mStartId;
        unsigned char padding_6A8[0x6A8-0xC8];
        GameProgressData *mGameProgressData; // 0x6A8
        spad(gap, 0x340);
        int curWorldId;
        #endif

        #if SMOVER==130
        unsigned char padding_30[0x30];
        sead::FixedSafeString<128> mStartId;
        unsigned char padding_6A8[0x6A8-0xC8];
        GameProgressData *mGameProgressData; // 0x6A8
        undefined padding_9F0[0x1F0];
        PlayerHitPointData* mPlayerHitPointData;
        spad(gap, 0x148);
        int curWorldId;
        #endif
};