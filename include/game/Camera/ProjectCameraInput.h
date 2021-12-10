#pragma once

#include "al/camera/ICameraInput.h"
#include <al/LiveActor/LiveActor.h>

class ProjectCameraInput : public al::ICameraInput
{
public:
    ProjectCameraInput(const al::LiveActor*);
};