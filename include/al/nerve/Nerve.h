#pragma once

#include "al/iuse/IUseNerve.h"

namespace al
{
    class NerveKeeper;

    class Nerve
    {
    public:
        virtual void execute(NerveKeeper *) = 0;
        virtual void executeOnEnd(NerveKeeper *) const;
    };
};
