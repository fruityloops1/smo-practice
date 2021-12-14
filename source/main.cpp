#include "al/util.hpp"
#include "game/Layouts/MapLayout.h"
#include "rs/util.hpp"
#include <fl/ui.h>
#include <fl/server.h>
#include <nn/init.h>
#include <mem.h>

void serverThreadFunc(void* args)
{
    smo::Server* server = (smo::Server*) args;
    nn::TimeSpan w = nn::TimeSpan::FromNanoSeconds(1000000);
    while (true)
    {
        server->handlePacket();
        nn::os::YieldThread();
        nn::os::SleepThread(w);
    }
}

void stageSceneControlHook() {
    __asm ("MOV X19, X0");

    StageScene* stageScene;
    __asm ("MOV %[result], X0" : [result] "=r" (stageScene));
    
    fl::PracticeUI::instance().update(*stageScene);

    #if(SMOVER==100)
    static bool init = false;
    if (!init)
    {
        smo::Server& server = smo::Server::instance();
        nn::os::ThreadType* thread = (nn::os::ThreadType*) nn::init::GetAllocator()->Allocate(sizeof(nn::os::ThreadType));
        const u32 stackSize = 0x5000;
        void* threadStack = aligned_alloc(0x1000, stackSize);
        nn::os::CreateThread(thread, serverThreadFunc, &server, threadStack, stackSize, 16, 0);
        nn::os::SetThreadName(thread, "UDP Thread");
        nn::os::StartThread(thread);
        init = true;
    }
    #endif

    __asm ("MOV X0, %[input]" : [input] "=r" (stageScene));
}

void setGotShineVar(GameDataHolderWriter writer, const ShineInfo* shineInfo)
{
    fl::PracticeUI& ui = fl::PracticeUI::instance();
    if (!ui.shineRefresh)
        writer.mGameDataFile->setGotShine(shineInfo);
}

bool isGotShineVar(GameDataHolderAccessor accessor, const ShineInfo* shineInfo)
{
    return fl::PracticeUI::instance().gotShineRefresh ? false : accessor.mGameDataFile->isGotShine(shineInfo);
}

bool isEnableCheckpointWarpVar(MapLayout* layout)
{
    return fl::PracticeUI::instance().alwaysWarp ? true : layout->isEnableCheckpointWarp();
}

bool isEnableSaveVar(StageScene* stageScene)
{
    return fl::PracticeUI::instance().disableAutoSave ? false : stageScene->isEnableSave();
}

bool isTriggerSnapShotModeVar(const al::IUseSceneObjHolder* objHolder)
{
    return showMenu ? false : rs::isTriggerSnapShotMode(objHolder);
}

bool isTriggerAmiiboModeVar(const al::IUseSceneObjHolder* objHolder)
{
    return showMenu ? false : rs::isTriggerAmiiboMode(objHolder);
}