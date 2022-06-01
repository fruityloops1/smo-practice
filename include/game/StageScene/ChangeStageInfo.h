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
    #if(SMOVER==100)
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
    #endif
    #if(SMOVER==130)
    VCEFUN_CTOR(ChangeStageInfo, 0x0021BA10, EFUN_ARGS(const GameDataHolder* holder, const al::PlacementInfo& placementInfo), EFUN_ARGS(holder, placementInfo));
    VCEFUN_CTOR(ChangeStageInfo, 0x0021BDD0, EFUN_ARGS(const GameDataHolder* holder, const al::PlacementInfo& placementInfo, const char* entranceName, const char* stageName, bool something, int scenario, ChangeStageInfo::SubScenarioType subScenarioType), EFUN_ARGS(holder, placementInfo, entranceName, stageName, something, scenario, subScenarioType));
    VCEFUN_CTOR(ChangeStageInfo, 0x0021C040, EFUN_ARGS(const GameDataHolder* holder, const char* entranceName, const char* stageName, bool something, int scenario, ChangeStageInfo::SubScenarioType subScenarioType), EFUN_ARGS(holder, entranceName, stageName, something, scenario, subScenarioType));
    VCEFUN(ChangeStageInfo, 0x0021C240, copy, EFUN_ARGS(const ChangeStageInfo &info), EFUN_ARGS(info));
    s32 findScenarioNoByList(const GameDataHolder*); // Haven't been able to find the address of the v1.3.0 equivalent.
    VVCEFUN(ChangeStageInfo, 0x0021C1D0, init);
    VCEFUN(ChangeStageInfo, 0x0021BB20, init, EFUN_ARGS(const al::PlacementInfo& placementInfo, const GameDataHolder* holder), EFUN_ARGS(placementInfo, holder));
    CVEFUN(ChangeStageInfo, 0x0021C580, bool, isSubScenarioTypeLifeRecover);
    CVEFUN(ChangeStageInfo, 0x0021C5A0, bool, isSubScenarioTypeResetMiniGame);
    VCEFUN(ChangeStageInfo, 0x0021C5C0, setWipeType, EFUN_ARGS(const char* type), EFUN_ARGS(type));
    #endif
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
    #if(SMOVER==130)
    spad(padding, 0x278);
    #endif
};

static_assert(sizeof(ChangeStageInfo) == 0x278);