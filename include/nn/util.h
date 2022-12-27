#pragma once

#include "../types.h"

namespace nn {
namespace util {

s32 SNPrintf(char *s, ulong n, const char *format, ...);
s32 VSNPrintf(char *s, ulong n, const char *format, va_list arg);

} // namespace util

namespace hid {
struct NpadBaseState {
  long mSamplingNumber;
  long mButtons;
  long mAnalogStickL;
  long mAnalogStickR;
  int mAttributes;
  int RESERVED;
};

struct NpadHandheldState : NpadBaseState{};
struct NpadJoyDualState : NpadBaseState{};
struct NpadFullKeyState : NpadBaseState{};
struct NpadJoyLeftState : NpadBaseState{};
struct NpadJoyRightState : NpadBaseState{};

void GetNpadStates(NpadHandheldState *, int, const unsigned int &);
void GetNpadStates(NpadJoyDualState *, int, const unsigned int &);
void GetNpadStates(NpadFullKeyState *, int, const unsigned int &);
void GetNpadStates(NpadJoyLeftState *, int, const unsigned int &);
void GetNpadStates(NpadJoyRightState *, int, const unsigned int &);
} // namespace hid

} // namespace nn
