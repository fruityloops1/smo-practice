#pragma once

#include "al/hio/HioNode.h"

namespace al
{
    class LiveActor;

    class LiveActorGroup : public al::HioNode
    {
    public:
        LiveActorGroup(const char *, int);

        virtual void registerActor(al::LiveActor *);
        int calcAliveActorNum() const;

        const char* mName;
        sead::PtrArray<al::LiveActor> mActors;
    };
};
