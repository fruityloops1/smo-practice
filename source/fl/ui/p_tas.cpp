#include "fl/common.h"
#include "fl/input.h"
#include "fl/server.h"
#include "fl/tas.h"
#include "fl/ui/pages.h"

void fl::ui::tas::update(PracticeUI& ui)
{
#if SMOVER == 130
    ui.printf(MSG_NO130);
    return;
#endif

#if SMOVER == 100
    ui.trigger("Connect to server", []() {
        // smo::Server::instance().connect("someip");
    });
    ui.toggle("Old Motion Mod", fl::TasHolder::instance().oldMotion);

    fl::TasHolder& h = fl::TasHolder::instance();

    if (h.isRunning) {
        ui.trigger("Stop Script", [&h]() {
            h.stop();
        });
    } else {
        ui.trigger("Start Script", [&h]() {
            if (h.frames)
                h.start();
        });
    }

    ui.printf("\n");

    if (h.scriptName)
        ui.printf(" Script: %s (%lu frames)\n", h.scriptName, h.frameCount);

    if (h.isRunning)
        ui.printf(" TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
    sead::Vector2f& left = *fgetLeftStick(CONTROLLER_AUTO);
    sead::Vector2f& right = *fgetRightStick(CONTROLLER_AUTO);
    ui.printf("Left Stick: (X: %.5f Y: %.5f)\n", left.x, left.y);
    ui.printf("Right Stick: (X: %.5f Y: %.5f)\n", right.x, right.y);
    ui.printf("Buttons:\n");
    // -1 = CONTROLLER_AUTO
    ui.printf("%s %s %s %s %s %s %s %s\n", fisPadHoldA(-1) ? "A" : " ", fisPadHoldB(-1) ? "B" : " ", fisPadHoldX(-1) ? "X" : " ", fisPadHoldY(-1) ? "Y" : " ", fisPadHoldL(-1) ? "L" : " ", fisPadHoldR(-1) ? "R" : " ", fisPadHoldZL(-1) ? "ZL" : "  ", fisPadHoldZR(-1) ? "ZR" : "  ");
    ui.printf("%s %s %s %s %s %s %s %s\n", fisPadHoldPlus(-1) ? "+" : " ", fisPadHoldMinus(-1) ? "-" : " ", fisPadHoldPressLeftStick(-1) ? "LS" : "  ", fisPadHoldPressRightStick(-1) ? "RS" : "  ", fisPadHoldUp(-1) ? "DUP" : "   ", fisPadHoldRight(-1) ? "DRIGHT" : "      ", fisPadHoldDown(-1) ? "DDOWN" : "     ", fisPadHoldLeft(-1) ? "DLEFT" : "     ");
#endif
}