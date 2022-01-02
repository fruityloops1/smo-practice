#include "al/LiveActor/LiveActor.h"
#include "game/GameData/GameDataFunction.h"
#include "rs/util.hpp"

#include <fl/common.h>
#include <fl/server.h>
#include <fl/input.h>
#include <fl/tas.h>
#include <fl/ui.h>
#include <fl/util.h>
#include <str.h>

const char* stageNames[] = {"CapWorldHomeStage", "WaterfallWorldHomeStage", "SandWorldHomeStage", "LakeWorldHomeStage", "ForestWorldHomeStage", "CloudWorldHomeStage", "ClashWorldHomeStage", "CityWorldHomeStage",
                            "SnowWorldHomeStage", "SeaWorldHomeStage", "LavaWorldHomeStage", "BossRaidWorldHomeStage", "SkyWorldHomeStage", "MoonWorldHomeStage", "PeachWorldHomeStage", "Special1WorldHomeStage", "Special2WorldHomeStage", "MoonWorldBasementStage", "MoonWorldKoopa1Stage", "MoonWorldKoopa2Stage", "DotTowerExStage", "Special2WorldLavaStage", "FrogSearchExStage", "Cube2DExStage", "SandWorldPyramid001Stage", "SeaWorldSecretStage", "CapAppearExStage", "ForestWorldWaterExStage", "PeachWorldShopStage", "SkyWorldTreasureStage", "SnowWorldRaceExStage", "PushBlockExStage", "ShootingCityYoshiExStage", "SnowWorldLobbyExStage", "DemoChangeWorldFindKoopaShipStage", "DonsukeExStage", "BullRunExStage", "DemoBossRaidAttackStage", "PeachWorldPictureGiantWanderBossStage", "CityWorldShop01Stage", "PackunPoisonNoCapExStage", "RevengeBossKnuckleStage", "SenobiTowerYoshiExStage", "SnowWorldShopStage", "Theater2DExStage", "LavaWorldBubbleLaneExStage", "DemoChangeWorldBossRaidAttackStage", "Special1WorldTowerStackerStage", "Special1WorldTowerFireBlowerStage", "SandWorldCostumeStage", "LavaWorldFenceLiftExStage", "ForestWorldBossStage", "BikeSteelExStage", "FastenerExStage", "SandWorldRotateExStage", "SeaWorldSneakingManStage", "TrexBikeExStage", "SnowWorldRaceHardExStage", "SandWorldPressExStage", "DemoCrashHomeStage", "WaterValleyExStage", "CapWorldTowerStage", "KillerRailCollisionExStage", "ByugoPuzzleExStage", "CityWorldFactoryStage", "Special2WorldKoopaStage", "SandWorldUnderground001Stage", "IceWaterBlockExStage", "PackunPoisonExStage", "DemoEndingStage", "DotHardExStage", "SenobiTowerExStage", "GabuzouClockExStage", "PeachWorldPictureBossMagmaStage", "ClashWorldShopStage", "SeaWorldCostumeStage", "DemoCrashHomeFallStage", "MoonWorldSphinxRoom", "SandWorldUnderground000Stage", "ShootingCityExStage", "PeachWorldPictureBossRaidStage", "RailCollisionExStage", "RevengeBossRaidStage", "LavaWorldTreasureStage", "Special2WorldCloudStage", "DemoWorldMoveForwardArriveStage", "MoonWorldWeddingRoomStage", "SeaWorldVibrationStage", "DemoWorldMoveMoonForwardStage", "ForestWorldWoodsTreasureStage", "ForestWorldWoodsStage", "ForestWorldCloudBonusExStage", "PeachWorldPictureMofumofuStage", "CapRotatePackunExStage", "GotogotonExStage", "IceWalkerExStage", "PeachWorldPictureBossKnuckleStage", "RevengeBossMagmaStage", "ForestWorldTowerStage", "DemoStartWorldWaterfallStage", "PeachWorldCastleStage", "SkyWorldCostumeStage", "DemoWorldMoveMoonForwardFirstStage", "SkyWorldShopStage", "SnowWorldTownStage", "DemoLavaWorldScenario1EndStage", "RevengeGiantWanderBossStage", "SandWorldSphinxExStage", "DemoWorldMoveMoonBackwardStage", "SnowWorldRace000Stage", "SnowWorldCostumeStage", "BikeSteelNoCapExStage", "CapAppearLavaLiftExStage", "DemoHackKoopaStage", "RadioControlExStage", "TrexPoppunExStage", "TsukkunClimbExStage", "LavaWorldShopStage", "SandWorldSecretStage", "FukuwaraiKuriboStage", "ForkExStage", "JangoExStage", "DemoOpeningStage", "LakeWorldShopStage", "PoleGrabCeilExStage", "PoisonWaveExStage", "DemoWorldWarpHoleStage", "SandWorldVibrationStage", "LavaWorldClockExStage", "FukuwaraiMarioStage", "HomeShipInsideStage", "ImomuPoisonExStage", "CityWorldMainTowerStage", "SnowWorldRaceTutorialStage", "WorldStage", "SandWorldSlotStage", "RollingExStage", "SnowWorldRace001Stage", "SnowWorldLobby000Stage", "MoonWorldWeddingRoom2Stage", "LavaWorldUpDownExStage", "RevengeForestBossStage", "AnimalChaseExStage", "SeaWorldUtsuboCaveStage", "DemoTakeOffKoopaForMoonStage", "MoonWorldCaptureParadeStage", "LavaWorldCostumeStage", "Lift2DExStage", "Special1WorldTowerBombTailStage", "MoonWorldShopRoom", "SnowWorldCloudBonusExStage", "TogezoRotateExStage", "FrogPoisonExStage", "SkyWorldCloudBonusExStage", "KaronWingTowerStage", "WanwanClashExStage", "WaterTubeExStage", "DemoMeetCapNpcSubStage", "MoonAthleticExStage", "CloudExStage", "DemoHackFirstStage", "PeachWorldPictureBossForestStage", "ShootingElevatorExStage", "PeachWorldCostumeStage", "MeganeLiftExStage", "TrampolineWallCatchExStage", "CityWorldSandSlotStage", "ForestWorldBonusStage", "SwingSteelExStage", "TsukkunRotateExStage", "RocketFlowerExStage", "WindBlowExStage", "ForestWorldWoodsCostumeStage", "ElectricWireExStage", "DemoWorldMoveBackwardArriveStage", "Galaxy2DExStage", "IceWaterDashExStage", "ReflectBombExStage", "LavaWorldUpDownYoshiExStage", "JizoSwitchExStage", "RevengeMofumofuStage", "SnowWorldLobby001Stage", "YoshiCloudExStage", "KillerRoadExStage", "CityPeopleRoadStage", "Note2D3DRoomExStage", "DemoWorldMoveBackwardStage", "KillerRoadNoCapExStage", "DemoWorldMoveForwardStage", "SandWorldMeganeExStage", "LavaWorldExcavationExStage", "Special1WorldTowerCapThrowerStage", "DemoChangeWorldStage", "FogMountainExStage", "SandWorldPyramid000Stage", "SandWorldShopStage", "SandWorldKillerExStage", "PoleKillerExStage", "DemoWorldMoveForwardFirstStage", "StaffRollMoonRockDemo"};

#if(SMOVER==100)
#define printf(FORMAT, ...) p.printf(FORMAT, ##__VA_ARGS__);
#endif
#if(SMOVER==130)
#define printf(FORMAT, ...) {sprintfRv = sprintf(textBuffer + printPos, FORMAT, ##__VA_ARGS__); printPos += sprintfRv;}
#endif


#define NUM_PAGES 9
#define NUM_STAGES 200

#if(SMOVER==100)
#define CURSOR(LINE) printf(curLine == LINE ? ">" : "")
#endif
#if(SMOVER==130)
#define CURSOR(LINE) printf(curLine == LINE ? "·" : "")
#endif
#define CHANGE_PAGE() printf("Change Page (%d/%d)\n", +curPage + 1, NUM_PAGES)

// Sets max amount of lines for a page
#define MAX_LINE(LINE) if (curLine > LINE) curLine = 0;

#define TOGGLE(FORMAT, BOOL, LINE) CURSOR(LINE);\
                                   printf(FORMAT, BOOL ? "Enabled" : "Disabled");\
                                   if (inputEnabled && !nextFrameNoLeftInput && curLine == LINE && (al::isPadTriggerLeft(CONTROLLER_AUTO) || al::isPadTriggerRight(CONTROLLER_AUTO))) BOOL = !BOOL;

#define TRIGGER(NAME, LINE, ACTION) CURSOR(LINE);\
                              printf(NAME);\
                              if (inputEnabled && curLine == LINE && al::isPadTriggerRight(CONTROLLER_AUTO)) {ACTION;}

void fl::PracticeUI::savePosition(PlayerActorHakoniwa& player)
{
    savedTrans = *al::getTrans(&player);
    savedQuat = *al::getQuat(&player);
    saved = true;
}

void fl::PracticeUI::loadPosition(PlayerActorHakoniwa& player)
{
    al::LiveActor* move = &player;
    al::LiveActor* hack = player.mHackKeeper->currentHackActor;

    if (hack) move = hack;

    if (!hack) player.startDemoPuppetable();
    else al::offCollide(hack);

    al::setTrans(move, savedTrans);
    if (!hack) al::updatePoseQuat(move, savedQuat);
    al::setVelocityZero(move);

    if (!hack) player.endDemoPuppetable();
    else al::onCollide(hack);
}

void fl::PracticeUI::update(StageScene& stageScene)
{
    this->stageScene = &stageScene;
    isInGame = true;

    PlayerActorHakoniwa* player = rs::getPlayerActor(&stageScene);

    bool holdL = al::isPadHoldL(CONTROLLER_AUTO);

    #if SMOVER==100
    fl::TasHolder::instance().update();
    #endif

    if (holdL && al::isPadTriggerRight(CONTROLLER_AUTO)) {inputEnabled = !inputEnabled; return;}
    else if
    #if SMOVER==130
    (holdL && al::isPadTriggerLeft(CONTROLLER_AUTO))
    #endif
    #if SMOVER==100
    (al::isPadTriggerPressLeftStick(CONTROLLER_AUTO))
    #endif
    {
        showMenu = !showMenu;
        #if SMOVER==130
        nextFrameNoLeftInput = true;
        #endif
    }

    if (!showMenu)
    {
        if (teleportEnabled)
        {
            if (al::isPadTriggerLeft(CONTROLLER_AUTO))
                savePosition(*player);

            if (al::isPadTriggerRight(CONTROLLER_AUTO) && saved)
                loadPosition(*player);
        }
    }

    if (hideShineCounter)
        al::hidePane(stageScene.stageSceneLayout->shineCounter, "TxtShine");
    else
        al::showPane(stageScene.stageSceneLayout->shineCounter, "TxtShine");

    #if SMOVER==130
    if (showMenu) menu();
    else al::setPaneStringFormat(stageScene.stageSceneLayout->coinCounter, "TxtDebug", " ");
    #endif
}

#if SMOVER==100
void fl::PracticeUI::menu(sead::TextWriter& p)
#endif
#if SMOVER==130
void fl::PracticeUI::menu()
#endif
{
    #if(SMOVER==130)
    s32 sprintfRv = 0;
    printPos = 0;
    #endif
    if (!stageScene) return;
    if (showMenu)
    {
        enum Page : u8
        {
            About, Options, Stage, Misc, Info, Tas, MoonInfo, Modes, Debug
        };
        static Page curPage = About;
        static u8 curLine = 0;

        PlayerActorHakoniwa* player = rs::getPlayerActor(stageScene);

        if (inputEnabled)
        {
            if (al::isPadTriggerDown(CONTROLLER_AUTO)) curLine++;
            if (al::isPadTriggerUp(CONTROLLER_AUTO)) curLine--;
        }

        if (inputEnabled && curLine == 0)
        {
            if (al::isPadTriggerRight(CONTROLLER_AUTO))
            {
                if (curPage == About) curPage = Options;
                else if (curPage == Options) curPage = Stage;
                else if (curPage == Stage) curPage = Misc;
                else if (curPage == Misc) curPage = Info;
                else if (curPage == Info) curPage = Tas;
                else if (curPage == Tas) curPage = MoonInfo;
                else if (curPage == MoonInfo) curPage = Modes;
                else if (curPage == Modes) curPage = Debug;
                else if (curPage == Debug) curPage = About;
            }
            if (al::isPadTriggerLeft(CONTROLLER_AUTO) && !nextFrameNoLeftInput)
            {
                if (curPage == Options) curPage = About;
                else if (curPage == Stage) curPage = Options;
                else if (curPage == Misc) curPage = Stage;
                else if (curPage == Info) curPage = Misc;
                else if (curPage == Tas) curPage = Info;
                else if (curPage == MoonInfo) curPage = Tas;
                else if (curPage == Modes) curPage = MoonInfo;
                else if (curPage == Debug) curPage = Modes;
                else if (curPage == About) curPage = Debug;
            }
        }

        switch (curPage)
        {
            case About:
            {
                MAX_LINE(0);
                CURSOR(0);
                CHANGE_PAGE();
                printf("Welcome to the Practice Mod!\n");
                printf("Made by Fruityloops#8500 and contributors\n");
                printf("Big thanks to CraftyBoss, bryce_____ and Mars2030!\n");
                break;
            }
            case Options:
            {
                printf("Options\n");
                MAX_LINE(6);
                CURSOR(0);
                CHANGE_PAGE();
                
                TOGGLE("Teleport: %s\n", teleportEnabled, 1);
                TOGGLE("Moon Refresh: %s\n", shineRefresh, 2);
                TOGGLE("Gray Moon Refresh: %s\n", gotShineRefresh, 3);
                TOGGLE("Always Enable Warps: %s\n", alwaysWarp, 4);
                TOGGLE("Disable Autosaving: %s\n", disableAutoSave, 5);
                TOGGLE("Cloud Kingdom Bowser Skip: %s\n", skipBowser, 6);
                break;
            }
            case Stage:
            {
                static u32 currentStage = 0;
                static s8 currentScenario = -1;

                printf("Stages\n");
                #if SMOVER==100
                MAX_LINE(3);
                #endif
                #if SMOVER==130
                MAX_LINE(0);
                #endif
                CURSOR(0);
                CHANGE_PAGE();

                #if SMOVER==100
                CURSOR(1);

                if (inputEnabled && curLine == 1)
                {
                    if (al::isPadTriggerRight(CONTROLLER_AUTO)) currentStage++;
                    if (al::isPadTriggerLeft(CONTROLLER_AUTO) && !nextFrameNoLeftInput)
                    {
                        if (currentStage == 0)
                            currentStage = NUM_STAGES - 1;
                        else
                            currentStage--;
                    }
                }
                else if (inputEnabled && curLine == 2)
                {
                    if (al::isPadTriggerRight(CONTROLLER_AUTO))
                        currentScenario = currentScenario == -1 ? 1 : currentScenario + 1;
                    if (al::isPadTriggerLeft(CONTROLLER_AUTO) && !nextFrameNoLeftInput)
                    {
                        if (currentScenario == -1) currentScenario = 15;
                        else currentScenario--;
                    }
                }

                if (currentScenario < -1 || currentScenario == 0 || currentScenario > 15) currentScenario = -1;

                if (currentStage + 1 > NUM_STAGES) currentStage = 0;
                printf("Stage: %s\n", stageNames[currentStage]);
                CURSOR(2);
                if (currentScenario != -1)  {printf("Scenario: %d\n", +currentScenario);}
                else printf("Scenario: Don't change\n");

                TRIGGER("Go\n", 3, {
                    ChangeStageInfo info = ChangeStageInfo(stageScene->mHolder, "start", stageNames[currentStage], false, currentScenario, {0});
                    stageScene->mHolder->changeNextStage(&info, 0);
                    curLine = 0;
                });
                #endif

                #if SMOVER==130
                printf(MSG_NO130);
                #endif
                break;
            }
            case Misc:
            {
                printf("Miscellaneous\n");
                #if SMOVER==100
                MAX_LINE(8);
                #endif
                #if SMOVER==130
                MAX_LINE(7);
                #endif
                CURSOR(0);
                CHANGE_PAGE();

                TRIGGER("Kill Mario\n", 1, {
                    player->mDamageKeeper->dead();
                    curLine = 0;
                });
                TRIGGER("Damage Mario\n", 2, player->mDamageKeeper->damage(1));
                TRIGGER("Life Up Heart\n", 3, {
                    #if SMOVER==100
                    stageScene->mHolder->mGameDataFile->getPlayerHitPointData()->getMaxUpItem();
                    #endif
                    #if SMOVER==130
                    GameDataFunction::getLifeMaxUpItem(player);
                    #endif
                });
                TRIGGER("Heal Mario\n", 4, {
                    #if SMOVER==100
                    stageScene->mHolder->mGameDataFile->getPlayerHitPointData()->recover();
                    #endif
                    #if SMOVER==130
                    GameDataFunction::recoveryPlayer(player);
                    #endif
                });
                TRIGGER("Remove Cappy\n", 5, GameDataFunction::disableCapByPlacement(player->mHackCap));
                TRIGGER("Invincibility Star\n", 6, player->mDamageKeeper->activatePreventDamage());
                
                static u8 gravity = 0;

                CURSOR(7);

                const char* gravityString = nullptr;

                if (gravity == 0) gravityString = "Down";
                else if (gravity == 1) gravityString = "Up";
                else if (gravity == 2) gravityString = "North";
                else if (gravity == 3) gravityString = "South";
                else if (gravity == 4) gravityString = "East";
                else if (gravity == 5) gravityString = "West";
                
                bool gravityChanged = false;

                printf("Gravity: %s\n", gravityString);
                if (curLine == 7 && inputEnabled && !nextFrameNoLeftInput && al::isPadTriggerLeft(CONTROLLER_AUTO)) {gravity--; gravityChanged = true;}
                else if (curLine == 7 && inputEnabled && al::isPadTriggerRight(CONTROLLER_AUTO)) {gravity++; gravityChanged = true;}
                if (gravity == 255) gravity = 5;
                else if (gravity > 5) gravity = 0;

                if (gravityChanged)
                {
                    if (gravity == 0) al::setGravity(player, {0, -1, 0});
                    else if (gravity == 1) al::setGravity(player, {0, 1, 0});
                    else if (gravity == 2) al::setGravity(player, {1, 0, 0});
                    else if (gravity == 3) al::setGravity(player, {-1, 0, 0});
                    else if (gravity == 4) al::setGravity(player, {0, 0, 1});
                    else if (gravity == 5) al::setGravity(player, {0, 0, -1});
                }

                #if SMOVER==100
                TRIGGER("Reload Stage\n", 8, {
                    #if(SMOVER==100)
                    reloadStageForPos = 0;
                    reloadStagePos = *al::getTrans(player);
                    reloadStageQuat = *al::getQuat(player);
                    ChangeStageInfo info = ChangeStageInfo(stageScene->mHolder, "start", stageScene->mHolder->getCurrentStageName(), false, CURRENT_SCENARIO, {0});
                    stageScene->mHolder->changeNextStage(&info, 0);
                    #endif
                });
                #endif

                break;
            }
            case Info:
            {
                printf("Info\n");
                MAX_LINE(1);
                CURSOR(0);
                CHANGE_PAGE();

                static bool quatRot = false;
                TOGGLE("Quaternion Rotation: %s\n", quatRot, 1);

                sead::Vector3f* playerTrans = al::getTrans(player);
                sead::Vector3f* playerVel = al::getVelocity(player);
                sead::Quatf* playerQuat = al::getQuat(player);
                sead::Vector3f playerEulerAngles = fl::QuatToEuler(playerQuat);
                sead::Vector3f playerRot = sead::Vector3f(DEG(playerEulerAngles.x),DEG(playerEulerAngles.y),DEG(playerEulerAngles.z));
                sead::Vector3f* playerRecoveryPoint = player->mPlayerRecoverPoint->getSafetyPoint();
                sead::Vector3f* cappyPosition = al::getTrans(player->mHackCap);
                sead::Quatf* cappyQuat = al::getQuat(player->mHackCap);
                sead::Vector3f cappyEulerAngles = fl::QuatToEuler(playerQuat);
                sead::Vector3f cappyRot = sead::Vector3f(DEG(playerEulerAngles.x),DEG(playerEulerAngles.y),DEG(playerEulerAngles.z));
                const char* anim = player->mPlayerAnimator->mCurrentAnim;
                float hSpeed = al::calcSpeedH(player), vSpeed = al::calcSpeedV(player), speed = al::calcSpeed(player);

                printf("Player Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerTrans->x, playerTrans->y, playerTrans->z);
                printf("Player Vel: (X: %.3f Y: %.3f Z: %.3f)\n", playerVel->x, playerVel->y, playerVel->z);
                printf("Player Speed: (H: %.3f V: %.3f S: %.3f)\n", hSpeed, vSpeed, speed);
                if (quatRot)
                {
                    printf("Player Rot: (W: %.3f X: %.3f Y: %.3f Z: %.3f)\n", playerQuat->w, playerQuat->x, playerQuat->y, playerQuat->z);
                }
                else
                    printf("Player Rot: (X: %.3f Y: %.3f Z: %.3f)\n", playerRot.x, playerRot.y, playerRot.z);
                printf("Cappy Pos: (X: %.3f Y: %.3f Z: %.3f)\n", cappyPosition->x, cappyPosition->y, cappyPosition->z);
                if (quatRot)
                {
                    printf("Cappy Rot: (W: %.3f X: %.3f Y: %.3f Z: %.3f)\n", cappyQuat->w, cappyQuat->x, cappyQuat->y, cappyQuat->z);
                }
                else
                    printf("Cappy Rot: (X: %.3f Y: %.3f Z: %.3f)\n", cappyRot.x, cappyRot.y, cappyRot.z);
                printf("Bubble Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerRecoveryPoint->x, playerRecoveryPoint->y, playerRecoveryPoint->z);
                printf("Current Animation: %s (%.0f/%.0f)\n", anim, player->mPlayerAnimator->getAnimFrame() - 1.0f, player->mPlayerAnimator->getAnimFrameMax());

                break;
            }
            case Tas:
            {
                printf("TAS\n");
                #if SMOVER==100
                MAX_LINE(3);
                #endif
                #if SMOVER==130
                MAX_LINE(0);
                #endif
                CURSOR(0);
                CHANGE_PAGE();

                #if SMOVER==130
                printf(MSG_NO130);
                #endif

                #if SMOVER==100
                TRIGGER("Connect to server\n", 1, {
                    //smo::Server::instance().connect("someip", 7902);
                });
                TOGGLE("Old Motion Mod: %s\n", fl::TasHolder::instance().oldMotion, 2);

                fl::TasHolder& h = fl::TasHolder::instance();

                if (h.isRunning)  {TRIGGER("Stop Script\n", 3, h.stop());}
                else { TRIGGER("Start Script\n", 3, {
                    if (h.frames) h.start();
                });
                }

                printf("\n");

                if (h.scriptName)
                    printf("Script: %s (%lu frames)\n", h.scriptName, h.frameCount);

                if (h.isRunning)
                    printf("TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
                sead::Vector2f& left = *fgetLeftStick(CONTROLLER_AUTO);
                sead::Vector2f& right = *fgetRightStick(CONTROLLER_AUTO);
                printf("Left Stick: (X: %.5f Y: %.5f)\n", left.x, left.y);
                printf("Right Stick: (X: %.5f Y: %.5f)\n", right.x, right.y);
                printf("Buttons:\n");
                // -1 = CONTROLLER_AUTO
                printf("%s %s %s %s %s %s %s %s\n", fisPadHoldA(-1) ? "A" : " ", fisPadHoldB(-1) ? "B" : " ", fisPadHoldX(-1) ? "X" : " ", fisPadHoldY(-1) ? "Y" : " ", fisPadHoldL(-1) ? "L" : " ", fisPadHoldR(-1) ? "R" : " ", fisPadHoldZL(-1) ? "ZL" : "  ", fisPadHoldZR(-1) ? "ZR" : "  ");
                printf("%s %s %s %s %s %s %s %s\n", fisPadHoldPlus(-1) ? "+" : " ", fisPadHoldMinus(-1) ? "-" : " ", fisPadHoldPressLeftStick(-1) ? "LS" : "  ", fisPadHoldPressRightStick(-1) ? "RS" : "  ", fisPadHoldUp(-1) ? "DUP" : "   ", fisPadHoldRight(-1) ? "DRIGHT" : "      ", fisPadHoldDown(-1) ? "DDOWN" : "     ", fisPadHoldLeft(-1) ? "DLEFT" : "     ");
                #endif
                break;
            }
            case MoonInfo:
            {
                printf("Moon Info\n");
                MAX_LINE(1);
                CURSOR(0);
                CHANGE_PAGE();

                TOGGLE("Hide Original Moon Counter: %s\n", hideShineCounter, 1);

                #if(SMOVER==100)
                s32 currShine = GameDataFunction::getCurrentShineNum(*stageScene->mHolder);
                s32 totalShine = GameDataFunction::getTotalShineNum(*stageScene->mHolder, -1);
                s32 unlockShine = GameDataFunction::findUnlockShineNumByWorldId(0, *stageScene->mHolder, GameDataFunction::getCurrentWorldId(*stageScene->mHolder));
                printf("Current Moons: %d\n", currShine);
                printf("Total Moons: %d\n", totalShine);
                printf("Required Moons: %d", unlockShine);
                #endif
                break;
            }
            case Modes:
            {
                printf("Modes\n");
                #if SMOVER==100
                MAX_LINE(6);
                #endif
                #if SMOVER==130
                MAX_LINE(0);
                #endif
                CURSOR(0);
                CHANGE_PAGE();

                #if SMOVER==130
                printf(MSG_NO130);
                #endif

                #if SMOVER==100
                TOGGLE("isModeDiverOrJungleGymRom: %s\n", isModeDiverOrJungleGymRom, 1);
                TOGGLE("isModeDiverRom: %s\n", isModeDiverRom, 2);
                TOGGLE("isModeJungleGymRom: %s\n", isModeJungleGymRom, 3);
                TOGGLE("isModeE3LiveRom: %s\n", isModeE3LiveRom, 4);
                TOGGLE("isModeE3MovieRom: %s\n", isModeE3MovieRom, 5);
                TOGGLE("isModeEpdMovieRom: %s\n", isModeEpdMovieRom, 6);
                #endif
                break;
            };
            case Debug:
            {
                printf("Debug\n");
                MAX_LINE(0);
                CURSOR(0);
                CHANGE_PAGE();

                #if(SMOVER==100)
                printf("Current Scenario: %d\n", GameDataFunction::getWorldScenarioNo(*stageScene->mHolder, GameDataFunction::getCurrentWorldId(*stageScene->mHolder)));
                printf("Current World ID: %d\n", GameDataFunction::getCurrentWorldId(*stageScene->mHolder));
                printf("Current Stage Name: %s\n", GameDataFunction::getCurrentStageName(*stageScene->mHolder));
                printf("Language: %s\n", stageScene->mHolder->getLanguage());
                #endif
                printf("\n");
                printf("Practice Mod Version: %s\n", PRACTICE_VERSTR);
                break;
            }
            default:
            {
                curPage = About;
                break;
            }
        }
    }
    #if(SMOVER==130)
    al::showPane(stageScene->stageSceneLayout->coinCounter, "TxtDebug");
    al::setPaneStringFormat(stageScene->stageSceneLayout->coinCounter, "TxtDebug", textBuffer);
    nextFrameNoLeftInput = false;
    #endif
}