#include <fl/tas.h>
#include <mem.h>

void fl::TasHolder::update()
{
    if(!isRunning) return;
    
    if (curFrame + 1 >= frameCount && curFrame >= 0) stop();
    curFrame++;
}

void fl::TasHolder::onStageKill()
{
    if(startPending) {
        start();
        curFrame = -1;
    }
}

void fl::TasHolder::start()
{
    startPending = false;
    curFrame = 0;
    isRunning = true;
}

void fl::TasHolder::stop()
{
    startPending = false;
    curFrame = 0;
    isRunning = false;
}

void fl::TasHolder::setScriptName(char* name)
{
    if (scriptName) dealloc(scriptName);
    scriptName = name;
}
