#pragma once

namespace al
{
    class LiveActor;

    class AreaObj {

    };

}

namespace sead {
    class LogicalFrameBuffer;
}

#include "sead/math/seadVector.h"
#include "sead/prim/seadSafeString.h"
#include "sead/heap/seadHeap.h"
#include "sead/basis/seadNew.hpp"
#include "sead/gfx/seadContext.h"

#include "al/scene/Scene.h"
#include "al/PlayerHolder/PlayerHolder.h"
#include "al/audio/AudioKeeper.h"
#include "al/camera/Projection.h"
#include "al/camera/CameraTargetBase.h"
#include "al/layout/IUseLayout.h"
#include "al/layout/LayoutKit.h"
#include "al/layout/LayoutActor.h"
#include "al/sensor/SensorMsg.h"
#include "al/stage/StageInfo.h"
#include "al/area/AreaObjGroup.h"

#include "game/Player/PlayerActorHakoniwa.h"

#include "agl/DrawContext.h"

#include "nn/ui2d/Texture.h"

#include "types.h"

#include <fl/efun.h>

template<class T>
al::LiveActor* createActorFunction(const char *name);

namespace al
{

    // General Input functions

    bool isPadTriggerUp(int port);
    bool isPadTriggerDown(int port);
    bool isPadTriggerLeft(int port);
    bool isPadTriggerPressLeftStick(int port);
    bool isPadTriggerRight(int port);

    #if(S2VER==100)
    bool isPadTriggerA(int port);
    #endif
    #if(S2VER==130)
    EFUN(0x005CFBD0, bool, isPadTriggerA, EFUN_ARGS(int port)); 
    #endif
    bool isPadTriggerB(int port);
    bool isPadTriggerX(int port);
    bool isPadTriggerY(int port);

    bool isPadTriggerZL(int port);
    bool isPadTriggerZR(int port);

    bool isPadTriggerL(int port);
    bool isPadTriggerR(int port);

    bool isPadHoldUp(int port);
    bool isPadHoldDown(int port);
    bool isPadHoldLeft(int port);
    bool isPadHoldLeftLeftStick(int port);
    bool isPadHoldRight(int port);

    bool isPadHoldA(int port);
    bool isPadHoldB(int port);
    bool isPadHoldX(int port);
    bool isPadHoldY(int port);

    bool isPadHoldL(int port);
    bool isPadHoldR(int port);

    bool isPadHoldZL(int port);
    bool isPadHoldZR(int port);
    bool isPadReleaseLeftLeftStick(int port);

    sead::Vector2f *getLeftStick(int);
    sead::Vector2f *getRightStick(int);

    // getters
    
    sead::Vector3f *getTrans(al::LiveActor const *);

    sead::Vector3f *getTransPtr(al::LiveActor *);

    sead::Vector3f *getGravity(al::LiveActor const *);

    sead::Vector3f *getUp(al::LiveActor const *);

    sead::Vector3f *getUpPtr(al::LiveActor *);

    sead::Vector3f *getFront(al::LiveActor const *);

    sead::Vector3f *getCameraUp(al::IUseCamera const *, int);

    sead::Vector3f *getScale(al::LiveActor const *);

    float *getScaleX(al::LiveActor const *);

    float *getScaleY(al::LiveActor const *);

    float *getScaleZ(al::LiveActor const *);

    al::PlayerHolder *getScenePlayerHolder(al::Scene const *);

    PlayerActorHakoniwa *getPlayerActor(al::LiveActor const *, int);

    PlayerActorHakoniwa *tryGetPlayerActor(al::PlayerHolder const *, int);

    sead::Heap *getCurrentHeap(void);

    al::Projection *getProjection(al::IUseCamera const *, int);

    int getSubActorNum(al::LiveActor const *);

    al::LiveActor *getSubActor(al::LiveActor const *, int);

    sead::Vector3f *getVelocity(al::LiveActor const *);

    sead::Quatf *getQuat(al::LiveActor const *);

    int getPlayerControllerPort(int);

    char const *getActionName(al::LiveActor const *);

    char const *getActionFrame(al::LiveActor const *);

    // setters

    void setTransY(al::LiveActor *, float);

    #if(S2VER==100)
    void setTrans(al::LiveActor *, sead::Vector3f const &);
    #endif
    #if(S2VER==130)
    EFUN(0x0066D6D0, void, setTrans, EFUN_ARGS(const al::LiveActor* actor, const sead::Vector3f& trans));
    #endif

    void setScaleAll(al::LiveActor *, float);

    void setGravity(al::LiveActor const *, sead::Vector3f const &);

    void setFront(al::LiveActor *, sead::Vector3f const &);

    void setQuat(al::LiveActor *, const sead::Quatf &);

    void updatePoseQuat(al::LiveActor*, const sead::Quatf&);

    void setVelocityZero(al::LiveActor *);

    void setEffectParticleScale(al::IUseEffectKeeper *actor, char const *effectName, float scale);

    // layout stuff

    void setPaneTexture(al::IUseLayout *, char const *, nn::ui2d::TextureInfo const *);

    //void setPaneString(al::IUseLayout *layout, char const *paneName, char16_t const *, ushort);

    void setPaneStringFormat(al::IUseLayout *layout, char const *paneName, char const *format,...);

    void setPaneLocalTrans(al::IUseLayout *layout, const char *paneName, sead::Vector3f const &);
    void setPaneLocalTrans(al::IUseLayout *layout, const char *paneName, sead::Vector2f const &);
    void setPaneLocalSize(al::IUseLayout *layout, const char *paneName, sead::Vector2f const &);
    void setPaneLocalScale(al::IUseLayout *layout, const char *paneName, sead::Vector2f const &);
    void setPaneLocalRotate(al::IUseLayout *layout, const char *paneName, sead::Vector3f const &);

    sead::Vector2f getPaneLocalTrans(al::IUseLayout *layout, const char *paneName);
    sead::Vector2f getPaneLocalSize(al::IUseLayout *layout, const char *paneName);
    sead::Vector2f getPaneLocalScale(al::IUseLayout *layout, const char *paneName);
    sead::Vector2f getPaneLocalRotate(al::IUseLayout *layout, const char *paneName);

    bool killLayoutIfActive(al::LayoutActor *);

    void hidePane(al::IUseLayout *lyt, const char *paneName);

    bool isHidePane(al::IUseLayout const *lyt, const char *paneName);

    void showPane(al::IUseLayout *lyt, const char *paneName);

    // camera stuff

    void setCameraTarget(al::IUseCamera *, al::CameraTargetBase *);

    // calc functions

    f32 calcSpeed(al::LiveActor const *);

    f32 calcSpeedH(al::LiveActor const *);
    
    f32 calcSpeedV(al::LiveActor const *);

    f32 calcDistance(al::LiveActor const *, al::LiveActor const*); // calculates distance between two actors

    f32 calcDistance(al::LiveActor const *, sead::Vector3f const&); // calculates distance between an actor and a position in the world

    void calcFrontDir(sead::Vector3f *result, al::LiveActor const *actor);

    // velocity stuff

    void addVelocity(al::LiveActor *,sead::Vector3f const&);

    void setVelocity(al::LiveActor *,sead::Vector3f const&);

    void scaleVelocityExceptDirection(al::LiveActor *,sead::Vector3f const&, float);

    void addVelocityToGravity(al::LiveActor *, float);

    // animation stuff

    const char * getPlayingSklAnimName(const al::LiveActor *actor, int index);

    bool tryStartSklAnimIfNotPlaying(al::LiveActor *actor, const char * animName);
    
    bool tryStartSklAnimIfExist(al::LiveActor *actor, const char * animName);

    // byml stuff

    bool tryGetByamlF32(float *, al::ByamlIter const&, char const*);

    f32 findActorParamF32(al::LiveActor const*,char const*);
    s32 findActorParamS32(al::LiveActor const*,char const*);

    // nerve stuff

    bool isLessStep(al::IUseNerve const*,int); // checks if the current nerve has been activated for a certain amount of frames(?)

    bool isFirstStep(al::IUseNerve const *);

    bool isNerve(al::IUseNerve const*, al::Nerve const*);

    void setNerve(al::IUseNerve *,al::Nerve const*);

    // effect stuff

    void emitEffect(al::IUseEffectKeeper *effectKeeper, char const *effectName, sead::Vector3f const *effectPosition);
    
    bool tryEmitEffect(al::IUseEffectKeeper *effectKeeper, char const *effectName, sead::Vector3f const *effectPosition);

    void tryDeleteEffect(al::IUseEffectKeeper *effectKeeper, char const *effectName);

    // sensor stuff

    // enum SensorType {
    //     Unknown, // 0
    //     Player, // 1
    //     PlayerAttack, // 2
    //     PlayerFoot // 3
    // };
    
    void addHitSensor(al::LiveActor *actor, al::ActorInitInfo const &initInfo, char const *sensorName, unsigned int typeEnum, float radius, unsigned short maxCount, sead::Vector3f const& position);

    bool isMsgPlayerTrampleReflect(al::SensorMsg const *);

    bool isSensorPlayerAttack(al::HitSensor const *targetSensor);

    bool sendMsgPlayerHipDropKnockDown(al::HitSensor *target, al::HitSensor *source);

    // audio

    void tryPauseBgmIfLowPriority(al::IUseAudioKeeper const *keeper, const char *audioName, int unk);    

    // player stuff

    void tryGetPlacementInfoAndCount(al::PlacementInfo *, int *, al::StageInfo const*, char const*);

    void getClassName(const char **namePtr, const al::ActorInitInfo &info);

    void getDisplayName(const char **namePtr, const al::ActorInitInfo &info);

    // stage switch stuff

    // misc

    al::AreaObjGroup *tryFindAreaObjGroup(al::IUseAreaObj const *, const char *areaName);

    sead::DrawContext *getSceneDrawContext(al::Scene const*); // these two things are all thats needed to setup text writer in the right context

    sead::LogicalFrameBuffer *getSceneFrameBufferMain(al::Scene const*);

    int getLayoutDisplayWidth();
    int getLayoutDisplayHeight();

    void executeDraw(al::LayoutKit const *, char const *);

    bool isExistFile(sead::SafeString const &filePath);

    al::StageInfo *getStageInfoMap(al::Scene const*,int);

    void tryGetObjectName(const char **, al::ActorInitInfo const &);

    bool isVisAnimExist(const al::LiveActor *, const char *);

    bool isInAreaObj(al::LiveActor const *, const char *);

    al::AreaObj *tryFindAreaObj(al::LiveActor const *, const char *);

    void tryGetAreaObjArg(int *, al::AreaObj const *, const char *);
    void tryGetAreaObjArg(float *, al::AreaObj const *, const char *);
    void tryGetAreaObjArg(bool *, al::AreaObj const *, const char *);

    void tryGetAreaObjStringArg(const char **, al::AreaObj const *, const char *);

    void offCollide(al::LiveActor *);
    void onCollide(al::LiveActor *);

    void startAction(al::LiveActor *, char const *);

    bool tryStartSe(al::IUseAudioKeeper const *, sead::SafeStringBase<char> const &);

    void startSe(al::IUseAudioKeeper const *, sead::SafeStringBase<char> const &);

    void startHitReaction(al::LiveActor const *, char const*);

    bool isInDeathArea(al::LiveActor const *);

    void calcCameraUpDir(sead::Vector3f *, al::IUseCamera const*, int);

    const unsigned char *tryGetBymlFromArcName(sead::SafeStringBase<char> const &, sead::SafeStringBase<char> const &);

    class ActorInitInfo;

    bool getArg(int *, const al::ActorInitInfo &, const char *);

    bool isActiveDemo(const al::Scene *);

    bool isEqualString(char const *, char const *);

    bool isEqualSubString(char const *, char const *);

    bool isOnGround(al::LiveActor const*, unsigned int);

    bool isActiveDemo(al::Scene const *);

    bool isInWaterPos(al::LiveActor const*, sead::Vector3f const &);

    // interpolation functions

    void lerpVec(sead::Vector3f *result, sead::Vector3f const& from, sead::Vector3f const& to, float rate);

    void slerpQuat(sead::Quatf *result, sead::Quatf const& from, sead::Quatf const& to, float rate);
    
    // dither anim stuff

    bool isExistDitherAnimator(al::LiveActor const *);

    void stopDitherAnimAutoCtrl(al::LiveActor *);
    void restartDitherAnimAutoCtrl(al::LiveActor *);

    void validateDitherAnim(al::LiveActor *);
    void invalidateDitherAnim(al::LiveActor *);

    float getDitherAnimNearClipStartDistance(al::LiveActor const *);
    float getDitherAnimNearClipEndDistance(al::LiveActor const *);

    void setDitherAnimSphereRadius(al::LiveActor *, float);
    void setDitherAnimBoundingBox(al::LiveActor *, sead::Vector3f const&);
    void setDitherAnimMaxAlpha(al::LiveActor *, float);
    void setDitherAnimClippingJudgeLocalOffset(al::LiveActor *, sead::Vector3f const&);
    void setDitherAnimClippingJudgeParam(al::LiveActor *, const char *);

}
