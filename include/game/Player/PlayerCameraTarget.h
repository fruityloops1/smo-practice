#pragma once

#include "al/camera/ICameraInput.h"
#include <al/LiveActor/LiveActor.h>
#include <al/camera/CameraTargetBase.h>
#include <types.h>

class PlayerCameraTarget : public al::CameraTargetBase
{
public:
    PlayerCameraTarget(const al::LiveActor* player);
};