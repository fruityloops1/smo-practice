#include <fl/tas.h>

void fl::TasHolder::update()
{
    if (!isRunning) return;
    if (curFrame + 1 >= frameCount) stop();
    curFrame++;
}

void fl::TasHolder::start(TasFrame* script, size_t scriptLen)
{
    if (isRunning)
    {
        free(script);
        return;
    }
    frames = script;
    frameCount = scriptLen;
    curFrame = 0;
    isRunning = true;
}

void fl::TasHolder::stop()
{
    if (frames) free(frames);
    frames = nullptr;
    curFrame = 0;
    isRunning = false;
    frameCount = 0;
}