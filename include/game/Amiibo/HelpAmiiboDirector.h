#pragma once

#include "game/Amiibo/HelpAmiiboCoinCollect.h"
#include <types.h>

class HelpAmiiboDirector
{
public:
    spad(gap, 0x60);
    HelpAmiiboCoinCollect* mHelpAmiiboCoinCollect;

    void appearCoinCollectEffect();
};