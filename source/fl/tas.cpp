#include <fl/tas.h>
#include <mem.h>

void fl::TasHolder::update()
{
    if (!isRunning) return;
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