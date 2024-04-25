#pragma once

#include "al/hio/HioNode.h"
#include "al/LiveActor/LiveActor.h"
#include <sead/container/seadPtrArray.h>

namespace al {
class ExecutorActorExecuteBase : public al::HioNode {
public:
    virtual void execute() const = 0;

    const char* mName;
    sead::PtrArray<al::LiveActor> mActors;
};

class ExecutorActorDraw : public al::ExecutorActorExecuteBase {

};

}
