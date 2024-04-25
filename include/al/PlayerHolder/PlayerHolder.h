#pragma once

#include "sead/math/seadVector.h"
#include "al/scene/Scene.h"
#include "al/PlayerHolder/PlayerHolder.h"
#include "al/LiveActor/LiveActor.h"
#include "types.h"



namespace al {

    class PadRumbleKeeper;

    class PlayerHolder {
        public:
            PlayerHolder(int);
            al::LiveActor *getPlayer(int);
            al::LiveActor* tryGetPlayer(int) const;
            int *getPlayerNum() const;
            int *getBufferSize() const;
            void registerPlayer(al::LiveActor *, al::PadRumbleKeeper *);
    };
}
