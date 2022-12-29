#include "al/LiveActor/LiveActor.h"
#include "fl/tas.h"
#include "fl/ui/pages.h"
#include "fl/util.h"
#include "game/GameData/GameDataFunction.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "rs/util.hpp"

void fl::ui::statistics::update(PracticeUI& ui)
{
    StageScene* stageScene = ui.getStageScene();
    if (!isInGame) {
        ui.printf("Not in game!\n");
        return;
    }

    int jumpCount = rs::getPlayerJumpCount(stageScene->mHolder);
    int throwCapCount = rs::getPlayerThrowCapCount(stageScene->mHolder);
    int playTimeTotal = GameDataFunction::getPlayTimeTotal(*stageScene->mHolder);
    int playTimeAcrossFile = GameDataFunction::getPlayTimeAcrossFile(*stageScene->mHolder);
    int totalCoinNum = rs::getTotalCoinNum(stageScene->mHolder);

    ui.printf("Jump Count: %d\n", jumpCount);
    ui.printf("Throw Cap Count: %d\n", throwCapCount);
    ui.printf("Play Time Total: %d\n", playTimeTotal);
    ui.printf("Play Time Across File: %d\n", playTimeAcrossFile);
    ui.printf("Total Coin Num: %d\n", totalCoinNum);
}
