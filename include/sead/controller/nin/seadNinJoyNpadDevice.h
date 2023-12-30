#pragma once

#include "controller/seadControlDevice.h"
#include "controller/seadController.h"
#include "heap/seadHeap.h"

namespace nn::hid {

typedef int NpadJoyHoldType;

}

namespace sead
{
// stubbed and only added methods for seadControllerMgr
class NinJoyNpadDevice : public ControlDevice
{
public:
    NinJoyNpadDevice(ControllerMgr* mgr, Heap* heap);

    void calc() override;

//private:
  int mNpadIdUpdateNum;
  nn::hid::NpadJoyHoldType mNpadJoyHoldType;
  void *SEAD_NINJOYNPADDEVICE[4261];
};

}  // namespace sead
