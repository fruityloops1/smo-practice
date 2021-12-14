#include "debugMenu.hpp"
#include "fl/ui.h"
#include <al/util.hpp>

// These files must exist in your romfs! they are not there by default, and must be added in order for the debug font to work correctly.
static const char *DBG_FONT_PATH = "DebugData/Font/nvn_font_jis1.ntx";
static const char *DBG_SHADER_PATH = "DebugData/Font/nvn_font_shader_jis1.bin";
static const char *DBG_TBL_PATH = "DebugData/Font/nvn_font_jis1_tbl.bin";

sead::TextWriter *gTextWriter;

bool showMenu = true;
bool isInGame = false;

void setupDebugMenu(GameSystem *gSys) {

    //gLogger->LOG("Preparing Debug Menu.\n");

    sead::Heap *curHeap = al::getCurrentHeap();

    agl::DrawContext *context = gSys->mSystemInfo->mDrawInfo->mDrawContext;

    if(curHeap) {
        if(context) {
            //gLogger->LOG("Creating Debug Font Instance.\n");

            sead::DebugFontMgrJis1Nvn::sInstance = sead::DebugFontMgrJis1Nvn::createInstance(curHeap);

            //gLogger->LOG("Checking if Paths Exist: {%s} {%s} {%s}\n", DBG_FONT_PATH, DBG_SHADER_PATH, DBG_TBL_PATH);

            if(al::isExistFile(DBG_FONT_PATH) && al::isExistFile(DBG_SHADER_PATH) && al::isExistFile(DBG_TBL_PATH)) {

                //gLogger->LOG("Found All Files in Debug Directory!\n");

                sead::DebugFontMgrJis1Nvn::sInstance->initialize(curHeap, DBG_SHADER_PATH, DBG_FONT_PATH, DBG_TBL_PATH, 0x100000);

                //gLogger->LOG("Initialized Instance!\n");

                sead::TextWriter::setDefaultFont(sead::DebugFontMgrJis1Nvn::sInstance);

                //gLogger->LOG("Set Default Text Writer Font!\n");

                gTextWriter = new sead::TextWriter(context);

                //gLogger->LOG("Created Text Writer!\n");

                gTextWriter->setupGraphics(context);

                //gLogger->LOG("Setup Graphics!\n");
                
            }
        }else {
            //gLogger->LOG("Failed to get Context!\n");
        }
    }else {
        //gLogger->LOG("Failed to get Heap!\n");
    }

    __asm("MOV W23, #0x3F800000");
    __asm("MOV W8, #0xFFFFFFFF");
}

void drawBackground(agl::DrawContext *context) {

    sead::Vector3<float> p1; // top left
    p1.x = -1.0;
    p1.y = -0.05;
    p1.z = 0.0;
    sead::Vector3<float> p2; // top right
    p2.x = -0.1;
    p2.y = -0.05;
    p2.z = 0.0;
    sead::Vector3<float> p3; // bottom left
    p3.x = -1.0;
    p3.y = -1.0;
    p3.z = 0.0;
    sead::Vector3<float> p4; // bottom right
    p4.x = -0.1;
    p4.y = -1.0;
    p4.z = 0.0;

    sead::Color4f c;
    c.r = 0.0;
    c.g = 0.0;
    c.b = 0.0;
    c.a = 0.5; 

    agl::utl::DevTools::beginDrawImm(context, sead::Matrix34<float>::ident, sead::Matrix44<float>::ident);
    agl::utl::DevTools::drawTriangleImm(context, p1, p2, p3, c);
    agl::utl::DevTools::drawTriangleImm(context, p3, p4, p2, c);
}

void drawMainHook(HakoniwaSequence *curSequence, sead::Viewport *viewport, sead::DrawContext *drawContext) {

    if(!showMenu) {
        al::executeDraw(curSequence->mLytKit, "２Ｄバック（メイン画面）");
        return;
    }

    int dispWidth = al::getLayoutDisplayWidth();
    int dispHeight = al::getLayoutDisplayHeight();

    gTextWriter->mViewport = viewport;

    gTextWriter->mColor = sead::Color4f(
        1.f,
        1.f,
        1.f,
        0.8f
    );

    al::Scene *curScene = curSequence->curScene;

    if(curScene && isInGame) {

        drawBackground((agl::DrawContext *)drawContext);

        al::PlayerHolder *pHolder = al::getScenePlayerHolder(curScene);
        PlayerActorHakoniwa *player = al::tryGetPlayerActor(pHolder, 0);
        sead::Vector3f *playerTrans = al::getTrans(player);
        sead::Vector3f *playerVel = al::getVelocity(player);
        sead::Quatf *playerQuat = al::getQuat(player);
        sead::Vector3f *playerRecoveryPoint = player->mPlayerRecoverPoint->getSafetyPoint();

        gTextWriter->beginDraw();
        gTextWriter->setCursorFromTopLeft(sead::Vector2f(10.f, (dispHeight / 2) + 30.f));
        gTextWriter->setScaleFromFontHeight(20.f);
        #if(SMOVER==100)
        fl::PracticeUI::instance().menu(*gTextWriter);
        #endif

        isInGame = false;
    }

    gTextWriter->endDraw();

    al::executeDraw(curSequence->mLytKit, "２Ｄバック（メイン画面）");

}