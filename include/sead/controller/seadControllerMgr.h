#pragma once

#include "sead/heap/seadDisposer.h"

namespace sead
{

    namespace ControllerDefine
    {
        typedef unsigned int ControllerId;
    };

    class Controller
    {
        
    };
    class ControllerMgr
    {
        SEAD_SINGLETON_DISPOSER(ControllerMgr)
    public:
        int findControllerPort(Controller*);
        Controller* getControllerByOrder(ControllerDefine::ControllerId id, int);

        /*unsigned char padding1[0x188];
        unsigned int controllerAmount; // idk how right this is
        int padding2;*/

    };
}