#pragma once

#include "al/layout/LayoutActor.h"
//#include "al/layout/SimpleLayoutAppearWaitEnd.h"
#include <sead/prim/seadSafeString.h>
#include <sead/container/seadPtrArray.h>

class MapTerrainLayout;
class CommonVerticalList;
namespace al {
class LayoutInitInfo;
class RollParts;
class SimpleLayoutAppearWaitEnd;
}

class ShineListLayout : public al::LayoutActor {
public:
    ShineListLayout(al::LayoutInitInfo const&);
    void appear() override;
    void control() override;
    void appearPosLayout();
    void endPosLayout();

    void up();              // 1
    void upTrigger();       // 2
    void down();            // 3
    void downTrigger();     // 4
    void right();           // 5
    void rightTrigger();    // 6
    void left();            // 7
    void leftTrigger();     // 8
    void decide();          // 9
    void pageDownTrigger(); // 10
    void pageUpTrigger();   // 11

    void calcCursorPos(sead::Vector2f*) const;
    void calcTransOnMap(sead::Vector2f*, sead::Vector3f const&, sead::Matrix44f const&);
    int getSelectedWorldId() const;
    int getWorldShineNum(al::LayoutActor const*, int) const;
    void setSelectedWorld(int);
    void updatePosLayout(bool);
    void updateWorldInfo();

    bool isClosing() const;
    bool isCompleteCollectCoin() const;
    bool isCompleteShine() const;
    bool isEnableChangePage() const;
    bool isEnableInput() const;

    void cancel();
    void changeIn(bool);
    void changeOut(bool);
    void deactivate();
    void jumpAchievement();

    // nerves
    void exeAppear();
    void exeChangeIn();
    void exeChangeOut();
    void exeDeactive();
    void exeEnd();
    void exeList();
    void exeWorldRoll();


    CommonVerticalList* mVerticalList;
    sead::WFixedSafeString<512>* mTxtContent;
    sead::WFixedSafeString<512>* mTxtNumber00;
    sead::WFixedSafeString<512>* mTxtNumber01;
    sead::WFixedSafeString<512>* mTxtValue;
    sead::WFixedSafeString<512>* mTxtIcon;
    sead::FixedSafeString<64>* mOnOff;
    sead::FixedSafeString<64>* mState;
    char16_t** mWorldNames;
    sead::PtrArray<al::SimpleLayoutAppearWaitEnd> mShineListPos;
    sead::PtrArray<al::SimpleLayoutAppearWaitEnd> mShineListPosSelect;
    al::RollParts* mRollParts;
    al::SimpleLayoutAppearWaitEnd* mShineListAchieve;
    int mWorldTotalShineNum;
    int mWorldIdx;
    int mWorldCount;
    int* mTopIndices;
    int* mCursorIndices;
    unsigned char gap1[0x8];
    int mInput;
    int iVar2;
    MapTerrainLayout* mMapTerrainLayout;
    bool bVar1;
    bool bVar2;
    al::LayoutActor* mParCounter00;
    al::LayoutActor* mParCounter01;
    al::LayoutActor* mParFooter;
    int iVar3;
    int mCursorIdx;
    int iVar5;
    int iVar6;
};
