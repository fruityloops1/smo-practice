#pragma once

#include <sead/framework/seadFramework.h>

namespace sead {
class GameFramework : public sead::Framework {
public:
    GameFramework();
    virtual ~GameFramework();

    virtual void createSystemTasks(TaskBase*, const CreateSystemTaskArg&) override;
    virtual void quitRun_(Heap*) override;
    virtual void createControllerMgr(TaskBase*);
    virtual void createHostIOMgr(TaskBase*, HostIOMgr::Parameter*, Heap*);
    virtual void createProcessMeter(TaskBase*);
    virtual void createSeadMenuMgr(TaskBase*);
    virtual void createInfLoopChecker(TaskBase*, TickSpan const&, int);
    virtual void createCuckooClock(TaskBase*);
    virtual float calcFps() = 0;
    virtual void saveScreenShot(SafeString const&);
    virtual bool isScreenShotBusy() const;
    virtual void waitStartDisplayLoop_();
    virtual void initHostIO_();
};


class GameFrameworkNx : public sead::GameFramework {
public:
    virtual float calcFps() override;
};
} // namespace sead
