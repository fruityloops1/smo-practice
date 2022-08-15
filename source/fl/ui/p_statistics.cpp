#include "al/LiveActor/LiveActor.h"
#include "fl/tas.h"
#include "fl/ui/pages.h"
#include "fl/util.h"
#include "game/GameData/GameDataFunction.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "rs/util.hpp"

void fl::ui::statistics::update(PracticeUI& ui)
{
    int jumpCount = rs::getPlayerJumpCount(ui.getStageScene()->mHolder);
    int throwCapCount = rs::getPlayerThrowCapCount(ui.getStageScene()->mHolder);
    int playTimeTotal = GameDataFunction::getPlayTimeTotal(*ui.getStageScene()->mHolder);
    int playTimeAcrossFile = GameDataFunction::getPlayTimeAcrossFile(*ui.getStageScene()->mHolder);
    int totalCoinNum = rs::getTotalCoinNum(ui.getStageScene()->mHolder);

    ui.printf("Jump Count: %d\n", jumpCount);
    ui.printf("Throw Cap Count: %d\n", throwCapCount);
    ui.printf("Play Time Total: %d\n", playTimeTotal);
    ui.printf("Play Time Across File: %d\n", playTimeAcrossFile);
    ui.printf("Total Coin Num: %d\n", totalCoinNum);
}
