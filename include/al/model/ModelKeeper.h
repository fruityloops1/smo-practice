#pragma once

#include "al/hio/HioNode.h"
#include <sead/math/seadMatrix.h>

namespace al {
class AnimPlayerSkl;
class AnimPlayerMat;
class AnimPlayerVis;
class ActorResource;
class ModelCtrl;
class DitherAnimator;
class ModelLodCtrl;

class ModelKeeper : public al::HioNode {
public:
    void setDisplayRootJointMtxPtr(sead::Matrix34f const*);
    void setModelLodCtrl(al::ModelLodCtrl*);
    void setDitherAnimator(al::DitherAnimator*);

    unsigned char pad[0x8];
    const char* mName;
    al::ModelCtrl* mModelCtrl;
    al::ActorResource* mActorResource;
    al::AnimPlayerSkl* mAnimPlayerSkl;
    al::AnimPlayerMat* mAnimPlayerMat1;
    al::AnimPlayerMat* mAnimPlayerMat2;
    al::AnimPlayerMat* mAnimPlayerMat3;
    al::AnimPlayerMat* mAnimPlayerMat4;
    al::AnimPlayerVis* mAnimPlayerVis1;
    al::AnimPlayerVis* mAnimPlayerVis2;
    sead::Matrix34f* mVar1; // array
    bool bVar1;
    bool bVar2;
    bool bVar3;
    bool bVar4;
};
}
