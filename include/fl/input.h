#pragma once

extern long raw_input;
extern long raw_input_prev;
extern long ext_input;

bool isPressed(int button);
bool isPressedPrev(int button);
bool isTriggerLeft();
bool isTriggerRight();
bool isTriggerUp();
bool isTriggerDown();
bool isHoldLeft();
bool isHoldRight();
bool isHoldUp();
bool isHoldDown();
bool isHoldA();
bool isHoldB();
bool isL();
bool isTriggerPressLeftStick();
