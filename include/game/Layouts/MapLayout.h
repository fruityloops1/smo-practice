#pragma once

#include <fl/efun.h>

class MapLayout
{
public:
    #if SMOVER==100
    bool isEnableCheckpointWarp() const;
    #endif
    #if SMOVER==130
    CVEFUN(MapLayout, 0x001D0B00, bool, isEnableCheckpointWarp);
    #endif
};