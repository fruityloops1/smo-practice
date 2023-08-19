/**
 * @file GameDataHolder.h
 * @brief Holds scenario / game data.
 */

#pragma once

#include "GameDataFile.h"
#include "GameDataHolderBase.h"
#include "al/message/MessageSystem.h"
#include "game/StageScene/ChangeStageInfo.h"
#include "game/WorldList/WorldList.h"
#include "sead/prim/seadSafeString.h"
#include <sead/container/seadPtrArray.h>

#include <fl/efun.h>

class ChangeStageInfo;
class GameDataFile;

class TempSaveData;
class CapMessageBossData;
class TemporaryScenarioCameraHolder;
class AchievementInfoReader;
class AchievementHolder;
class MapDataHolder;
class QuestInfoHolder;
class GameSequenceInfo;
class GameConfigData;
class UniqObjInfo;

namespace al {
class ActorInitInfo;
}

class GameDataHolder : public al::ISceneObj, public al::IUseMessageSystem // : public GameDataHolderBase
{
public:
    GameDataHolder(al::MessageSystem const *);
    GameDataHolder();

    //virtual ~GameDataHolder();

    //virtual char* getSceneObjName() const;
    //virtual al::MessageSystem* getMessageSystem() const;

    void setPlayingFileId(s32 file);
    void intitalizeData();
    void initialzeDataCommon();
    void resetTempSaveData(bool);
    void initializeDataId(s32);
    void readByamlData(s32, char const *);
    s32 tryFindEmptyFileId() const;
    al::MessageSystem* getMessageSystem() const override;

    virtual const char* getSceneObjName() const override;
    virtual void initAfterPlacementSceneObj(al::ActorInitInfo const&) override;
    virtual void initSceneObj() override;

    bool isRequireSave() const;
    void setRequireSave();
    void setRequireSaveFalse();
    void setRequireSaveFrame();
    void updateRequireSaveFrame();
    bool isInvalidSaveForMoonGet() const;
    void invalidateSaveForMoonGet();
    void validateSaveForMoonGet();
    void setLanguage(char const *);

    void resetLocationName();
    void changeNextStageWithDemoWorldWarp(char const *);
    #if(SMOVER==100)
    void changeNextStage(ChangeStageInfo const*, int);
    #endif
    #if(SMOVER==130)
    VCEFUN(GameDataHolder, 0x004DB060, changeNextStage, EFUN_ARGS(const ChangeStageInfo* info, int something), EFUN_ARGS(info, something));
    #endif
    bool tryChangeNextStageWithWorldWarpHole(char const *);
    #if(SMOVER==100)
    void returnPrevStage();
    #endif
    #if(SMOVER==130)
    VVCEFUN(GameDataHolder, 0x004DB150, returnPrevStage);
    #endif
    char* getNextStageName() const;
    char* getNextStageName(s32 idx) const;
    GameDataFile* getGameDataFile(s32 idx) const;
    // u64 getNextPlayerStartId() const;
    
    #if(SMOVER==100)
    char* getCurrentStageName() const;
    char* getLanguage() const;
    #endif
    #if(SMOVER==130)
    CVEFUN(GameDataHolder, 0x004DB1C0, char*, getCurrentStageName);
    CVEFUN(GameDataHolder, 0x004DB030, char*, getLanguage);
    #endif
    char* tryGetCurrentStageName() const;
    char* getCurrentStageName(s32 idx) const;
    // void setCheckpointId(al::PlacementId const *);
    char* tryGetRestartPointIdString() const;
    void endStage();
    void startStage(char const *, s32);
    // void onObjNoWriteSaveData(al::PlacementId const *);
    // void offObjNoWriteSaveData(al::PlacementId const *);
    // bool isOnObjNoWriteSaveData(al::PlacementId const *) const;
    // void onObjNoWriteSaveDataResetMiniGame(al::PlacementId const*);
    // void offObjNoWriteSaveDataResetMiniGame(al::PlacementId const *);
    // bool isOnObjNoWriteSaveDataResetMiniGame(al::PlacementId const *) const;
    // void onObjNoWriteSaveDataInSameScenario(al::PlacementId const *);
    // bool isOnObjNoWriteSaveDataInSameScenario(al::PlacementId const *) const;
    void writeTempSaveDataToHash(char const *, bool);

    void resetMiniGameData();
    s32 getPlayingFileId() const;

    s32 findUnlockShineNum(bool *, s32) const;
    s32 calcBeforePhaseWorldNumMax(s32) const;
    bool isFindKoopaNext(s32) const;
    bool isBossAttackedHomeNext(s32) const;
    void playScenarioStartCamera(s32);
    bool isPlayAlreadyScenarioStartCamera() const;

    s32 getShineAnimFrame(s32) const;
    s32 getCoinCollectNumMax(s32) const;

    void readFromSaveDataBufferCommonFileOnlyLanguage();


    al::MessageSystem* mMessageSystem;
    GameDataFile** mFiles;
    GameDataFile* mPlayingFile;
    GameDataFile* uVar1;
    int mPlayingFileId;
    unsigned char gap1[0x4];
    void* gap2;
    bool mIsRequireSave;
    int mRequireSaveFrame;
    bool mIsInvalidSaveForMoonGet;
    bool bVar1;
    bool bVar2;
    sead::BufferedSafeString mLanguage;
    unsigned char gap3[0x20];
    ulong mPlayTimeAcrossFile;
    sead::Heap* mHeap;
    void* gap8;
    GameConfigData* mGameConfigData;
    TempSaveData* uVar2;
    TempSaveData* uVar3;
    CapMessageBossData* mCapMessageBossData;
    unsigned char gap9[0x8];
    unsigned char gap10[0x4];
    unsigned char gap11[0x4];
    TemporaryScenarioCameraHolder* mTemporaryScenarioCameraHolder;
    bool* mIsPlayAlreadyScenarioStartCamera;
    sead::PtrArrayImpl mStageLockList;
    sead::PtrArrayImpl arr1;
    sead::PtrArrayImpl mItemListE3;
    sead::PtrArrayImpl mItemCloth;
    sead::PtrArrayImpl mItemCap;
    sead::PtrArrayImpl mItemGift;
    sead::PtrArrayImpl mItemSticker;
    sead::PtrArray<char> mHackObj;
    sead::PtrArrayImpl arr2;
    void* gap12;
    int iVar1;
    AchievementInfoReader* mAchievementInfoReader;
    AchievementHolder* mAchievementHolder;
    WorldList* mWorldList;
    sead::PtrArrayImpl mChangeStageList;
    sead::PtrArrayImpl mExStageList;
    sead::PtrArrayImpl mInvalidOpenMapList;
    sead::PtrArray<sead::BufferedSafeString> mShowHackTutorialList;
    bool* mIsShowBindTutorial;
    MapDataHolder* mMapDataHolder;
    int iVar2;
    void** gap13;
    int* mCoinCollectNumMax;
    int* piVar1;
    void* gap14;
    int iVar3;
    UniqObjInfo* mLocationName;
    bool bVar3;
    unsigned char gap15[0x7];
    bool mIsEnableCheckpointWarp;
    sead::Vector3f mStageMapPlayerPos;
    sead::Vector3f (*mCoinTransForDeadPlayer)[8];
    unsigned char gap17[0x4];
    bool bVar5;
    bool mIsSeparatePlay;
    bool bVar6;
    QuestInfoHolder* mQuestInfoHolder;
    bool bVar7;
    GameSequenceInfo* mGameSequenceInfo;
    void* gap18;
};
