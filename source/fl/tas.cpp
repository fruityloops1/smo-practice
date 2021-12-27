#include <fl/tas.h>
#include <mem.h>

void fl::TasHolder::update()
{
    if (!isRunning)
    {
        if (startPending)
        {
            isRunning = true;
            curFrame = 0;
            startPending = false;
        }
        return;
    }
    if (curFrame + 1 >= frameCount) stop();
    curFrame++;
}

void fl::TasHolder::start()
{
    isRunning = true;
}

void fl::TasHolder::stop()
{
    curFrame = 0;
    isRunning = false;
}

void fl::TasHolder::setScriptName(char* name)
{
    if (scriptName) dealloc(scriptName);
    scriptName = name;
}