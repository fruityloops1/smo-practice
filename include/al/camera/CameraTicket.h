#pragma once

#include "al/camera/CameraPoser.h"

namespace al {
class CameraTicketId;

class CameraTicket {
public:
    al::CameraPoser* mPoser;
    al::CameraTicketId* mTicketId;
    int mPriority;
    bool bVar1;
};
}
