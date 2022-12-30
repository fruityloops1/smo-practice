#include "al/LiveActor/LiveActor.h"
#include "al/util.hpp"
#include "fl/tas.h"
#include "fl/ui/pages.h"
#include "fl/util.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "rs/util.hpp"
#include "gfx/seadCamera.h"
#include "nn/util.h"
#include "sead/controller/seadControllerMgr.h"
#include "sead/controller/seadControllerAddon.h"
#include "sead/controller/seadControlDevice.h"
#include "sead/controller/nin/seadNinJoyNpadDevice.h"
#include "fl/common.h"

void fl::ui::info::update(PracticeUI& ui)
{
    static bool quatRot = false;

    ui.toggle("Quaternion Rotation", quatRot);

	StageScene* stageScene = ui.getStageScene();
    if (!isInGame) {
        ui.printf("Not in game!\n");
        
#if SMOVER == 100
        fl::TasHolder& h = fl::TasHolder::instance();

        if (h.isRunning)
            ui.printf(" TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
#endif
        return;
    }
    PlayerActorHakoniwa* player = rs::getPlayerActor(stageScene);
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
    float hSpeedAngle = atan2f(playerVel->z, playerVel->x);
    if (hSpeedAngle < 0)
        hSpeedAngle += M_PI * 2;

    ui.printf("Player Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerTrans->x, playerTrans->y, playerTrans->z);
    ui.printf("Player Vel: (X: %.3f Y: %.3f Z: %.3f)\n", playerVel->x, playerVel->y, playerVel->z);
    ui.printf("Player Vel Angle: %.3f\n", DEG(hSpeedAngle));
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

#if SMOVER == 100
    fl::TasHolder& h = fl::TasHolder::instance();

    if (h.isRunning)
        ui.printf(" TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
#endif
}

void fl::ui::info2::update(PracticeUI& ui)
{
    #if SMOVER == 130
    ui.printf(MSG_NO130);
    return;
    #endif
	StageScene* stageScene = ui.getStageScene();

    if(isInGame) {
        sead::LookAtCamera* camera = al::getLookAtCamera(stageScene, 0);

        sead::Vector3f cameraPos = camera->mPos;
        sead::Vector3f cameraAt = camera->mAt;
        sead::Vector3f cameraUp = camera->mUp;

        ui.printf("Camera Pos: (X: %.3f Y: %.3f Z: %.3f)\n", cameraPos.x, cameraPos.y, cameraPos.z);
        ui.printf("Camera At: (X: %.3f Y: %.3f Z: %.3f)\n", cameraAt.x, cameraAt.y, cameraAt.z);
        ui.printf("Camera Up: (X: %.3f Y: %.3f Z: %.3f)\n", cameraUp.x, cameraUp.y, cameraUp.z);

        sead::Vector3f diff = cameraAt - cameraPos;
        ui.printf("Vertical angle: %.3f\n", DEG(atan2f(diff.y, sqrtf(diff.x * diff.x + diff.z * diff.z))));
        ui.printf("Horizontal angle: %.3f\n", DEG(atan2f(diff.x, diff.z)));
    }

    sead::ControllerMgr* controllerMgr = sead::ControllerMgr::instance();

    sead::NinJoyNpadDevice* device = reinterpret_cast<sead::NinJoyNpadDevice*>(controllerMgr->getControlDevice(sead::ControllerDefine::DeviceId::_13));
    nn::hid::NpadFullKeyState* state = reinterpret_cast<nn::hid::NpadFullKeyState*>(&(device->SEAD_NINJOYNPADDEVICE[5]));

    //fgetNpadStatesFullKey(state, 16, 0);
    nn::hid::GetNpadStates(state, 16, 0);

    ui.printf("NPAD:\n");
    ui.printf("  mSamplingNumber: %#010x\n", state->mSamplingNumber);
    ui.printf("  mButtons: %#010x\n", state->mButtons);
    fl::TasHolder& h = fl::TasHolder::instance();
    if(h.isRunning) {
        ui.printf("  mAnalogStickL: %#018lx\n", (((long) h.frames[h.curFrame].leftStick.x) & 0xffffffff) | (((long) h.frames[h.curFrame].leftStick.y) << 32));
        ui.printf("  mAnalogStickR: %#018lx\n", (((long) h.frames[h.curFrame].rightStick.x) & 0xffffffff) | (((long) h.frames[h.curFrame].rightStick.y) << 32));
    } else {
        ui.printf("  mAnalogStickL: %#018lx\n", state->mAnalogStickL);
        ui.printf("  mAnalogStickR: %#018lx\n", state->mAnalogStickR);
    }
    ui.printf("  mAttributes: %#06x\n", state->mAttributes);
    ui.printf("  RESERVED: %#06x\n", state->RESERVED);
}

void fl::ui::infomighty::update(PracticeUI& ui) {
    #if SMOVER == 130
    ui.printf(MSG_NO130);
    return;
    #endif
    StageScene* stageScene = ui.getStageScene();

    if (!isInGame) {
        ui.printf("Not in game!\n");
        
#if SMOVER == 100
        fl::TasHolder& h = fl::TasHolder::instance();

        if (h.isRunning)
            ui.printf(" TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
#endif
        return;
    }

    PlayerActorHakoniwa* player = rs::getPlayerActor(stageScene);
    al::LiveActor* cappy = player->mHackCap;
    sead::LookAtCamera* camera = al::getLookAtCamera(stageScene, 0);

    sead::Vector3f* playerTrans = al::getTrans(player);
    float hSpeed = al::calcSpeedH(player), vSpeed = al::calcSpeedV(player), speed = al::calcSpeed(player);
    sead::Quatf* playerQuat = al::getQuat(player);
    sead::Vector3f playerEulerAngles = fl::QuatToEuler(playerQuat);
    sead::Vector3f playerRot = sead::Vector3f(DEG(playerEulerAngles.x), DEG(playerEulerAngles.y), DEG(playerEulerAngles.z));
    sead::Vector3f* cappyPosition = al::getTrans(cappy);
    sead::Vector3f* playerVel = al::getVelocity(player);
    float hSpeedAngle = atan2f(playerVel->z, playerVel->x);
    if (hSpeedAngle < 0)
        hSpeedAngle += M_PI * 2;
    
    sead::Vector3f cameraPos = camera->mPos;
    sead::Vector3f cameraAt = camera->mAt;
    sead::Vector3f cameraUp = camera->mUp;
    sead::Vector3f cameraDiff = cameraAt - cameraPos;
    float camVAngle = atan2f(cameraDiff.y, sqrtf(cameraDiff.x * cameraDiff.x + cameraDiff.z * cameraDiff.z));
    float camHAngle = atan2f(cameraDiff.z, cameraDiff.x);
    if (camHAngle < 0)
        camHAngle += M_PI * 2;

    float relAngleVel = hSpeedAngle - camHAngle - (M_PI / 2); // offset to move 0 to the right
    if (relAngleVel < 0)
        relAngleVel += M_PI * 2;
    relAngleVel = -relAngleVel + M_PI*2; // invert to conform normal anti-clockwise angle system

    ui.printf("Player Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerTrans->x, playerTrans->y, playerTrans->z);
    ui.printf("Player Speed: (H: %.3f V: %.3f S: %.3f)\n", hSpeed, vSpeed, speed);
    ui.printf("Player Vel Angle: %.3f\n", DEG(hSpeedAngle));
    ui.printf("Player Rot: (X: %.3f Y: %.3f Z: %.3f)\n", playerRot.x, playerRot.y, playerRot.z);
    ui.printf("Rel. Vel Angle: %.3f\n", DEG(relAngleVel));
    ui.printf("Cappy Pos: (X: %.3f Y: %.3f Z: %.3f)\n", cappyPosition->x, cappyPosition->y, cappyPosition->z);
    ui.printf("Cappy Speed: (H: %.3f V: %.3f S: %.3f)\n", al::calcSpeedH(cappy), al::calcSpeedV(cappy), al::calcSpeed(cappy));
    ui.printf("Current Animation: %s (%.0f/%.0f)\n", player->mPlayerAnimator->mCurrentAnim, player->mPlayerAnimator->getAnimFrame() - 1.0f, player->mPlayerAnimator->getAnimFrameMax());
    ui.printf("Cam Vertical angle: %.3f\n", DEG(camVAngle));
    ui.printf("Cam Horizontal angle: %.3f\n", DEG(camHAngle));
    
#if SMOVER == 100
    fl::TasHolder& h = fl::TasHolder::instance();

    if (h.isRunning)
        ui.printf(" TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
#endif
}

void fl::ui::infomighty2::update(PracticeUI& ui) {
    #if SMOVER == 130
    ui.printf(MSG_NO130);
    return;
    #endif
    StageScene* stageScene = ui.getStageScene();

    if (!isInGame) {
        ui.printf("Not in game!\n");
        
#if SMOVER == 100
        fl::TasHolder& h = fl::TasHolder::instance();

        if (h.isRunning)
            ui.printf(" TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
#endif
        return;
    }

    PlayerActorHakoniwa* player = rs::getPlayerActor(stageScene);
    al::LiveActor* cappy = player->mHackCap;
    sead::LookAtCamera* camera = al::getLookAtCamera(stageScene, 0);
    
    sead::Vector3f* playerVel = al::getVelocity(player);
    sead::Vector3f* cappyVel = al::getVelocity(cappy);
    sead::Vector3f* playerRecoveryPoint = player->mPlayerRecoverPoint->getSafetyPoint();

    ui.printf("Player Vel: (X: %.3f Y: %.3f Z: %.3f)\n", playerVel->x, playerVel->y, playerVel->z);
    ui.printf("Cappy Vel: (X: %.3f Y: %.3f Z: %.3f)\n", cappyVel->x, cappyVel->y, cappyVel->z);
    ui.printf("Bubble Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerRecoveryPoint->x, playerRecoveryPoint->y, playerRecoveryPoint->z);
    
    sead::Vector3f cameraPos = camera->mPos;
    sead::Vector3f cameraAt = camera->mAt;
    sead::Vector3f cameraUp = camera->mUp;
    sead::Vector3f diff = cameraAt - cameraPos;

    ui.printf("Camera Pos: (X: %.3f Y: %.3f Z: %.3f)\n", cameraPos.x, cameraPos.y, cameraPos.z);
    ui.printf("Camera At: (X: %.3f Y: %.3f Z: %.3f)\n", cameraAt.x, cameraAt.y, cameraAt.z);
    ui.printf("Camera Up: (X: %.3f Y: %.3f Z: %.3f)\n", cameraUp.x, cameraUp.y, cameraUp.z);

#if SMOVER == 100
    fl::TasHolder& h = fl::TasHolder::instance();

    if (h.isRunning)
        ui.printf(" TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
#endif
    
}
