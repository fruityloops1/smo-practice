#pragma once

#include <sead/heap/seadDisposer.h>

namespace al {
    class SystemKit;
    class GameFrameworkNx;
    class DrawSystemInfo;
    class AccountHolder;
}

class Application : public sead::IDisposer {
public:
    static const Application* sInstance;

    al::SystemKit* mSystemKit;
    al::GameFrameworkNx *mFramework;
    al::DrawSystemInfo* mDrawSystemInfo;
    al::AccountHolder* mAccountHolder;
};
// const Application *Application::sInstance;
