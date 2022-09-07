#include "al/LiveActor/LiveActor.h"
#include "al/util.hpp"
#include "fl/ui/pages.h"
#include "fl/util.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "rs/util.hpp"
#include "gfx/seadCamera.h"

void fl::ui::info::update(PracticeUI& ui)
{
    static bool quatRot = false;

    ui.toggle("Quaternion Rotation", quatRot);

    PlayerActorHakoniwa* player = rs::getPlayerActor(ui.getStageScene());
    al::LiveActor* cappy = player->mHackCap;

    sead::Vector3f* playerTrans = al::getTrans(player);
    sead::Vector3f* playerVel = al::getVelocity(player);
    sead::Quatf* playerQuat = al::getQuat(player);
    sead::Vector3f playerEulerAngles = fl::QuatToEuler(playerQuat);
    sead::Vector3f playerRot = sead::Vector3f(DEG(playerEulerAngles.x), DEG(playerEulerAngles.y), DEG(playerEulerAngles.z));
    sead::Vector3f* playerRecoveryPoint = player->mPlayerRecoverPoint->getSafetyPoint();
    sead::Vector3f* cappyPosition = al::getTrans(cappy);
    sead::Vector3f* cappyVel = al::getVelocity(cappy);
    sead::Quatf* cappyQuat = al::getQuat(cappy);
    sead::Vector3f cappyEulerAngles = fl::QuatToEuler(cappyQuat);
    sead::Vector3f cappyRot = sead::Vector3f(DEG(cappyEulerAngles.x), DEG(cappyEulerAngles.y), DEG(cappyEulerAngles.z));
    const char* anim = player->mPlayerAnimator->mCurrentAnim;
    float hSpeed = al::calcSpeedH(player), vSpeed = al::calcSpeedV(player), speed = al::calcSpeed(player);

    ui.printf("Player Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerTrans->x, playerTrans->y, playerTrans->z);
    ui.printf("Player Vel: (X: %.3f Y: %.3f Z: %.3f)\n", playerVel->x, playerVel->y, playerVel->z);
    ui.printf("Player Speed: (H: %.3f V: %.3f S: %.3f)\n", hSpeed, vSpeed, speed);
    if (quatRot) {
        ui.printf("Player Rot: (W: %.3f X: %.3f Y: %.3f Z: %.3f)\n", playerQuat->w, playerQuat->x, playerQuat->y, playerQuat->z);
    } else {
        ui.printf("Player Rot: (X: %.3f Y: %.3f Z: %.3f)\n", playerRot.x, playerRot.y, playerRot.z);
    }
    ui.printf("Cappy Pos: (X: %.3f Y: %.3f Z: %.3f)\n", cappyPosition->x, cappyPosition->y, cappyPosition->z);
    ui.printf("Cappy Vel: (X: %.3f Y: %.3f Z: %.3f)\n", cappyVel->x, cappyVel->y, cappyVel->z);
    if (quatRot) {
        ui.printf("Cappy Rot: (W: %.3f X: %.3f Y: %.3f Z: %.3f)\n", cappyQuat->w, cappyQuat->x, cappyQuat->y, cappyQuat->z);
    } else {
        ui.printf("Cappy Rot: (X: %.3f Y: %.3f Z: %.3f)\n", cappyRot.x, cappyRot.y, cappyRot.z);
    }
    ui.printf("Bubble Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerRecoveryPoint->x, playerRecoveryPoint->y, playerRecoveryPoint->z);
    ui.printf("Current Animation: %s (%.0f/%.0f)\n", anim, player->mPlayerAnimator->getAnimFrame() - 1.0f, player->mPlayerAnimator->getAnimFrameMax());
}

void fl::ui::info2::update(PracticeUI& ui)
{
    sead::LookAtCamera* camera = al::getLookAtCamera(ui.getStageScene(), 0);
    
    sead::Vector3f cameraPos = camera->mPos;
    sead::Vector3f cameraAt = camera->mAt;
    sead::Vector3f cameraUp = camera->mUp;

    ui.printf("Camera Pos: (X: %.3f Y: %.3f Z: %.3f)\n", cameraPos.x, cameraPos.y, cameraPos.z);
    ui.printf("Camera At: (X: %.3f Y: %.3f Z: %.3f)\n", cameraAt.x, cameraAt.y, cameraAt.z);
    ui.printf("Camera Up: (X: %.3f Y: %.3f Z: %.3f)\n", cameraUp.x, cameraUp.y, cameraUp.z);

}
