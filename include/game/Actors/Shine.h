#pragma once

#include "types.h"

#include "game/Info/ShineInfo.h"
#include "game/Interfaces/IUseDimension.h"
#include "al/LiveActor/LiveActor.h"

class Shine : public al::LiveActor , public IUseDimension {
    public:
        Shine(const char *actorName);

        void offAppear();
        void onAppear();
        
        void getDirectWithDemo(void);
        void getDirect();
        void get();

        void onSwitchGet(void);
        
        bool isGot() const;

        void setGrandShine(void);
        
        undefined padding[0x120 - 0xD0];
        ShineInfo *curShineInfo; // 0x120
        undefined padding_290[0x290 - 0x128];
        int shineId; // 0x290
};