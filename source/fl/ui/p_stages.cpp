#include "fl/ui/pages.h"
#include <fl/common.h>

constexpr const char* stageNames[] = { "CapWorldHomeStage", "WaterfallWorldHomeStage", "SandWorldHomeStage", "LakeWorldHomeStage", "ForestWorldHomeStage", "CloudWorldHomeStage", "ClashWorldHomeStage", "CityWorldHomeStage",
    "SnowWorldHomeStage", "SeaWorldHomeStage", "LavaWorldHomeStage", "BossRaidWorldHomeStage", "SkyWorldHomeStage", "MoonWorldHomeStage", "PeachWorldHomeStage", "Special1WorldHomeStage", "Special2WorldHomeStage", "MoonWorldBasementStage", "MoonWorldKoopa1Stage", "MoonWorldKoopa2Stage", "AnimalChaseExStage", "BikeSteelExStage", "BikeSteelNoCapExStage", "BullRunExStage", "ByugoPuzzleExStage", "CapAppearExStage", "CapAppearLavaLiftExStage", "CapRotatePackunExStage", "CapWorldTowerStage", "CityPeopleRoadStage", "CityWorldFactoryStage", "CityWorldMainTowerStage", "CityWorldSandSlotStage", "CityWorldShop01Stage", "ClashWorldShopStage", "CloudExStage", "Cube2DExStage", "DemoBossRaidAttackStage", "DemoChangeWorldBossRaidAttackStage", "DemoChangeWorldFindKoopaShipStage", "DemoChangeWorldStage", "DemoCrashHomeFallStage", "DemoCrashHomeStage", "DemoEndingStage", "DemoHackFirstStage", "DemoHackKoopaStage", "DemoLavaWorldScenario1EndStage", "DemoMeetCapNpcSubStage", "DemoOpeningStage", "DemoStartWorldWaterfallStage", "DemoTakeOffKoopaForMoonStage", "DemoWorldMoveBackwardArriveStage", "DemoWorldMoveBackwardStage", "DemoWorldMoveForwardArriveStage", "DemoWorldMoveForwardFirstStage", "DemoWorldMoveForwardStage", "DemoWorldMoveMoonBackwardStage", "DemoWorldMoveMoonForwardFirstStage", "DemoWorldMoveMoonForwardStage", "DemoWorldWarpHoleStage", "DonsukeExStage", "DotHardExStage", "DotTowerExStage", "ElectricWireExStage", "FastenerExStage", "FogMountainExStage", "ForestWorldBonusStage", "ForestWorldBossStage", "ForestWorldCloudBonusExStage", "ForestWorldTowerStage", "ForestWorldWaterExStage", "ForestWorldWoodsCostumeStage", "ForestWorldWoodsStage", "ForestWorldWoodsTreasureStage", "ForkExStage", "FrogPoisonExStage", "FrogSearchExStage", "FukuwaraiKuriboStage", "FukuwaraiMarioStage", "GabuzouClockExStage", "Galaxy2DExStage", "GotogotonExStage", "HomeShipInsideStage", "IceWalkerExStage", "IceWaterBlockExStage", "IceWaterDashExStage", "ImomuPoisonExStage", "JangoExStage", "JizoSwitchExStage", "KaronWingTowerStage", "KillerRailCollisionExStage", "KillerRoadExStage", "KillerRoadNoCapExStage", "LakeWorldShopStage", "LavaWorldBonus1Zone", "LavaWorldBubbleLaneExStage", "LavaWorldClockExStage", "LavaWorldCostumeStage", "LavaWorldExcavationExStage", "LavaWorldFenceLiftExStage", "LavaWorldShopStage", "LavaWorldTreasureStage", "LavaWorldUpDownExStage", "LavaWorldUpDownYoshiExStage", "Lift2DExStage", "MeganeLiftExStage", "MoonAthleticExStage", "MoonWorldCaptureParadeStage", "MoonWorldShopRoom", "MoonWorldSphinxRoom", "MoonWorldWeddingRoom2Stage", "MoonWorldWeddingRoomStage", "Note2D3DRoomExStage", "PackunPoisonExStage", "PackunPoisonNoCapExStage", "PeachWorldCastleStage", "PeachWorldCostumeStage", "PeachWorldPictureBossForestStage", "PeachWorldPictureBossKnuckleStage", "PeachWorldPictureBossMagmaStage", "PeachWorldPictureBossRaidStage", "PeachWorldPictureGiantWanderBossStage", "PeachWorldPictureMofumofuStage", "PeachWorldShopStage", "PoisonWaveExStage", "PoleGrabCeilExStage", "PoleKillerExStage", "PushBlockExStage", "RadioControlExStage", "RailCollisionExStage", "ReflectBombExStage", "RevengeBossKnuckleStage", "RevengeBossMagmaStage", "RevengeBossRaidStage", "RevengeForestBossStage", "RevengeGiantWanderBossStage", "RevengeMofumofuStage", "RocketFlowerExStage", "RollingExStage", "SandWorldCostumeStage", "SandWorldKillerExStage", "SandWorldMeganeExStage", "SandWorldPressExStage", "SandWorldPyramid000Stage", "SandWorldPyramid001Stage", "SandWorldRotateExStage", "SandWorldSecretStage", "SandWorldShopStage", "SandWorldSlotStage", "SandWorldSphinxExStage", "SandWorldUnderground000Stage", "SandWorldUnderground001Stage", "SandWorldVibrationStage", "SeaWorldCostumeStage", "SeaWorldSecretStage", "SeaWorldSneakingManStage", "SeaWorldUtsuboCaveStage", "SeaWorldVibrationStage", "SenobiTowerExStage", "SenobiTowerYoshiExStage", "ShootingCityExStage", "ShootingCityYoshiExStage", "ShootingElevatorExStage", "SkyWorldCloudBonusExStage", "SkyWorldCostumeStage", "SkyWorldShopStage", "SkyWorldTreasureStage", "SnowWorldCloudBonusExStage", "SnowWorldCostumeStage", "SnowWorldLobby000Stage", "SnowWorldLobby001Stage", "SnowWorldLobbyExStage", "SnowWorldRace000Stage", "SnowWorldRace001Stage", "SnowWorldRaceExStage", "SnowWorldRaceHardExStage", "SnowWorldRaceTutorialStage", "SnowWorldShopStage", "SnowWorldTownStage", "Special1WorldTowerBombTailStage", "Special1WorldTowerCapThrowerStage", "Special1WorldTowerFireBlowerStage", "Special1WorldTowerStackerStage", "Special2WorldCloudStage", "Special2WorldKoopaStage", "Special2WorldLavaStage", "StaffRollMoonRockDemo", "SwingSteelExStage", "Theater2DExStage", "TogezoRotateExStage", "TrampolineWallCatchExStage", "TrexBikeExStage", "TrexPoppunExStage", "TsukkunClimbExStage", "TsukkunRotateExStage", "WanwanClashExStage", "WaterTubeExStage", "WaterValleyExStage", "WindBlowExStage", "WorldStage", "YoshiCloudExStage" };

constexpr const char *stageNameDescriptions[17][15] = {
	{"first visit, spawn airborne", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "trailer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "plot complete", "post-game", "moon rock", "Koopa Freerunning", "Luigi's Balloon World", "post-game, copy", "trailer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "night", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "E3 demo", "trailer", "night, E3 demonstration", "crashes", "crashes", "crashes", "crashes", "crashes"},
	{"first visit", "plot complete", "post-game", "moon rock", "Koopa Freerunning", "Luigi's Balloon World", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "night", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "first visit, copy", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "plot complete", "post-game", "moon rock", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"night", "day", "festival", "plot complete", "post-game", "Luigi's Balloon World", "festival, revisit", "moon rock", "Koopa Freerunning", "morning metro", "festival, 8-bit", "morning, missing wire", "day, trailer", "festival, trailer", "night, copy"},
	{"first visit", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "plot complete", "post-game", "moon rock", "Koopa Freerunning", "Luigi's Balloon World", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "evening", "plot complete", "Koopa Freerunning", "incomplete", "incomplete", "post-game", "moon rock", "Luigi's Balloon World", "bruncheon", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "plot complete", "post-game", "moon rock", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes"},
	{"first visit", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layere"},
	{"first visit", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"rushroom", "first visit", "post-game", "Koopa Freerunning", "Luigi's Balloon World", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "post-game", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
	{"first visit", "post-game", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"}};

#define NUM_STAGES 201

void fl::ui::stages::update(PracticeUI& ui)
{
    static int currentStage = 0;
    static int currentScenario = 1;

    ui.cursor(1);
    if (ui.inputEnabled && ui.curLine == 1) {
        if (isTriggerRight() && !ui.nextFrameNoRightInput)
            currentStage++;
        if (isTriggerLeft() && !ui.nextFrameNoLeftInput) {
            if (currentStage == 0)
                currentStage = NUM_STAGES - 1;
            else
                currentStage--;
        }
    } else if (ui.inputEnabled && ui.curLine == 2) {
        if (isTriggerRight() && !ui.nextFrameNoRightInput)
            currentScenario = currentScenario == -1 ? 1 : currentScenario + 1;
        if (isTriggerLeft() && !ui.nextFrameNoLeftInput) {
            if (currentScenario == -1)
                currentScenario = 15;
            else
                currentScenario--;
        }
    }
    if (currentScenario < -1 || currentScenario == 0 || currentScenario > 15)
        currentScenario = -1;
    if (currentStage + 1 > NUM_STAGES)
        currentStage = 0;
    ui.printf("Stage: %s\n", stageNames[currentStage]);
    ui.addLine();
    ui.cursor(2);
    if (currentScenario != -1) {
        if (currentStage < 17) {
            const char* description = stageNameDescriptions[currentStage][currentScenario - 1];
            ui.printf("Scenario: %d (%s)\n", currentScenario, description);
        }
        else
            ui.printf("Scenario: %d\n", currentScenario);
    } else
        ui.printf("Scenario: Don't change\n");

    ui.addLine();

    ui.trigger("Go", [&ui]() {
        ChangeStageInfo info = ChangeStageInfo(ui.getStageScene()->mHolder, "start", stageNames[currentStage], false, currentScenario, { 0 });
        ui.getStageScene()->mHolder->changeNextStage(&info, 0);
    });
}
