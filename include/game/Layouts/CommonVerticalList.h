#pragma once

#include "al/layout/LayoutActor.h"
#include "al/layout/RollParts.h"
#include "al/nerve/NerveExecutor.h"
#include "nn/ui2d/Texture.h"
#include <sead/math/seadVector.h>
#include <sead/container/seadPtrArray.h>

namespace al {
class LayoutInitInfo;
}
class CursorParts;
class RollPartsData;
class ScrollBarParts;

class CommonVerticalList : public al::NerveExecutor {
public:
    CommonVerticalList(al::LayoutActor*, al::LayoutInitInfo const&);
    ~CommonVerticalList();
    void initData(int);
    void initDataNoResetSelected(int);
    void initDataWithIdx(int, int, int);

    void appearCursor();
    void hideCursor();
    void endCursor();

    void up();
    void pageUp();
    void jumpTop();
    void down();
    void pageDown();
    void jumpBottom();
    void rollRight();
    void rollLeft();
    void decide();
    void reject();

    void addGroupAnimData(sead::FixedSafeString<64> const*, const char*);
    void addStringData(sead::WFixedSafeString<512> const*, const char*);
    float calcAnimRate();
    void calcCursorPos(sead::Vector2f*) const;
    int getListPartsNum() const;
    al::RollParts* getParts(int) const;
    int getRollPartsSelected(int) const;
    al::RollParts* getSelectedParts() const;
    void setEnableData(bool const*);
    void setImageData(nn::ui2d::TextureInfo**, const char*);
    void setRollPartsData(RollPartsData*);
    void setRollPartsSelected(int, int);
    void setSelectedIdx(int, int);
    void update();
    void updateCursorPos();
    void updateParts();

    bool isActive() const;
    bool isDeactive() const;
    bool isDecideEnd() const;
    bool isRejectEnd() const;

    void activate();
    void deactivate();
    void hideAll();
    void startLoopActionAll(const char*, const char*);

    void exeActive();
    void exeDeactive();
    void exeDecide();
    void exeDecideEnd();
    void exeReject();
    void exeRejectEnd();

    al::LayoutActor* mLyt;
    sead::PtrArray<al::RollParts> mRollParts;
    CursorParts* mParCursor;
    ScrollBarParts* mParScroll;
    int iVar1;
    int mCursorIdx;
    int mTopIdx;
    int mPrevCursorIdx;
    int mPrevTopIdx;
    float fVar1;
    int mDelayFrame;
    int iVar7;
    float fVar2;
    sead::Vector2f mCursorPos;
    bool bVar1;
    bool bVar2;
    int iVar8;
    sead::WFixedSafeString<512>** mStringData;
    sead::FixedSafeString<128>* uVar1;
    nn::ui2d::TextureInfo** uVar2;
    nn::ui2d::TextureInfo* uVar3;
    bool* mEnableData;
    int mStringDataCount;
    int mItemCount;
    char* sVar1;
    void* mGroupAnimData;
    int mGroupAnimDataCount;
    RollPartsData* mRollPartsData;
    int* mRollPartsSelected;
    float fVar3;
    bool bVar3;
};
