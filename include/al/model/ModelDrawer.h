#pragma once

#include <agl/DrawContext.h>
#include "al/hio/HioNode.h"

namespace al {
class ModelDrawBufferCounter;
class ModelDrawDisplayList;
class MeshDrawerTable;
class GraphicsSystemInfo;
class ModelKeeper;
class ModelCtrl;
class UniformBlock;

class ModelDrawerBase : public al::HioNode {
public:
    ModelDrawerBase(const char*);
    virtual ~ModelDrawerBase();
    virtual void createTable() = 0;
    virtual void draw() const = 0;
    virtual void registerModel(al::ModelCtrl*);
    virtual void addModel(al::ModelCtrl*);
    virtual void removeModel(al::ModelCtrl*);
    virtual void updateModel(al::ModelCtrl*);

    bool addModelToTable(al::ModelCtrl*);
    void createModelDrawDisplayList(int);
    int getDrawBufferIndex() const;
    bool isDraw() const;
    void setDrawInfo(agl::DrawContext*, al::GraphicsSystemInfo const*, al::ModelDrawBufferCounter const*, al::ModelKeeper const*);

    const char* mName;
    agl::DrawContext* mDrawContext;
    al::ModelKeeper* mModelKeeper;
    al::GraphicsSystemInfo* mGraphicsSystemInfo;
    al::ModelDrawBufferCounter* mDrawBufferCounter;
    al::ModelDrawDisplayList* mDrawDisplayList;
    sead::PtrArray<al::ModelCtrl> mTable;
    al::MeshDrawerTable* mMeshDrawerTable;
};

class ModelDrawerBufferUpdate : public al::ModelDrawerBase {
public:
    ModelDrawerBufferUpdate(const char*);
    virtual ~ModelDrawerBufferUpdate();
    void createTable() override;
    void draw() const override;
};

class ModelDrawerChromakey : public al::ModelDrawerBase {
public:
    ModelDrawerChromakey(const char*, bool, bool, bool, bool);
    virtual ~ModelDrawerChromakey();
    void createTable() override;
    void draw() const override;
    void registerModel(al::ModelCtrl*) override;

    bool bVar1;
    bool mIsCharacter;
    bool mIsOpa;
    bool mIsXlu;
};

class ModelDrawerDeferred : public al::ModelDrawerBase {
public:
    ModelDrawerDeferred(const char*, bool, bool, bool, bool);
    virtual ~ModelDrawerDeferred();
    void createTable() override;
    void draw() const override;
    void addModel(al::ModelCtrl*) override;
    void removeModel(al::ModelCtrl*) override;

    bool mIsOnly;
    bool mIsNotXlu;
    bool mIsNotOpa;
    bool mIsMarchingCube;
};

class ModelDrawerDeferredFootPrint : public al::ModelDrawerBase {
public:
    ModelDrawerDeferredFootPrint(const char*);
    virtual ~ModelDrawerDeferredFootPrint();
    void createTable() override;
    void draw() const override;

    sead::GraphicsContextMRT mGraphicsContext;
};

enum SilhouetteDrawCategory {
    Default = 0,
    Ride
};

class ModelDrawerDeferredSilhouette : public al::ModelDrawerBase {
public:
    ModelDrawerDeferredSilhouette(const char*, al::SilhouetteDrawCategory);
    virtual ~ModelDrawerDeferredSilhouette();
    void createTable() override;
    void draw() const override;

    al::SilhouetteDrawCategory mDrawCategory;
    al::UniformBlock* mUniformBlock;
};

class ModelDrawerDeferredSky : public al::ModelDrawerBase {
public:
    ModelDrawerDeferredSky(const char*);
    virtual ~ModelDrawerDeferredSky();
    void createTable() override;
    void draw() const override;

    sead::GraphicsContextMRT mGraphicsContext;
};

class ModelDrawerDepthOnly : public al::ModelDrawerBase {
public:
    ModelDrawerDepthOnly(const char*, bool, bool, bool, bool, bool);
    virtual ~ModelDrawerDepthOnly();
    void createTable() override;
    void draw() const override;
    void registerModel(al::ModelCtrl*) override;
    void addModel(al::ModelCtrl*) override;
    void removeModel(al::ModelCtrl*) override;
    void updateModel(al::ModelCtrl*) override;

    void createTableCulling();

    bool bVar1;
    bool mIsForce;
    bool mIsDither;
    bool mIsXlu;
    bool mIsIndirect;
    bool mIsChromakey;
    bool bVar2;
    al::MeshDrawerTable* uVar1;
};

class ModelDrawerDepthShadow : public al::ModelDrawerBase {
public:
    ModelDrawerDepthShadow(const char*, bool, bool);
    virtual ~ModelDrawerDepthShadow();
    void createTable() override;
    void draw() const override;
    void registerModel(al::ModelCtrl*) override;
    void addModel(al::ModelCtrl*) override;
    void updateModel(al::ModelCtrl*) override;

    bool mIsMarchingCube;
};

class ModelDrawerDepthShadowMap : public al::ModelDrawerBase {
public:
    ModelDrawerDepthShadowMap(const char*);
    virtual ~ModelDrawerDepthShadowMap();
    void createTable() override;
    void draw() const override;
    void removeModel(al::ModelCtrl*) override;
    void updateModel(al::ModelCtrl*) override;
};

class ModelDrawerForward : public al::ModelDrawerBase {
public:
    ModelDrawerForward(const char*, bool, bool, bool, bool, bool, bool);
    virtual ~ModelDrawerForward();
    void createTable() override;
    void draw() const override;
    void addModel(al::ModelCtrl*) override;
    void removeModel(al::ModelCtrl*) override;

    bool mIsOnly;
    bool mIsPostEffectMask;
    bool mIsForce;
    bool mIsIndirect;
    bool bVar1;
    bool bVar2;
};

class ModelDrawerMask : public al::ModelDrawerBase {
public:
    ModelDrawerMask(const char*);
    virtual ~ModelDrawerMask();
    void createTable() override;
    void draw() const override;
    void updateModel(al::ModelCtrl*) override;
};

class ModelDrawerPrepassCulling : public al::ModelDrawerBase {
public:
    ModelDrawerPrepassCulling(const char*);
    virtual ~ModelDrawerPrepassCulling();
    void createTable() override;
    void draw() const override;
    void registerModel(al::ModelCtrl*) override;
    void addModel(al::ModelCtrl*) override;
    void updateModel(al::ModelCtrl*) override;
};

class ModelDrawerStaticDepthShadow : public al::ModelDrawerBase {
public:
    ModelDrawerStaticDepthShadow(const char*);
    virtual ~ModelDrawerStaticDepthShadow();
    void createTable() override;
    void draw() const override;
    void addModel(al::ModelCtrl*) override;
    void removeModel(al::ModelCtrl*) override;
};

class ModelDrawerWorldAo : public al::ModelDrawerBase {
public:
    ModelDrawerWorldAo(const char*);
    virtual ~ModelDrawerWorldAo();
    void createTable() override;
    void draw() const override;
    void addModel(al::ModelCtrl*) override;
    void removeModel(al::ModelCtrl*) override;
};
}
