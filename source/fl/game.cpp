#include "fl/game.h"

#include <game/GameData/GameDataFunction.h>
#include <game/Player/PlayerActorHakoniwa.h>
#include <game/StageScene/StageScene.h>
#include "rs/util.hpp"

namespace fl {

void Game::setStageScene(StageScene* stage_scene) {
    mStageScene = stage_scene;
}

PlayerActorHakoniwa* Game::getPlayer() const {
    return rs::getPlayerActor(mStageScene);
}

void Game::killMario() {
    getPlayer()->mDamageKeeper->dead();
}

void Game::damageMario(int amount) {
    getPlayer()->mDamageKeeper->damage(amount);
}

void Game::lifeUpHeart() {
    #if SMOVER==100
    mStageScene->mHolder->mGameDataFile->getPlayerHitPointData()->getMaxUpItem();
    #endif
    #if SMOVER==130
    GameDataFunction::getLifeMaxUpItem(getPlayer());
    #endif
}

void Game::healMario() {
    #if SMOVER==100
    mStageScene->mHolder->mGameDataFile->getPlayerHitPointData()->recover();
    #endif
    #if SMOVER==130
    GameDataFunction::recoveryPlayer(getPlayer());
    #endif
}

void Game::removeCappy() {
    GameDataFunction::disableCapByPlacement(getPlayer()->mHackCap);
}

void Game::invincibilityStar() {
    getPlayer()->mDamageKeeper->activatePreventDamage();
}

}
