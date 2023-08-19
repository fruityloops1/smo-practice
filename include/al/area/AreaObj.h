#pragma once

#include "al/iuse/IUseSceneObjHolder.h"
#include "al/iuse/IUseStageSwitch.h"
#include "al/hio/HioNode.h"
#include <sead/math/seadMatrix.h>

namespace al {
class PlacementInfo;
class AreaShape;
class StageSwitchKeeper;
class SceneObjHolder;

class AreaObj : al::IUseStageSwitch, al::IUseSceneObjHolder, al::HioNode {
public:
    AreaObj(char const *);
    const char* getName() const;
    al::SceneObjHolder* getSceneObjHolder() const;
    al::StageSwitchKeeper* getStageSwitchKeeper() const;
    //void init(al::AreaInitInfo const &);
    void initStageSwitchKeeper();
    void invalidate();
    bool isInVolume(sead::Vector3f const &) const;
    bool isInVolumeOffset(sead::Vector3f const &, float) const;
    void validate();

    const char* mName;
    al::AreaShape* mAreaShape;
    al::StageSwitchKeeper* mStageSwitchKeeper;
    al::SceneObjHolder* mSceneObjHolder;
    sead::Matrix34f mAreaMtx;
    al::PlacementInfo* mPlacementInfo;
    int mPriority;
    bool mIsValid;
};

}
