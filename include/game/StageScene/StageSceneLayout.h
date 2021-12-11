#pragma once

#include "game/Layouts/CoinCounter.h"
#include "game/Layouts/ShineCounter.h"
#include <types.h>

class StageSceneLayout {
    public:
        spad(gap, 0x18);
        CoinCounter* coinCounter; // 0x18
        spad(gap2, 0x8);
        ShineCounter* shineCounter; //0x20
};