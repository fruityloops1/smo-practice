#pragma once

#include "al/actor/Placement.h"
#include "game/GameData/GameDataHolder.h"
#include "sead/prim/seadSafeString.h"

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
    ChangeStageInfo(const GameDataHolder*, const char* entranceName, const char* stageName, bool, int scenario, ChangeStageInfo::SubScenarioType);

    void copy(const ChangeStageInfo&);
    s32 findScenarioNoByList(const GameDataHolder*); // return type(?)
    void init();
    void init(const al::PlacementInfo&, const GameDataHolder*);
    bool isSubScenarioTypeLifeRecover() const;
    bool isSubScenarioTypeResetMiniGame() const;
    void setWipeType(const char* type);
private:
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
};

static_assert(sizeof(ChangeStageInfo) == 0x278);