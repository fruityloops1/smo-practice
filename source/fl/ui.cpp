#include "al/LiveActor/LiveActor.h"
#include "al/PlayerHolder/PlayerHolder.h"
#include "fl/util.h"
#include "game/GameData/GameDataFile.h"
#include "game/GameData/GameDataFunction.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "game/StageScene/ChangeStageInfo.h"
#include "debugMenu.hpp"
#include "sead/math/seadVector.h"
#include <al/util.hpp>
#include <fl/ui.h>

const char* stageNames[] = {"CapWorldHomeStage", "WaterfallWorldHomeStage", "SandWorldHomeStage", "LakeWorldHomeStage", "ForestWorldHomeStage", "CloudWorldHomeStage", "ClashWorldHomeStage", "CityWorldHomeStage",
                            "SnowWorldHomeStage", "SeaWorldHomeStage", "LavaWorldHomeStage", "BossRaidWorldHomeStage", "SkyWorldHomeStage", "MoonWorldHomeStage", "PeachWorldHomeStage", "Special1WorldHomeStage", "Special2WorldHomeStage", "DotTowerExStage", "Special2WorldLavaStage", "FrogSearchExStage", "Cube2DExStage", "SandWorldPyramid001Stage", "SeaWorldSecretStage", "CapAppearExStage", "ForestWorldWaterExStage", "PeachWorldShopStage", "SkyWorldTreasureStage", "SnowWorldRaceExStage", "PushBlockExStage", "ShootingCityYoshiExStage", "SnowWorldLobbyExStage", "DemoChangeWorldFindKoopaShipStage", "DonsukeExStage", "BullRunExStage", "DemoBossRaidAttackStage", "PeachWorldPictureGiantWanderBossStage", "CityWorldShop01Stage", "PackunPoisonNoCapExStage", "RevengeBossKnuckleStage", "SenobiTowerYoshiExStage", "SnowWorldShopStage", "Theater2DExStage", "LavaWorldBubbleLaneExStage", "DemoChangeWorldBossRaidAttackStage", "Special1WorldTowerStackerStage", "Special1WorldTowerFireBlowerStage", "SandWorldCostumeStage", "LavaWorldFenceLiftExStage", "ForestWorldBossStage", "BikeSteelExStage", "FastenerExStage", "SandWorldRotateExStage", "SeaWorldSneakingManStage", "TrexBikeExStage", "SnowWorldRaceHardExStage", "SandWorldPressExStage", "DemoCrashHomeStage", "WaterValleyExStage", "CapWorldTowerStage", "KillerRailCollisionExStage", "ByugoPuzzleExStage", "CityWorldFactoryStage", "Special2WorldKoopaStage", "SandWorldUnderground001Stage", "MoonWorldKoopa2Stage", "IceWaterBlockExStage", "PackunPoisonExStage", "DemoEndingStage", "DotHardExStage", "SenobiTowerExStage", "GabuzouClockExStage", "PeachWorldPictureBossMagmaStage", "ClashWorldShopStage", "SeaWorldCostumeStage", "DemoCrashHomeFallStage", "MoonWorldSphinxRoom", "SandWorldUnderground000Stage", "ShootingCityExStage", "PeachWorldPictureBossRaidStage", "RailCollisionExStage", "RevengeBossRaidStage", "LavaWorldTreasureStage", "Special2WorldCloudStage", "DemoWorldMoveForwardArriveStage", "MoonWorldWeddingRoomStage", "SeaWorldVibrationStage", "DemoWorldMoveMoonForwardStage", "MoonWorldBasementStage", "ForestWorldWoodsTreasureStage", "ForestWorldWoodsStage", "ForestWorldCloudBonusExStage", "PeachWorldPictureMofumofuStage", "CapRotatePackunExStage", "GotogotonExStage", "IceWalkerExStage", "PeachWorldPictureBossKnuckleStage", "MoonWorldKoopa1Stage", "RevengeBossMagmaStage", "ForestWorldTowerStage", "DemoStartWorldWaterfallStage", "PeachWorldCastleStage", "SkyWorldCostumeStage", "DemoWorldMoveMoonForwardFirstStage", "SkyWorldShopStage", "SnowWorldTownStage", "DemoLavaWorldScenario1EndStage", "RevengeGiantWanderBossStage", "SandWorldSphinxExStage", "DemoWorldMoveMoonBackwardStage", "SnowWorldRace000Stage", "SnowWorldCostumeStage", "BikeSteelNoCapExStage", "CapAppearLavaLiftExStage", "DemoHackKoopaStage", "RadioControlExStage", "TrexPoppunExStage", "TsukkunClimbExStage", "LavaWorldShopStage", "SandWorldSecretStage", "FukuwaraiKuriboStage", "ForkExStage", "JangoExStage", "DemoOpeningStage", "LakeWorldShopStage", "PoleGrabCeilExStage", "PoisonWaveExStage", "DemoWorldWarpHoleStage", "SandWorldVibrationStage", "LavaWorldClockExStage", "FukuwaraiMarioStage", "HomeShipInsideStage", "ImomuPoisonExStage", "CityWorldMainTowerStage", "SnowWorldRaceTutorialStage", "WorldStage", "SandWorldSlotStage", "RollingExStage", "SnowWorldRace001Stage", "SnowWorldLobby000Stage", "MoonWorldWeddingRoom2Stage", "LavaWorldUpDownExStage", "RevengeForestBossStage", "AnimalChaseExStage", "SeaWorldUtsuboCaveStage", "DemoTakeOffKoopaForMoonStage", "MoonWorldCaptureParadeStage", "LavaWorldCostumeStage", "Lift2DExStage", "Special1WorldTowerBombTailStage", "MoonWorldShopRoom", "SnowWorldCloudBonusExStage", "TogezoRotateExStage", "FrogPoisonExStage", "SkyWorldCloudBonusExStage", "KaronWingTowerStage", "WanwanClashExStage", "WaterTubeExStage", "DemoMeetCapNpcSubStage", "MoonAthleticExStage", "CloudExStage", "DemoHackFirstStage", "PeachWorldPictureBossForestStage", "ShootingElevatorExStage", "PeachWorldCostumeStage", "MeganeLiftExStage", "TrampolineWallCatchExStage", "CityWorldSandSlotStage", "ForestWorldBonusStage", "SwingSteelExStage", "TsukkunRotateExStage", "RocketFlowerExStage", "WindBlowExStage", "ForestWorldWoodsCostumeStage", "ElectricWireExStage", "DemoWorldMoveBackwardArriveStage", "Galaxy2DExStage", "IceWaterDashExStage", "ReflectBombExStage", "LavaWorldUpDownYoshiExStage", "JizoSwitchExStage", "RevengeMofumofuStage", "SnowWorldLobby001Stage", "YoshiCloudExStage", "KillerRoadExStage", "CityPeopleRoadStage", "Note2D3DRoomExStage", "DemoWorldMoveBackwardStage", "KillerRoadNoCapExStage", "DemoWorldMoveForwardStage", "SandWorldMeganeExStage", "LavaWorldExcavationExStage", "Special1WorldTowerCapThrowerStage", "DemoChangeWorldStage", "FogMountainExStage", "SandWorldPyramid000Stage", "SandWorldShopStage", "SandWorldKillerExStage", "PoleKillerExStage", "DemoWorldMoveForwardFirstStage", "StaffRollMoonRockDemo"};

#define NUM_PAGES 7
#define NUM_STAGES 200

#define CURSOR(WRITER, LINE) WRITER.printf(curLine == LINE ? ">" : "")
#define CHANGE_PAGE() p.printf("Change Page (%d/%d)\n", +curPage + 1, NUM_PAGES)

// Sets max amount of lines for a page
#define MAX_LINE(LINE) if (curLine > LINE) curLine = 0;

#define TOGGLE(FORMAT, BOOL, LINE) CURSOR(p, LINE);\
                                   p.printf(FORMAT, BOOL ? "Enabled" : "Disabled");\
                                   if (inputEnabled && curLine == LINE && (al::isPadTriggerLeft(CONTROLLER_AUTO) || al::isPadTriggerRight(CONTROLLER_AUTO))) BOOL = !BOOL;

#define TRIGGER(NAME, LINE, ACTION) CURSOR(p, LINE);\
                              p.printf(NAME);\
                              if (inputEnabled && curLine == LINE && al::isPadTriggerRight(CONTROLLER_AUTO)) ACTION;


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

    al::PlayerHolder* pHolder = al::getScenePlayerHolder(&stageScene);
    PlayerActorHakoniwa* player = al::tryGetPlayerActor(pHolder, 0);
    
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

    if (reloadStageForPos != -1)
    {
        reloadStageForPos++;
        if (reloadStageForPos == 11)
        {
            player->startDemoPuppetable();
            al::setTrans(player, reloadStagePos);
            al::updatePoseQuat(player, reloadStageQuat);
            player->endDemoPuppetable();
            reloadStageForPos = -1;
        }
    }

    bool triggerLeftStick = al::isPadTriggerPressLeftStick(CONTROLLER_AUTO);

    if (al::isPadHoldL(CONTROLLER_AUTO) && triggerLeftStick) inputEnabled = !inputEnabled;
    else if (triggerLeftStick) showMenu = !showMenu;
}

void fl::PracticeUI::print(sead::TextWriter& p)
{
    if (!stageScene) return;
    if (showMenu)
    {
        enum Page : u8
        {
            About, Options, Stage, Misc, Info, Debug, MoonInfo
        };
        static Page curPage = About;
        static u8 curLine = 0;

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
                else if (curPage == Info) curPage = Debug;
                else if (curPage == Debug) curPage = MoonInfo;
            }
            if (al::isPadTriggerLeft(CONTROLLER_AUTO))
            {
                if (curPage == Options) curPage = About;
                else if (curPage == Stage) curPage = Options;
                else if (curPage == Misc) curPage = Stage;
                else if (curPage == Info) curPage = Misc;
                else if (curPage == Debug) curPage = Info;
                else if (curPage == MoonInfo) curPage = Debug;
            }
        }

        al::PlayerHolder* pHolder = al::getScenePlayerHolder(stageScene);
        PlayerActorHakoniwa* player = al::tryGetPlayerActor(pHolder, 0);

        switch (curPage)
        {
            case About:
            {
                MAX_LINE(0);
                CURSOR(p, 0);
                CHANGE_PAGE();
                p.printf("Welcome to the Practice Mod!\n");
                p.printf("Made by Fruityloops#8500\n");
                p.printf("Big thanks to CraftyBoss and bryce_____!\n");
                break;
            }
            case Options:
            {
                p.printf("Options\n");
                MAX_LINE(5);
                CURSOR(p, 0);
                CHANGE_PAGE();
                
                TOGGLE("Teleport: %s\n", teleportEnabled, 1);
                TOGGLE("Moon Refresh: %s\n", shineRefresh, 2);
                TOGGLE("Gray Moon Refresh: %s\n", gotShineRefresh, 3);
                TOGGLE("Always Enable Warps: %s\n", alwaysWarp, 4);
                TOGGLE("Disable Autosaving: %s\n", disableAutoSave, 5);
                break;
            }
            case Stage:
            {
                static u32 currentStage = 0;
                static s8 currentScenario = -1;

                p.printf("Stages\n");
                MAX_LINE(3);
                CURSOR(p, 0);
                CHANGE_PAGE();
                CURSOR(p, 1);

                if (inputEnabled && curLine == 1)
                {
                    if (al::isPadTriggerRight(CONTROLLER_AUTO)) currentStage++;
                    if (al::isPadTriggerLeft(CONTROLLER_AUTO))
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
                    if (al::isPadTriggerLeft(CONTROLLER_AUTO)) currentScenario--;
                }

                if (currentScenario < -1 || currentScenario == 0 || currentScenario > 15) currentScenario = -1;

                if (currentStage + 1 > NUM_STAGES) currentStage = 0;
                p.printf("Stage: %s\n", stageNames[currentStage]);
                CURSOR(p, 2);
                if (currentScenario != -1) p.printf("Scenario: %d\n", +currentScenario);
                else p.printf("Scenario: Don't change\n");

                TRIGGER("Go\n", 3, {
                    ChangeStageInfo info = ChangeStageInfo(stageScene->mHolder, "start", stageNames[currentStage], false, currentScenario, {0});
                    stageScene->mHolder->changeNextStage(&info, 0);
                    curLine = 0;
                });
                break;
            }
            case Misc:
            {
                p.printf("Miscellaneous\n");
                MAX_LINE(4);
                CURSOR(p, 0);
                CHANGE_PAGE();

                TRIGGER("Kill Mario\n", 1, {
                    player->mDamageKeeper->dead();
                    curLine = 0;
                });
                TRIGGER("Remove Cappy\n", 2, GameDataFunction::disableCapByPlacement(player->mHackCap));
                TRIGGER("Invincibility Star\n", 3, player->mDamageKeeper->activatePreventDamage());
                TRIGGER("Reload Stage\n", 4, {
                    reloadStageForPos = 0;
                    reloadStagePos = *al::getTrans(player);
                    reloadStageQuat = *al::getQuat(player);
                    ChangeStageInfo info = ChangeStageInfo(stageScene->mHolder, "start", stageScene->mHolder->getCurrentStageName(), false, CURRENT_SCENARIO, {0});
                    stageScene->mHolder->changeNextStage(&info, 0);
                });

                break;
            }
            case Info:
            {
                p.printf("Info\n");
                MAX_LINE(1);
                CURSOR(p, 0);
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

                p.printf("Player Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerTrans->x, playerTrans->y, playerTrans->z);
                p.printf("Player Vel: (X: %.3f Y: %.3f Z: %.3f)\n", playerVel->x, playerVel->y, playerVel->z);
                p.printf("Player Speed: (H: %.3f V: %.3f S: %.3f)\n", hSpeed, vSpeed, speed);
                if (quatRot)
                    p.printf("Player Rot: (W: %.3f X: %.3f Y: %.3f Z: %.3f)\n", playerQuat->w, playerQuat->x, playerQuat->y, playerQuat->z);
                else
                    p.printf("Player Rot: (X: %.3f Y: %.3f Z: %.3f)\n", playerRot.x, playerRot.y, playerRot.z);
                p.printf("Cappy Pos: (X: %.3f Y: %.3f Z: %.3f)\n", cappyPosition->x, cappyPosition->y, cappyPosition->z);
                if (quatRot)
                    p.printf("Cappy Rot: (W: %.3f X: %.3f Y: %.3f Z: %.3f)\n", cappyQuat->w, cappyQuat->x, cappyQuat->y, cappyQuat->z);
                else
                    p.printf("Cappy Rot: (X: %.3f Y: %.3f Z: %.3f)\n", cappyRot.x, cappyRot.y, cappyRot.z);
                p.printf("Bubble Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerRecoveryPoint->x, playerRecoveryPoint->y, playerRecoveryPoint->z);
                p.printf("Current Animation: %s (%.0f/%.0f)\n", anim, player->mPlayerAnimator->getAnimFrame() - 1.0f, player->mPlayerAnimator->getAnimFrameMax());

                break;
            }
            case Debug:
            {
                p.printf("Debug\n");
                MAX_LINE(0);
                CURSOR(p, 0);
                CHANGE_PAGE();

                p.printf("Current Stage: %s\n", stageScene->mHolder->getCurrentStageName());
                p.printf("Current Scenario: %d\n", GameDataFunction::getWorldScenarioNo(*stageScene->mHolder, GameDataFunction::getCurrentWorldId(*stageScene->mHolder)));
                p.printf("Current World ID: %d\n", GameDataFunction::getCurrentWorldId(*stageScene->mHolder));
                p.printf("Language: %s\n", stageScene->mHolder->getLanguage());
                break;
            }
            case MoonInfo:
            {
                p.printf("Moon Info\n");
                MAX_LINE(1);
                CURSOR(p, 0);
                CHANGE_PAGE();

                static bool hideShineCounter = false;
                TOGGLE("Hide Original Moon Counter: %s\n", hideShineCounter, 1);

                if (hideShineCounter)
                al::hidePane(stageScene->stageSceneLayout->shineCounter, "TxtShine");
                else
                al::showPane(stageScene->stageSceneLayout->shineCounter, "TxtShine");

                s32 currshine = GameDataFunction::getCurrentShineNum(*stageScene->mHolder);
                s32 totalshine = GameDataFunction::getTotalShineNum(*stageScene->mHolder, -1);
                s32 unlockshine = GameDataFunction::findUnlockShineNumByWorldId(0, *stageScene->mHolder, GameDataFunction::getCurrentWorldId(*stageScene->mHolder));
                p.printf("Current Moons: %d\n", currshine);
                p.printf("Total Moons: %d\n", totalshine);
                p.printf("Required Moons: %d", unlockshine);
                break;
            }
            default:
            {
                curPage = About;
                break;
            }
        }
    }
}