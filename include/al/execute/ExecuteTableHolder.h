#pragma once

#include "al/execute/ExecuteOrder.h"
#include "al/execute/ExecutorListBase.h"
#include "al/execute/ExecutorListActor.h"
#include "al/execute/ExecutorListActorModelDraw.h"
#include "al/execute/ExecutorListFunctor.h"
#include "al/execute/ExecutorListIUseExecutor.h"
#include "al/execute/ExecutorListLayout.h"
#include "al/hio/HioNode.h"
#include <cstring>
#include <sead/container/seadPtrArray.h>

namespace al {

class ExecuteTableHolderUpdate : public al::HioNode {
public:

};

class ExecuteTableHolderDraw : public al::HioNode {
public:
    virtual ~ExecuteTableHolderDraw();
    ExecuteTableHolderDraw() {
        mName = nullptr;
        memset(&arr1, 0, 0x70);
        debug_Enabled = true;
        debug_ExecuteOrder = nullptr;
        __asm("MOV X0, #0");
        __asm("LDR X0, [X0]");
    }


    void execute() const;

    const char* mName;
    sead::PtrArray<al::ExecutorListBase> arr1;
    sead::PtrArray<al::ExecutorListBase> mListAll;
    sead::PtrArray<al::ExecutorListActorExecuteBase> mListActor;            // useless? some entries have 8 buffer size but no items
    sead::PtrArray<al::ExecutorListActorModelDrawBase> mListActorModel;
    sead::PtrArray<al::ExecutorListLayoutDrawBase> mListLayout;
    sead::PtrArray<al::ExecutorListIUseExecutorBase> mListUser;
    sead::PtrArray<al::ExecutorListFunctor> mListFunctor;
    bool debug_Enabled;
    al::ExecuteOrder* debug_ExecuteOrder;
};

}
