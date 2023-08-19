#pragma once

#include "al/layout/LayoutActor.h"

namespace al {
class LayoutInitInfo;

class RollParts : public al::LayoutActor {
public:
    RollParts(al::LayoutActor*, al::LayoutInitInfo const&, const char*);

    void activate();
    void activate(int);
    void calcCursorTrans(sead::Vector2f*) const;
    void deactivate();
    bool isJustChangeRoll() const;
    bool isRoll() const;
    void rollLeft();
    void rollRight();
    void setData(char16_t const**, int, bool, int, const char*);
    void setSelectedIdx(int);
    void startLoopAction(const char*, const char*);
    void updateHeaderText();

    char16_t** mData;
    int mDataCount;
    int iVar1;
    bool bVar1;
    const char* sVar1;
    const char* sVar2;
    const char* mActionChange;
    const char* mActionSelect;
    const char* mActionWait;
    const char* mActionRightIn;
    const char* mActionLeftOut;
    const char* mActionRightOut;
    const char* mActionLeftIn;
    int iVar2;
    int iVar3;
    bool bVar2;
};
}
