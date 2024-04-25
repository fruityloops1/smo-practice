#pragma once

#include <agl/DrawContext.h>
#include "al/execute/ExecutorActor.h"
#include "al/execute/ExecutorListBase.h"
#include "al/execute/ExecuteSystemInitInfo.h"
#include "al/model/ModelDrawer.h"
#include <sead/container/seadPtrArray.h>

namespace al {
class ExecutorListActorModelDrawBase : public al::ExecutorListBase {
public:
    ExecutorListActorModelDrawBase(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawBase();
    virtual void executeList() const;
    virtual bool isActive() const;
    virtual al::ModelDrawerBase* createDrawer(const char*) const = 0;

    void createList();
    void registerActorModel(al::LiveActor*);

    sead::PtrArray<al::ExecutorActorDraw> mActors;
    agl::DrawContext* mDrawContext;
};

class ExecutorListActorModelDrawCharacterChromakey : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawCharacterChromakey(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawCharacterChromakey();
    al::ModelDrawerChromakey* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawCulling : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawCulling(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawCulling();
    al::ModelDrawerPrepassCulling* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDeferred : public al::ExecutorListActorModelDrawBase{
public:
    ExecutorListActorModelDrawDeferred(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDeferred();
    al::ModelDrawerDeferred* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDeferredFootPrint : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDeferredFootPrint(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDeferredFootPrint();
    al::ModelDrawerDeferredFootPrint* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDeferredMarchingCube : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDeferredMarchingCube(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDeferredMarchingCube();
    al::ModelDrawerDeferred* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDeferredOnly : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDeferredOnly(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDeferredOnly();
    al::ModelDrawerDeferred* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDeferredOpa : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDeferredOpa(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDeferredOpa();
    al::ModelDrawerDeferred* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDeferredSilhouette : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDeferredSilhouette(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDeferredSilhouette();
    al::ModelDrawerDeferredSilhouette* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDeferredSilhouetteRide : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDeferredSilhouetteRide(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDeferredSilhouetteRide();
    al::ModelDrawerDeferredSilhouette* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDeferredSky : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDeferredSky(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDeferredSky();
    al::ModelDrawerDeferredSky* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDeferredXlu : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDeferredXlu(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDeferredXlu();
    al::ModelDrawerDeferred* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDepthChromakey : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDepthChromakey(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDepthChromakey();
    al::ModelDrawerDepthOnly* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDepthDither : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDepthDither(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDepthDither();
    al::ModelDrawerDepthOnly* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDepthDitherIndirect : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDepthDitherIndirect(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDepthDitherIndirect();
    al::ModelDrawerDepthOnly* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDepthForce : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDepthForce(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDepthForce();
    al::ModelDrawerDepthOnly* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDepthIndirect : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDepthIndirect(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDepthIndirect();
    al::ModelDrawerDepthOnly* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDepthOnly : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDepthOnly(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDepthOnly();
    al::ModelDrawerDepthOnly* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDepthShadow : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDepthShadow(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDepthShadow();
    al::ModelDrawerDepthShadow* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDepthShadowMarchingCube : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDepthShadowMarchingCube(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDepthShadowMarchingCube();
    al::ModelDrawerDepthShadow* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDepthXlu : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDepthXlu(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDepthXlu();
    al::ModelDrawerDepthOnly* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawDitherChromakey : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawDitherChromakey(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawDitherChromakey();
    al::ModelDrawerDepthOnly* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawForward : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawForward(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawForward();
    al::ModelDrawerForward* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawForwardForce : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawForwardForce(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawForwardForce();
    al::ModelDrawerForward* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawForwardOnly : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawForwardOnly(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawForwardOnly();
    al::ModelDrawerForward* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawForwardPostEffectMask : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawForwardPostEffectMask(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawForwardPostEffectMask();
    al::ModelDrawerForward* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawIndirect : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawIndirect(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawIndirect();
    al::ModelDrawerForward* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawIndirectOnly : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawIndirectOnly(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawIndirectOnly();
    al::ModelDrawerForward* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawPlayerChromakey : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawPlayerChromakey(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawPlayerChromakey();
    al::ModelDrawerChromakey* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawPlayerChromakeyOpa : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawPlayerChromakeyOpa(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawPlayerChromakeyOpa();
    al::ModelDrawerChromakey* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawPlayerChromakeyXlu : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawPlayerChromakeyXlu(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawPlayerChromakeyXlu();
    al::ModelDrawerChromakey* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawStaticDepthShadow : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawStaticDepthShadow(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawStaticDepthShadow();
    al::ModelDrawerStaticDepthShadow* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawUpdate : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawUpdate(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawUpdate();
    al::ModelDrawerBufferUpdate* createDrawer(const char*) const override;
};

class ExecutorListActorModelDrawWorldAo : public al::ExecutorListActorModelDrawBase {
public:
    ExecutorListActorModelDrawWorldAo(const char*, int, al::ExecuteSystemInitInfo const&);
    virtual ~ExecutorListActorModelDrawWorldAo();
    al::ModelDrawerWorldAo* createDrawer(const char*) const override;
};




}
