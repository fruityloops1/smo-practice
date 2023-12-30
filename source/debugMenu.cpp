#include "debugMenu.hpp"
#include "drawer.h"
#include "fl/server.h"
#include "fl/ui/ui.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include "game/Player/PlayerCollider.h"
#include "game/System/Application.h"
#include <sead/gfx/seadPrimitiveRenderer.h>
#include <al/util.hpp>
#include <sead/FrameBuffer.h>

// These files must exist in your romfs! they are not there by default, and must be added in order for the debug font to work correctly.
static const char* DBG_FONT_PATH = "DebugData/Font/nvn_font_jis1.ntx";
static const char* DBG_SHADER_PATH = "DebugData/Font/nvn_font_shader_jis1.bin";
static const char* DBG_TBL_PATH = "DebugData/Font/nvn_font_jis1_tbl.bin";

sead::TextWriter* gTextWriter;

bool showMenu = true;
bool isInGame = false;
bool inputEnabled = true;

void setupDebugMenu(GameSystem* gSys)
{

    // gLogger->LOG("Preparing Debug Menu.\n");

    sead::Heap* curHeap = al::getCurrentHeap();

    agl::DrawContext* context = gSys->mSystemInfo->mDrawInfo->mDrawContext;

    if (curHeap) {
        if (context) {
            // gLogger->LOG("Creating Debug Font Instance.\n");

            sead::DebugFontMgrJis1Nvn::sInstance = sead::DebugFontMgrJis1Nvn::createInstance(curHeap);

            // gLogger->LOG("Checking if Paths Exist: {%s} {%s} {%s}\n", DBG_FONT_PATH, DBG_SHADER_PATH, DBG_TBL_PATH);

            if (al::isExistFile(DBG_FONT_PATH) && al::isExistFile(DBG_SHADER_PATH) && al::isExistFile(DBG_TBL_PATH)) {

                // gLogger->LOG("Found All Files in Debug Directory!\n");

                sead::DebugFontMgrJis1Nvn::sInstance->initialize(curHeap, DBG_SHADER_PATH, DBG_FONT_PATH, DBG_TBL_PATH, 0x100000);

                // gLogger->LOG("Initialized Instance!\n");

                sead::TextWriter::setDefaultFont(sead::DebugFontMgrJis1Nvn::sInstance);

                // gLogger->LOG("Set Default Text Writer Font!\n");

                gTextWriter = new sead::TextWriter(context);

                // gLogger->LOG("Created Text Writer!\n");

                gTextWriter->setupGraphics(context);

                // gLogger->LOG("Setup Graphics!\n");
            }
        } else {
            // gLogger->LOG("Failed to get Context!\n");
        }
    } else {
        // gLogger->LOG("Failed to get Heap!\n");
    }

    smo::Server::instance().start();

    __asm("MOV W23, #0x3F800000");
    __asm("MOV W8, #0xFFFFFFFF");
}

void drawBackground(agl::DrawContext* context)
{

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

void drawMainHook(sead::Viewport* viewport, sead::DrawContext* drawContext, sead::LogicalFrameBuffer* frameBuffer, al::LayoutKit* layoutKit)
{
    al::executeDraw(layoutKit, "２Ｄバック（メイン画面）");
    al::executeDraw(layoutKit, "２Ｄベース（メイン画面）");
    al::executeDraw(layoutKit, "２Ｄオーバー（メイン画面）");

    if (showMenu) {
        int dispWidth = al::getLayoutDisplayWidth();
        int dispHeight = al::getLayoutDisplayHeight();

        gTextWriter->setDrawContext(drawContext);
        gTextWriter->setupGraphics(drawContext);
        gTextWriter->mViewport = viewport;

        gTextWriter->mColor = sead::Color4f(
            1.f,
            1.f,
            1.f,
            0.8f);

        drawBackground((agl::DrawContext*)drawContext);

        gTextWriter->beginDraw();
        gTextWriter->setCursorFromTopLeft(sead::Vector2f(10.f, 10.f));
        gTextWriter->printf("FPS: %d\n", static_cast<int>(round(Application::sInstance->mFramework->calcFps())));
        gTextWriter->setCursorFromTopLeft(sead::Vector2f(10.f, (dispHeight / 2) + 30.f));
        gTextWriter->setScaleFromFontHeight(20.f);
#if (SMOVER == 100)
        if(isInGame)
            fl::ui::PracticeUI::instance().menu(*gTextWriter);
#endif

        gTextWriter->endDraw();
    }
    
    fl::ui::PracticeUI& ui = fl::ui::PracticeUI::instance();
    al::Scene *curScene = ui.getStageScene();
#if (SMOVER == 100)
    if (curScene && isInGame) {
        sead::LookAtCamera* cam = al::getLookAtCamera(curScene, 0);
        sead::Projection* projection = al::getProjectionSead(curScene, 0);

        sead::PrimitiveRenderer* renderer = sead::PrimitiveRenderer::instance();
        renderer->setDrawContext(drawContext);
        renderer->setCamera(*cam);
        renderer->setProjection(*projection);
        renderer->begin();

        sead::Vector3f pos = sead::Vector3f::zero;
        sead::Matrix34f mat = sead::Matrix34f::ident;
        mat.setBase(3, pos);
        renderer->setModelMatrix(mat);

        al::PlayerHolder* playerHolder = al::getScenePlayerHolder(curScene);
        bool isExistPlayer = playerHolder->getPlayerNum() != 0;
        al::LiveActor* playerActor = playerHolder->tryGetPlayer(0);

        PlayerActorHakoniwa* player;
        if (isExistPlayer)
            player = static_cast<PlayerActorHakoniwa*>(playerActor);

        PlayerCollider* collider = player->mColliderHakoniwa->mCollider;
        sead::Vector3f* playerTrans = al::getTrans(player);
        sead::Quatf* playerQuat = al::getQuat(player);
        sead::Vector3f playerFacing = sead::Vector3f::ez;
        al::rotateVectorQuat(&playerFacing, *playerQuat);


        HackCap* cappy = player->mHackCap;
        sead::Vector3f* cappyTrans;
        if (cappy)
            cappyTrans = al::getTrans(cappy);

        // renderer->drawSphere8x16(ui.renderer.actorTrans, 30.0f, {1.0f, 0.0f, 0.0f, 0.8f});

        if (ui.renderer.showPlayer)
            renderer->drawSphere8x16(*playerTrans, 20.0f, {0.0f, 1.0f, 0.0f, 0.5f});

        if (ui.renderer.showAxis)
            renderer->drawAxis({0.0f, 0.0f, 0.0f}, 200.0f);

        if (ui.renderer.showHitInfoFloor)
            drawHitInfo(renderer, collider->mHitFloor, {0.8, 1.0, 1.0, 0.8});

        if (ui.renderer.showHitInfoWall)
            drawHitInfo(renderer, collider->mHitWall, {1.0, 0.8, 1.0, 0.8});

        if (ui.renderer.showHitInfoCeil)
            drawHitInfo(renderer, collider->mHitCeil, {1.0, 1.0, 0.8, 0.8});

        // drawWireTriangle(renderer, ui.renderer.kclTri, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 1.0f, 1.0f}, true);

        if (ui.renderer.showHitInfoArray) {
            for (int i = 0; i < collider->arr4.capacity(); ++i) {
            // for (int i = 0; i < 64; ++i) {
                drawHitInfo(renderer, collider->arr4[i], {0.03f, 0.11f, 0.75f, 0.5f});
            }
        }

        if (ui.renderer.showHitSensors && ui.currentActor) {
            al::HitSensorKeeper* sensorKeeper = ui.currentActor->mHitSensorKeeper;
            if (sensorKeeper) {
                sead::PtrArray<al::HitSensor> sensors = sensorKeeper->mSensors;
                for (int i = 0; i < sensors.size(); ++i) {
                    al::HitSensor* sensor = sensors[i];
                    if (!al::isSensorValid(sensor)) continue;

                    sead::Vector3f pos = al::getSensorPos(sensor);
                    float radius = al::getSensorRadius(sensor);
                    renderer->drawSphere8x16(pos, radius, {1.0f, 0.8f, 1.0f, 0.7f});
                }
            }
        }

        if (ui.renderer.curArea && ui.renderer.showArea) {
            al::calcNearestAreaObjEdgePos(&ui.renderer.nearestEdgePoint, ui.renderer.curArea, *playerTrans);
            if (ui.renderer.showAreaPoint)
                renderer->drawSphere8x16(ui.renderer.nearestEdgePoint, 15.0f, {0.0f, 1.0f, 0.0f, 1.0f});
            drawAreaObj(renderer, ui.renderer.curArea, false, {1.0f, 0.8f, 1.0f, 0.9f}, {1.0f, 0.8f, 1.0f, 0.6f}, {1.0f, 0.8f, 1.0f, 0.6f});
        }

        if (ui.renderer.curAreaGroup && ui.renderer.showAreaGroup)
            drawAreaObjGroup(renderer, ui.renderer.curAreaGroup, false, {0.8f, 0.5f, 0.8f, 0.3f}, {0.8f, 0.5f, 0.8f, 0.3f}, {0.8f, 0.5f, 0.8f, 0.3f});

        if (ui.renderer.showCRC && cappy) {
            sead::Vector3f difference = *cappyTrans - *playerTrans;
            sead::Vector3f crc = *playerTrans + sead::dot(difference, playerFacing) * playerFacing;

            renderer->drawLine(*playerTrans, *playerTrans + playerFacing * 50.0f, {0.25f, 0.25f, 1.0f, 1.0f});

            renderer->drawSphere8x16(crc, 60.0f, {1.0f, 0.25f, 0.25, 0.4f});
        }


        if (ui.testDrawCube) {
            sead::PrimitiveRenderer::CubeArg shapeArea({20750, 250, 6750}, {500.0, 500.0, 500.0}, {1.0f, 0.0f, 0.0f, 1.0f});
            renderer->drawCube(shapeArea);
        }

        if (ui.testDrawSphere) {
            renderer->drawSphere8x16({20750, 250, 6750}, 250.0f, {0.0f, 1.0f, 0.0f, 1.0f});
        }

        if (ui.testDrawCylinder) {
            renderer->drawCylinder32({20750, 250, 6750}, 250.0f, 500.0f, {0.0f, 0.0f, 1.0f, 1.0f});
        }

        renderer->end();
    }
#endif
    
    isInGame = false;
}
