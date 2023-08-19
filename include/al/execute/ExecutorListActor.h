#pragma once

#include "al/execute/ExecutorActor.h"
#include "al/execute/ExecutorListBase.h"
#include <sead/container/seadPtrArray.h>

namespace al {

class ExecutorListActorExecuteBase : public al::ExecutorListBase {
public:
    sead::PtrArray<al::ExecutorActorExecuteBase> mActors;
};

class ExecutorListActorDraw : public al::ExecutorListActorExecuteBase {

};

}
