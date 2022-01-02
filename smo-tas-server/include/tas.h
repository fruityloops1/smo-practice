#pragma once

#include <types.h>
#include <vector>

namespace fl
{
    struct TasFrame
    {
        smo::Vector2f leftStick;
        smo::Vector2f rightStick;
        bool A:1 = false, B:1 = false, X:1 = false, Y:1 = false;
        bool L:1 = false, R:1 = false, ZL:1 = false, ZR:1 = false;
        bool plus:1 = false, minus:1 = false, pressLeftStick:1 = false, pressRightStick:1 = false;
        bool dUp:1 = false, dRight:1 = false, dDown:1 = false, dLeft:1 = false;

        unsigned char padding[2]{0};
    };

    struct TasScript
    {
        std::vector<TasFrame> frames;
    };
}