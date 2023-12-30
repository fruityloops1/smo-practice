#pragma once

#include "al/nerve/NerveExecutor.h"
#include "al/LiveActor/LiveActor.h"

namespace al {
    class NerveStateBase : public NerveExecutor {
    public:
        NerveStateBase(const char *);

        virtual ~NerveStateBase();
        virtual void init();
        virtual void appear();
        virtual void kill();
        virtual bool update();
        virtual void control();

        bool mIsDead = true;
    };

    class ActorStateBase : public al::NerveStateBase {
    public:
        ActorStateBase(const char*, al::LiveActor*);

    private:
        LiveActor* mLiveActor;
};
};
