#include "sead/math/seadVector.h"
#include <al/util.hpp>
#include <fl/tas.h>
#include <fl/input.h>

#if(SMOVER==100)

#define PADTRIGGER(BUTTON, PNAME) bool fisPadTrigger##BUTTON(int port) {\
                               fl::TasHolder& h = fl::TasHolder::instance();\
                               if (h.isRunning) {\
                                   if (h.curFrame == 0) return h.frames[0].PNAME;\
                                   return !h.frames[h.curFrame - 1].PNAME && h.frames[h.curFrame].PNAME;\
                               } else return al::isPadTrigger##BUTTON(port);}

#define PADHOLD(BUTTON, PNAME) bool fisPadHold##BUTTON(int port) {\
                            fl::TasHolder& h = fl::TasHolder::instance();\
                            if (h.isRunning) {\
                                if (h.curFrame == 0) return false;\
                                return h.frames[h.curFrame].PNAME;\
                            } else return al::isPadHold##BUTTON(port);}

#define PADRELEASE(BUTTON, PNAME) bool fisPadRelease##BUTTON(int port) {\
                               fl::TasHolder& h = fl::TasHolder::instance();\
                               if (h.isRunning) {\
                                   if (h.curFrame <= 1) return false;\
                                   return h.frames[h.curFrame - 1].PNAME && !h.frames[h.curFrame].PNAME;\
                               } else return al::isPadRelease##BUTTON(port);}

sead::Vector2f* fgetLeftStick(int port)
{
    fl::TasHolder& h = fl::TasHolder::instance();
    return h.isRunning ? &h.frames[h.curFrame].leftStick : al::getLeftStick(port);
}
sead::Vector2f* fgetRightStick(int port)
{
    fl::TasHolder& h = fl::TasHolder::instance();
    return h.isRunning ? &h.frames[h.curFrame].rightStick : al::getRightStick(port);
}

PADTRIGGER(A, A);
PADTRIGGER(B, B);
PADTRIGGER(X, X);
PADTRIGGER(Y, Y);
PADTRIGGER(L, L);
PADTRIGGER(R, R);
PADTRIGGER(ZL, ZL);
PADTRIGGER(ZR, ZR);
PADTRIGGER(PressLeftStick, pressLeftStick);
PADTRIGGER(PressRightStick, pressRightStick);
PADTRIGGER(Plus, plus);
PADTRIGGER(Minus, minus);
PADTRIGGER(Up, dUp);
PADTRIGGER(Right, dRight);
PADTRIGGER(Down, dDown);
PADTRIGGER(Left, dLeft);

PADHOLD(A, A);
PADHOLD(B, B);
PADHOLD(X, X);
PADHOLD(Y, Y);
PADHOLD(L, L);
PADHOLD(R, R);
PADHOLD(ZL, ZL);
PADHOLD(ZR, ZR);
PADHOLD(PressLeftStick, pressLeftStick);
PADHOLD(PressRightStick, pressRightStick);
PADHOLD(Plus, plus);
PADHOLD(Minus, minus);
PADHOLD(Up, dUp);
PADHOLD(Right, dRight);
PADHOLD(Down, dDown);
PADHOLD(Left, dLeft);

PADRELEASE(A, A);
PADRELEASE(B, B);
PADRELEASE(X, X);
PADRELEASE(Y, Y);
PADRELEASE(L, L);
PADRELEASE(R, R);
PADRELEASE(ZL, ZL);
PADRELEASE(ZR, ZR);
PADRELEASE(PressLeftStick, pressLeftStick);
PADRELEASE(PressRightStick, pressRightStick);
PADRELEASE(Plus, plus);
PADRELEASE(Minus, minus);
PADRELEASE(Up, dUp);
PADRELEASE(Right, dRight);
PADRELEASE(Down, dDown);
PADRELEASE(Left, dLeft);

#endif