#include "al/util.hpp"
#include "fl/ui/page.h"
#include "fl/ui/pages.h"
#include "fl/util.h"
#include "nn/init.h"
#include "rs/util.hpp"

#include <fl/game.h>
#include <fl/server.h>
#include <fl/ui/ui.h>

void fl::ui::PracticeUI::savePosition(PlayerActorHakoniwa& player)
{
    savedTrans = *al::getTrans(&player);
    savedQuat = *al::getQuat(&player);
    saved = true;
}

void fl::ui::PracticeUI::loadPosition(PlayerActorHakoniwa& player)
{
    al::LiveActor* move = &player;
    al::LiveActor* hack = player.mHackKeeper->currentHackActor;

    if (hack)
        move = hack;

    if (disablePuppet && !hack)
        al::offCollide(&player);
    else if (!hack)
        player.startDemoPuppetable();
    else
        al::offCollide(hack);

    al::setTrans(move, savedTrans);
    if (!hack)
        al::updatePoseQuat(move, savedQuat);
    al::setVelocityZero(move);

    if (disablePuppet && !hack)
        al::onCollide(&player);
    else if (!hack)
        player.endDemoPuppetable();
    else
        al::onCollide(hack);
}

void fl::ui::PracticeUI::update(StageScene* stageScene)
{
    Game::instance().setStageScene(stageScene);
    this->mStageScene = stageScene;
    isInGame = true;

    PlayerActorHakoniwa* player = rs::getPlayerActor(stageScene);

    bool holdL = isL();

#if SMOVER == 100
    fl::TasHolder::instance().update();
#endif

    if (holdL && isTriggerRight()) {
        inputEnabled = !inputEnabled;
        nextFrameNoRightInput = true;
        return;
    } else if
#if SMOVER == 130
        (holdL && isTriggerLeft())
#endif
#if SMOVER == 100
        (isTriggerPressLeftStick())
#endif
        {
            showMenu = !showMenu;
#if SMOVER == 130
            nextFrameNoLeftInput = true;
#endif
        }

	if (!showMenu || (!inputEnabled && !holdL)) {
		if (teleportEnabled) {
			// If holdL is true and the left D-pad is pressed, that means showMenu is only false
			// because we just hid the menu. And hiding the menu shouldn't save Mario's position.
#if SMOVER == 100
			if (isTriggerLeft())
				savePosition(*player);
#endif
#if SMOVER == 130
			if (isTriggerLeft() && !holdL)
				savePosition(*player);
#endif

            if (isTriggerRight() && saved)
                loadPosition(*player);
        }
    }

    if (hideShineCounter)
        al::hidePane(stageScene->stageSceneLayout->shineCounter, "TxtShine");
    else
        al::showPane(stageScene->stageSceneLayout->shineCounter, "TxtShine");

#if SMOVER == 130
    if (showMenu)
        menu();
    else
        al::setPaneStringFormat(stageScene->stageSceneLayout->coinCounter, "TxtDebug", " ");
#endif
}

#if SMOVER == 100
void fl::ui::PracticeUI::menu(sead::TextWriter& p)
#endif
#if SMOVER == 130
    void fl::ui::PracticeUI::menu()
#endif
{
    s32 sprintfRv = 0;
    printPos = 0;
    if (!mStageScene)
        return;
    if (showMenu) {
        if (inputEnabled) {
            if (isTriggerDown())
                curLine++;
            if (isTriggerUp())
                curLine = (curLine == 0 ? curMaxLine-1 : curLine - 1);
            
            if (curLine < 0)
                curLine = curMaxLine;
            if (curLine >= curMaxLine)
                curLine = 0;
        }

        if (inputEnabled && curLine == 0) {
            if (isTriggerRight() && !nextFrameNoRightInput)
                (*(u8*)&curPage)++;
            if (isTriggerLeft() && !nextFrameNoLeftInput)
                (*(u8*)&curPage) = (curPage == Page::About ? (u8)Page::Debug : (*(u8*)&curPage)-1);
            if ((*(u8*)&curPage) > (u8)Page::Debug)
                (*(u8*)&curPage) = (u8)Page::About;
        }

        auto& page = mPages[*(u8*)&curPage];
        printf("%s%s (%d/%d) %s\n", curLine == 0 ? ">" : "", page.name, (int)curPage + 1, sizeof(mPages) / sizeof(mPages[0]), inputEnabled ? "" : "[Menu Disabled]");
        curMaxLine = 1;
        page.update(*this);
    } else {
        textBuffer[0] = ' ';
        textBuffer[1] = '\0';
    }
#if SMOVER == 130
    al::showPane(getStageScene()->stageSceneLayout->coinCounter, "TxtDebug");
    al::setPaneStringFormat(getStageScene()->stageSceneLayout->coinCounter, "TxtDebug", textBuffer);

    nextFrameNoLeftInput = false;
#elif SMOVER == 100
    p.printf(textBuffer);
#endif
    nextFrameNoRightInput = false;
}

void fl::ui::PracticeUI::toggle(const char* name, bool& value)
{
    cursor(curMaxLine);
    printf("%s: %s\n", name, value ? "Enabled" : "Disabled");
    if (inputEnabled && !nextFrameNoLeftInput && !nextFrameNoRightInput && curLine == curMaxLine && (isTriggerLeft() || isTriggerRight()))
        value = !value;
    curMaxLine++;
}
