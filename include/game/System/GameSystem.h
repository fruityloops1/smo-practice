#pragma once

#include "game/System/GameSystemInfo.h"
#include "al/nerve/NerveExecutor.h"

class GameSystem : public al::NerveExecutor {
    public:
        void init();
        void *gap;
        GameSystemInfo *mSystemInfo; // 0x18
};