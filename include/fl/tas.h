#pragma once

#include <sead/math/seadVector.h>

namespace fl
{
    struct TasFrame
    {
        sead::Vector2f leftStick = sead::Vector2f(0, 0);
        sead::Vector2f rightStick = sead::Vector2f(0, 0);
        bool A:1, B:1, X:1, Y:1;
        bool L:1, R:1, ZL:1, ZR:1;
        bool plus:1, minus:1, pressLeftStick:1, pressRightStick:1;
        bool dUp:1, dRight:1, dDown:1, dLeft:1;
    };

    struct TasHolder
    {
        static TasHolder& instance() {static TasHolder tasHolder; return tasHolder;}

        TasFrame* frames = nullptr;

        bool isRunning = false;
        bool startPending = false;
        s64 curFrame = 0;
        u64 frameCount = 0;

        bool oldMotion = false;

        char* scriptName = nullptr;

        void update();
        void start();
        void stop();
        void setScriptName(char* name);
        void onStageKill();
    };
}
