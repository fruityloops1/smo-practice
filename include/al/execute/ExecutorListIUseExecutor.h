#pragma once

#include "al/execute/ExecutorListBase.h"
#include "al/iuse/IUseExecutor.h"
#include <sead/container/seadPtrArray.h>

namespace al {

class ExecutorListIUseExecutorBase : public al::ExecutorListBase {
public:
    sead::PtrArray<al::IUseExecutor> mUsers;
};

class ExecutorListIUseExecutorDraw : public al::ExecutorListIUseExecutorBase {

};

class ExecutorListIUseExecutorUpdate : public al::ExecutorListIUseExecutorBase {

};

}
