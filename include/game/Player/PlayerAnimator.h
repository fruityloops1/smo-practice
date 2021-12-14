#pragma once

#include "PlayerAnimFrameCtrl.h"
#include "sead/prim/seadSafeString.h"
#include "types.h"

#include <fl/efun.h>

class PlayerAnimator {
    public:
        void startAnim(const sead::SafeStringBase<char>& animName);
        void startAnimCommon(const sead::SafeStringBase<char>&);
        void startSubAnim(const sead::SafeStringBase<char>& animName);
        
        bool isAnim(const sead::SafeStringBase<char> &animName) const;
        bool isSubAnimEnd() const;

        #if(SMOVER==100)
        float getAnimFrame(void) const;
        float getAnimFrameMax(void) const;
        #endif
        #if(SMOVER==130)
        CVEFUN(PlayerAnimator, 0x003CD520, float, getAnimFrame);
        CVEFUN(PlayerAnimator, 0x003CD530, float, getAnimFrameMax);
        #endif
        float getAnimFrameRate(void) const;
        float getSubAnimFrame() const;
        float getBlendWeight(int index);

        void setAnimFrame(float frame);
        void setSubAnimFrame(float frame);
        void setBlendWeight(float, float, float, float, float, float);

        void forceCapOff();
        void forceCapOn();

        unsigned char padding_18[0x18];
        PlayerAnimFrameCtrl* mAnimFrameCtrl;
        undefined8 padding_4;
        char* mCurrentAnim;
        undefined padding_58[0x50];
        char* mCurrentSubAnim;
};