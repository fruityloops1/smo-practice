/**
 * @file SoundPlayer.h
 * @brief Sound player.
 */

#pragma once

#include "types.h"

namespace nn
{
    namespace atk
    {
        class SoundHandle;
        class SoundStartable {
        public:
            struct StartInfo;

            bool StartSound(SoundHandle*, const char*, const StartInfo*);
        };
    };
};
