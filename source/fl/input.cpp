#include "sead/math/seadVector.h"
#include <fl/input.h>
#include <al/util.hpp>
#include <fl/tas.h>
#include <nn/util.h>

long raw_input;
long raw_input_prev;

bool isPressed(int button) {
    return (raw_input & (1 << button)) != 0;
}
bool isPressedPrev(int button) {
    return (raw_input_prev & (1 << button)) != 0;
}
bool isTriggerLeft() {
    return isPressed(12) && !isPressedPrev(12);
}
bool isTriggerUp() {
    return isPressed(13) && !isPressedPrev(13);
}
bool isTriggerRight() {
    return isPressed(14) && !isPressedPrev(14);
}
bool isTriggerDown() {
    return isPressed(15) && !isPressedPrev(15);
}
bool isL() {
    return isPressed(6);
}
bool isTriggerPressLeftStick() {
    return isPressed(4) && !isPressedPrev(4);
}

void controllerHook(nn::hid::NpadBaseState* state) {
    fl::TasHolder& h = fl::TasHolder::instance();
    raw_input_prev = raw_input;
    raw_input = state->mButtons;
    if (!h.isRunning) {
        return;
    }

    state->mButtons = 0;
    if(h.frames[h.curFrame].A) 
        state->mButtons |= (1 << 0);
    if(h.frames[h.curFrame].B) 
        state->mButtons |= (1 << 1);
    if(h.frames[h.curFrame].X) 
        state->mButtons |= (1 << 2);
    if(h.frames[h.curFrame].Y) 
        state->mButtons |= (1 << 3);
    if(h.frames[h.curFrame].pressLeftStick) 
        state->mButtons |= (1 << 4);
    if(h.frames[h.curFrame].pressRightStick) 
        state->mButtons |= (1 << 5);
    if(h.frames[h.curFrame].L) 
        state->mButtons |= (1 << 6);
    if(h.frames[h.curFrame].R) 
        state->mButtons |= (1 << 7);
    if(h.frames[h.curFrame].ZL) 
        state->mButtons |= (1 << 8);
    if(h.frames[h.curFrame].ZR) 
        state->mButtons |= (1 << 9);
    if(h.frames[h.curFrame].plus) 
        state->mButtons |= (1 << 10);
    if(h.frames[h.curFrame].minus) 
        state->mButtons |= (1 << 11);
    if(h.frames[h.curFrame].dLeft) 
        state->mButtons |= (1 << 12);
    if(h.frames[h.curFrame].dUp) 
        state->mButtons |= (1 << 13);
    if(h.frames[h.curFrame].dRight) 
        state->mButtons |= (1 << 14);
    if(h.frames[h.curFrame].dDown) 
        state->mButtons |= (1 << 15);

    if(h.frames[h.curFrame].leftStick.x < -0.5f)
        state->mButtons |= (1 << 16);
    if(h.frames[h.curFrame].leftStick.y > 0.5f)
        state->mButtons |= (1 << 17);
    if(h.frames[h.curFrame].leftStick.x > 0.5f)
        state->mButtons |= (1 << 18);
    if(h.frames[h.curFrame].leftStick.y < -0.5f)
        state->mButtons |= (1 << 19);
        
    if(h.frames[h.curFrame].rightStick.x < -0.5f)
        state->mButtons |= (1 << 20);
    if(h.frames[h.curFrame].rightStick.y > 0.5f)
        state->mButtons |= (1 << 21);
    if(h.frames[h.curFrame].rightStick.x > 0.5f)
        state->mButtons |= (1 << 22);
    if(h.frames[h.curFrame].rightStick.y < -0.5f)
        state->mButtons |= (1 << 23);
    
    // all others unused

    //state->mAnalogStickL = (((long) h.frames[h.curFrame].leftStick.x) & 0xffffffff) | (((long) h.frames[h.curFrame].leftStick.y) << 32);
    //state->mAnalogStickR = (((long) h.frames[h.curFrame].rightStick.x) & 0xffffffff) | (((long) h.frames[h.curFrame].rightStick.y) << 32);
    state->mAnalogStickL = (((long) (h.frames[h.curFrame].leftStick.x * 32767)) & 0xffffffff) | (((long) (h.frames[h.curFrame].leftStick.y * 32767)) << 32);
    state->mAnalogStickR = (((long) (h.frames[h.curFrame].rightStick.x * 32767)) & 0xffffffff) | (((long) (h.frames[h.curFrame].rightStick.y * 32767)) << 32);
}
void fgetNpadStatesHandheld(nn::hid::NpadHandheldState* state, int unk1, const unsigned int& unk2) {
    nn::hid::GetNpadStates(state, unk1, unk2);
    controllerHook(state);
}
void fgetNpadStatesDual(nn::hid::NpadJoyDualState* state, int unk1, const unsigned int& unk2) {
    nn::hid::GetNpadStates(state, unk1, unk2);
    controllerHook(state);
}
void fgetNpadStatesFullKey(nn::hid::NpadFullKeyState* state, int unk1, const unsigned int& unk2) {
    nn::hid::GetNpadStates(state, unk1, unk2);
    controllerHook(state);
}
void fgetNpadStatesJoyLeft(nn::hid::NpadJoyLeftState* state, int unk1, const unsigned int& unk2) {
    nn::hid::GetNpadStates(state, unk1, unk2);
    controllerHook(state);
}
void fgetNpadStatesJoyRight(nn::hid::NpadJoyRightState* state, int unk1, const unsigned int& unk2) {
    nn::hid::GetNpadStates(state, unk1, unk2);
    controllerHook(state);
}
