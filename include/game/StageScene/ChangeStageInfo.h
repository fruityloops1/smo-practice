#pragma once

#include "al/actor/Placement.h"
#include "game/GameData/GameDataHolder.h"
#include "sead/prim/seadSafeString.h"

#include <fl/efun.h>

class GameDataHolder;
class ChangeStageInfo
{
public:
    struct SubScenarioType
    {
        u32 type;
    };
    ChangeStageInfo(const GameDataHolder*, const al::PlacementInfo&);
    ChangeStageInfo(const GameDataHolder*, const al::PlacementInfo&, const char* entranceName, const char* stageName, bool, int scenario, ChangeStageInfo::SubScenarioType);
    #if(SMOVER==100)
    ChangeStageInfo(const GameDataHolder*, const char* entranceName, const char* stageName, bool, int scenario, ChangeStageInfo::SubScenarioType);
    #endif
    #if(SMOVER==130)
    VCEFUN_CTOR(ChangeStageInfo, 0x0021C040, EFUN_ARGS(const GameDataHolder* holder, const char* entranceName, const char* stageName, bool something, int scenario, ChangeStageInfo::SubScenarioType subScenarioType), EFUN_ARGS(holder, entranceName, stageName, something, scenario, subScenarioType));
    #endif

    void copy(const ChangeStageInfo&);
    s32 findScenarioNoByList(const GameDataHolder*); // return type(?)
    void init();
    void init(const al::PlacementInfo&, const GameDataHolder*);
    bool isSubScenarioTypeLifeRecover() const;
    bool isSubScenarioTypeResetMiniGame() const;
    void setWipeType(const char* type);
private:
    #if(SMOVER==100)
    sead::FixedSafeString<128> mStageEntranceName;
    sead::FixedSafeString<128> mStageName;
    sead::FixedSafeString<128> mUnkStr;
    bool mUnkBool;
    spad(pad, 0x3);
    s32 mScenario;
    SubScenarioType mSubScenarioType;
    sead::FixedSafeString<128> mWipeType;
    s32 mUnkInt;
    spad(unk, 0x4);
    #endif
};

#if(SMOVER==100)
static_assert(sizeof(ChangeStageInfo) == 0x278);
#endif