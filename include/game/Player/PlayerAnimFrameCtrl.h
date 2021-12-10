#pragma once

#include <types.h>

class PlayerAnimFrameCtrl {
    public:
        const char *getActionName(void) const;
        undefined unk[0x5c];
        float mCurAnimFrame;
};