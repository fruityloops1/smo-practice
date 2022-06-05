/**
 * @file GameDataFunction.h
 * @brief Holds static functions for getting / storage save data.
 */

#pragma once

#include <al/LiveActor/LiveActor.h>
#include <game/StageScene/ChangeStageInfo.h>
#include "GameDataHolderAccessor.h"
#include "GameDataHolderWriter.h"
#include "GameDataHolder.h"
#include "game/GameData/GameDataFile.h"

#include <fl/efun.h>

class GameDataFunction
{
public:
    // Gets the required number of moons required to leave a kingdom
    #if(SMOVER==100)
    static s32 getCurrentShineNum(GameDataHolderAccessor);
    static s32 getTotalShineNum(GameDataHolderAccessor, int);
	static s32 findUnlockShineNumByWorldId(bool *, GameDataHolderAccessor, int);
    #endif
    #if(SMOVER==130)
    static WEFUN(0x004D3C60, s32, getCurrentShineNum, EFUN_ARGS(GameDataHolderAccessor *accessor), EFUN_ARGS(accessor));
	static WEFUN(0x004D4490, s32, getTotalShineNum, EFUN_ARGS(GameDataHolderAccessor *accessor, int something), EFUN_ARGS(accessor, something));
	static WEFUN(0x004D53C0, s32, findUnlockShineNumByWorldId, EFUN_ARGS(bool *something, GameDataHolderAccessor *accessor, int something2), EFUN_ARGS(something, accessor, something2));
    #endif
    // gets prev save file's current world id
    static s32 getPrevWorldId(GameDataHolderAccessor);
    // gets current save file's current world id
    // gets next save file's current world id
    static s32 getNextWorldId(GameDataHolderAccessor);


    static s32 calcNextScenarioNo(GameDataHolderAccessor);
    // gets total moons collected on a specified save file (-1 for current save)
    // gets the total amount of moons available in a kingdom
    static s32 getWorldTotalShineNum(GameDataHolderAccessor, int);

    #if(SMOVER==100)
    // gets the current scenario No of the specified kingdom
    static s32 getWorldScenarioNo(GameDataHolderAccessor, int);
    static s32 getCurrentWorldId(GameDataHolderAccessor); // 0x004d2de0
    static char* getCurrentStageName(GameDataHolderAccessor);
    #endif
    #if(SMOVER==130)
    static WEFUN(0x004D2DE0, s32, getCurrentWorldId, EFUN_ARGS(GameDataHolderAccessor *accessor), EFUN_ARGS(accessor));
    static WEFUN(0x004DB1C0, char*, getCurrentStageName, EFUN_ARGS(GameDataHolderAccessor *accessor), EFUN_ARGS(accessor));
    #endif

    static char* getMainStageName(GameDataHolderAccessor, int);

    static char* getNextStageName(GameDataHolderAccessor);

    // checks save file if shine is collected in kingdom index
    static bool isGotShine(GameDataHolderAccessor, int, int);

    // checks save file if shine is collected by shine index only (0 through 725)
    static bool isGotShine(GameDataHolderAccessor, int);

    static bool isGotShine(GameDataHolderAccessor, ShineInfo const*);

    // checks if current stage is a main stage
    static bool isMainStage(GameDataHolderAccessor);

    // Gets Index for X Kingdom
    static s32 getWorldIndexWaterfall(void);
    static s32 getWorldIndexMoon(void);

    // gets the current level of the Odyssey
    static s32 getHomeLevel(GameDataHolderAccessor);

    // enables cappy if not enabled already
    static void enableCap(GameDataHolderWriter);
    #if(SMOVER==100)
    static void disableCapByPlacement(al::LiveActor const*);
    static void missAndRestartStage(GameDataHolderWriter);
    static void recoveryPlayer(al::LiveActor* player);
    static void getLifeMaxUpItem(al::LiveActor* player);
    #endif
    #if(SMOVER==130)
    static WEFUN(0x004D80F0, void, disableCapByPlacement, EFUN_ARGS(al::LiveActor* actor), EFUN_ARGS(actor));
    static WEFUN(0x004D3050, void, missAndRestartStage, EFUN_ARGS(GameDataHolderWriter writer), EFUN_ARGS(writer));
    static WEFUN(0x004D3990, void, recoveryPlayer, EFUN_ARGS(al::LiveActor* player), EFUN_ARGS(player));
    static WEFUN(0x004D38A0, void, getLifeMaxUpItem, EFUN_ARGS(al::LiveActor* player), EFUN_ARGS(player));
    #endif

    // kills the player
    static void killPlayer(GameDataHolderWriter);

    // upgrades the odyssey
    static void upHomeLevel(GameDataHolderWriter);

    //unlocks a kingdom based off index
    static void unlockWorld(GameDataHolderWriter, int);
    //sets the scenario of the specified kingdom
    static void setMainScenarioNo(GameDataHolderWriter, int scenarioNo);

    // checks if odyssey is/needs a repair
    static bool isRepairHome(GameDataHolderAccessor);
    static void repairHome(GameDataHolderWriter);

    // checks if odyssey is crashed
    static bool isCrashHome(GameDataHolderAccessor);
    static void crashHome(GameDataHolderWriter);

    // checks if odyssey is activated 
    static bool isActivateHome(GameDataHolderAccessor);
    static void activateHome(GameDataHolderWriter);

    // checks if the odyssey has launched for the first time.
    static bool isLaunchHome(GameDataHolderAccessor);
    static void launchHome(GameDataHolderWriter);

    static bool isHomeShipStage(GameDataHolder const *);

    // used during the event that enables the odyssey to be used (enables the globe for the odyssey)
    static void talkCapNearHomeInWaterfall(al::LiveActor const*);

    static void tryChangeNextStage(GameDataHolderWriter, ChangeStageInfo const*);
    static GameDataFile* getGameDataFile(GameDataHolderWriter);
    static void tryChangeNextStageWithStartRaceFlag(GameDataHolderWriter, ChangeStageInfo const*);
    static void tryChangeNextStageWithDemoWorldWarp(GameDataHolderWriter, char const*);
    static void changeNextStageWithCloset(GameDataHolderWriter);

    #if(SMOVER==100)
    static int getPlayTimeTotal(GameDataHolderAccessor);
    static int getPlayTimeAcrossFile(GameDataHolderAccessor);
    #endif
    #if(SMOVER==130)
    static WEFUN(0x004D2C10, int, getPlayTimeTotal, EFUN_ARGS(GameDataHolderAccessor accessor), EFUN_ARGS(accessor));
    static WEFUN(0x004D2C20, int, getPlayTimeAcrossFile, EFUN_ARGS(GameDataHolderAccessor accessor), EFUN_ARGS(accessor));
    #endif
};