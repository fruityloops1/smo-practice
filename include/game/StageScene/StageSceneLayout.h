#pragma once

#include "game/Layouts/CoinCounter.h"
#include "game/Layouts/ShineCounter.h"

class StageSceneLayout {
    public:
        unsigned char padding_18[0x18];
        CoinCounter* coinCounter; // 0x18
        unsigned char padding_sus[0x8];
        ShineCounter* shineCounter; //0x20
};