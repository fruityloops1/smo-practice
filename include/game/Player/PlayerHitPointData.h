#pragma once

#include <fl/efun.h>

class PlayerHitPointData
{
public:
    #if(SMOVER==100)
    void getMaxUpItem();
    void recover();
    #endif
    #if(SMOVER==130)
    VVCEFUN(PlayerHitPointData, 0x004E49E0, getMaxUpItem);
    VVCEFUN(PlayerHitPointData, 0x004E49E0, recover);
    #endif
};