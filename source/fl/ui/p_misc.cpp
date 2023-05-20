#include "fl/ui/pages.h"
#include "game/GameData/GameDataFunction.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "rs/util.hpp"
#include <fl/game.h>

void fl::ui::misc::update(PracticeUI& ui)
{
    StageScene* stageScene = ui.getStageScene();
    if (!isInGame) {
        ui.printf("Not in game!\n");
        return;
    }
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
    ui.trigger("Add 1000 coins", [stageScene]() {
        stageScene->mHolder->mGameDataFile->addCoin(1000); // TODO idea: subtract coins
    });
    ui.trigger("Reload scene", [stageScene]() {
        const char* entry = stageScene->mHolder->mGameDataFile->mStartId.cstr();
        ChangeStageInfo info = ChangeStageInfo(stageScene->mHolder, entry, stageScene->mHolder->getCurrentStageName(), false, -1, {0});
        stageScene->mHolder->changeNextStage(&info, 0);
    });
    ui.trigger("Previous scene", [stageScene]() {
        stageScene->mHolder->returnPrevStage();
    });

    ui.toggle("Override Bowser Hat Randomizer", ui.overrideBowserHat0);

    static u8 gravity = 0;
    ui.cursor(11);
    ui.addLine();
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
    ui.printf("Gravity: %s", gravityString);
    if (ui.curLine == 11 && ui.inputEnabled && !ui.nextFrameNoLeftInput && isTriggerLeft()) {
        gravity--;
        gravityChanged = true;
    } else if (ui.curLine == 11 && ui.inputEnabled && !ui.nextFrameNoRightInput && isTriggerRight()) {
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
    
    if(o->mPoseKeeper->getGravityPtr() != nullptr) {
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
    } else {
        ui.printf(" (currently not applied)");
    }

    ui.printf("\n");
    ui.addLine();
	ui.printf("%sWiggler Pattern: %s\n", ui.curLine == 12 ? ">" : "", ui.curPattern == PracticeUI::MofumofuPattern::Random ? "Random" : ui.mPatternEntries[ui.curPattern].typeStr);
	if (isTriggerRight() && ui.curLine == 12) {
		if ((*(s8 *)&ui.curPattern) == (s8)PracticeUI::MofumofuPattern::Star)
			(*(s8 *)&ui.curPattern) = (s8)PracticeUI::MofumofuPattern::Random;
		else
			(*(s8 *)&ui.curPattern)++;
	}
	if (isTriggerLeft() && ui.curLine == 12) {
		if ((*(s8 *)&ui.curPattern) == (s8)PracticeUI::MofumofuPattern::Random)
			(*(s8 *)&ui.curPattern) = (s8)PracticeUI::MofumofuPattern::Star;
		else
			(*(s8 *)&ui.curPattern)--;
	}
}
