#pragma once

#include "al/async/FunctorBase.h"
#include "al/execute/ExecutorListBase.h"
#include <sead/container/seadPtrArray.h>

namespace al {

class ExecutorListFunctor : public al::ExecutorListBase {
public:
    sead::PtrArray<al::FunctorBase> mFunctors;
};

}
