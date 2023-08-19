#pragma once

namespace al {
class EffectInfo;

class EffectUserInfo {
public:
    EffectUserInfo();

    const char* mName;
    int mEffectCount;
    int iVar1;
    al::EffectInfo* mEffectInfo;
    int _18;
    int _1C;
    unsigned long _20;
    unsigned long _28;
};
}
