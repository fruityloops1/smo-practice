#pragma once

namespace al {

class ActorInitInfo;

class ISceneObj {
public:
    virtual const char* getSceneObjName() const = 0;
    virtual ~ISceneObj();
    virtual void initAfterPlacementSceneObj(ActorInitInfo const&) = 0;
    virtual void initSceneObj() = 0;
};

}
