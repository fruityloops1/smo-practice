#pragma once

#include <fl/efun.h>

class PlayerDamageKeeper
{
public:
    #if(SMOVER==100)
    void activatePreventDamage();
    void dead();
    void damage(int level);
    void damageForce(int level);
    #endif
    #if(SMOVER==130)
    VVCEFUN(PlayerDamageKeeper, 0x003E2850, dead);
    VVCEFUN(PlayerDamageKeeper, 0x003E28B0, activatePreventDamage);
    VCEFUN(PlayerDamageKeeper, 0x003E25B0, damage, EFUN_ARGS(int amount), EFUN_ARGS(amount));
    #endif
};
