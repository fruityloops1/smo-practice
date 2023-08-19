#pragma once

#include "al/execute/ExecutorListBase.h"
#include "al/layout/LayoutActor.h"
#include <sead/container/seadPtrArray.h>
#include <sead/gfx/seadContext.h>

namespace al {

class ExecutorListLayoutDrawBase : public al::ExecutorListBase {
public:
    sead::PtrArray<al::LayoutActor> mLytActors;
    unsigned char gap1[0x8];
};

class ExecutorListLayoutDrawNormal : public al::ExecutorListLayoutDrawBase {
public:
    sead::DrawContext* mDrawContext;
};

class ExecutorListLayoutUpdate : public al::ExecutorListBase {
public:
    sead::PtrArray<al::LayoutActor> mLytActors;
};

}
