#include "fl/ui/pages.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "rs/util.hpp"
#include <fl/game.h>

void fl::ui::misc::update(PracticeUI& ui)
{
    StageScene* stageScene = ui.getStageScene();
    ui.trigger("Kill Mario", []() {
        Game::instance().killMario();
    });
    ui.trigger("Damage Mario", []() {
        Game::instance().damageMario(1);
    });
    ui.trigger("Life Up Heart", []() {
        Game::instance().lifeUpHeart();
    });
    ui.trigger("Heal Mario", []() {
        Game::instance().healMario();
    });
    ui.trigger("Remove Cappy", []() {
        Game::instance().removeCappy();
    });
    ui.trigger("Invincibility Star", []() {
        Game::instance().invincibilityStar();
    });

    ui.addLine();

    static u8 gravity = 0;
    ui.cursor(7);
    const char* gravityString = nullptr;
    if (gravity == 0)
        gravityString = "Down";
    else if (gravity == 1)
        gravityString = "Up";
    else if (gravity == 2)
        gravityString = "North";
    else if (gravity == 3)
        gravityString = "South";
    else if (gravity == 4)
        gravityString = "East";
    else if (gravity == 5)
        gravityString = "West";

    bool gravityChanged = false;
    ui.printf("Gravity: %s\n", gravityString);
    if (ui.curLine == 7 && ui.inputEnabled && !ui.nextFrameNoLeftInput && al::isPadTriggerLeft(CONTROLLER_AUTO)) {
        gravity--;
        gravityChanged = true;
    } else if (ui.curLine == 7 && ui.inputEnabled && !ui.nextFrameNoRightInput && al::isPadTriggerRight(CONTROLLER_AUTO)) {
        gravity++;
        gravityChanged = true;
    }
    if (gravity == 255)
        gravity = 5;
    else if (gravity > 5)
        gravity = 0;
    PlayerActorHakoniwa* player = rs::getPlayerActor(stageScene);
    al::LiveActor* o = player;
    if (player->mHackKeeper->currentHackActor)
        o = player->mHackKeeper->currentHackActor;
    if (gravity == 0)
        al::setGravity(o, { 0, -1, 0 });
    else if (gravity == 1)
        al::setGravity(o, { 0, 1, 0 });
    else if (gravity == 2)
        al::setGravity(o, { 1, 0, 0 });
    else if (gravity == 3)
        al::setGravity(o, { -1, 0, 0 });
    else if (gravity == 4)
        al::setGravity(o, { 0, 0, 1 });
    else if (gravity == 5)
        al::setGravity(o, { 0, 0, -1 });
    ui.addLine();
    ui.printf("%sWiggler Pattern: %s\n", ui.curLine == 8 ? ">" : "", ui.curPattern == PracticeUI::MofumofuPattern::Random ? "Random" : ui.mPatternEntries[ui.curPattern].typeStr);
    if (al::isPadTriggerRight(CONTROLLER_AUTO) && ui.curLine == 8)
        (*(s8*)&ui.curPattern)++;
    if (al::isPadTriggerLeft(CONTROLLER_AUTO) && ui.curLine == 8)
        (*(s8*)&ui.curPattern)--;
    if (*(s8*)&ui.curPattern > 21 || *(s8*)&ui.curPattern < -1)
        ui.curPattern = PracticeUI::MofumofuPattern::Random;
}