#pragma once

#include <fl/efun.h>

class PlayerDamageKeeper
{
public:
    #if(SMOVER==100)
    void activatePreventDamage();
    void dead();
    void damage(int level);
    #endif
    #if(SMOVER==130)
    VVCEFUN(PlayerDamageKeeper, 0x003E2850, dead);
    VVCEFUN(PlayerDamageKeeper, 0x003E28b0, activatePreventDamage); // fix
    #endif
};