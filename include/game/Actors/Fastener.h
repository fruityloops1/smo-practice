#include "al/LiveActor/LiveActor.h"
#include "al/camera/CameraTicket.h"
#include "al/rail/Rail.h"
#include "al/rail/RailRider.h"
#include <sead/container/seadPtrArray.h>

class CapTargetInfo;
class FixMapParts;

class FastenerRailKeeper : public al::LiveActor {
public:
    al::LiveActor* mFastener;
    al::Rail* mRail;
    al::RailRider* mRailRider;
    float fVar1;
    bool mIsShowLine;
    sead::PtrArray<al::CameraTicket> mCameraTickets;
    bool mIsFastener;
    bool mIsMesh;
    bool mIsInvalid;
    bool mIsUncutable;
    bool mIsLimitY;
    bool mIsFixXZ;
    bool mIsMeshInvisible;
    bool mIsSplit;
    int mSplitLevel;
    FixMapParts* mMeshModel;
    char gap1[0xb0];
};


class Fastener : public al::LiveActor {
public:
    CapTargetInfo* mCapTargetInfo;
    sead::PtrArray<FastenerRailKeeper> mRailKeeperArray;
    FastenerRailKeeper* mRailKeepers[0x80];
    sead::PtrArrayImpl mArray2;
};
