#include "fl/common.h"
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

    if (h.isRunning) {
        ui.printf(" TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
        ui.printf(" %lu Frames Remaining\n", h.frameCount - h.curFrame);
    }
    sead::Vector2f& left = *al::getLeftStick(CONTROLLER_AUTO);
    sead::Vector2f& right = *al::getRightStick(CONTROLLER_AUTO);
    ui.printf("Left Stick: (X: %.5f Y: %.5f)\n", left.x, left.y);
    ui.printf("Right Stick: (X: %.5f Y: %.5f)\n", right.x, right.y);
	ui.printf("Left Stick Cartesian: (X: %.0f Y: %.0f)\n", left.x * 32767, left.y * 32767);
	ui.printf("Right Stick Cartesian: (X: %.0f Y: %.0f)\n", right.x * 32767, right.y * 32767);
    ui.printf("Buttons:\n");
    // -1 = CONTROLLER_AUTO
    ui.printf("%s %s %s %s %s %s %s %s\n", al::isPadHoldA(-1) ? "A" : " ", al::isPadHoldB(-1) ? "B" : " ", al::isPadHoldX(-1) ? "X" : " ", al::isPadHoldY(-1) ? "Y" : " ", al::isPadHoldL(-1) ? "L" : " ", al::isPadHoldR(-1) ? "R" : " ", al::isPadHoldZL(-1) ? "ZL" : "  ", al::isPadHoldZR(-1) ? "ZR" : "  ");
    ui.printf("%s %s %s %s %s %s %s %s\n", al::isPadHoldPlus(-1) ? "+" : " ", al::isPadHoldMinus(-1) ? "-" : " ", al::isPadHoldPressLeftStick(-1) ? "LS" : "  ", al::isPadHoldPressRightStick(-1) ? "RS" : "  ", al::isPadHoldUp(-1) ? "DUP" : "   ", al::isPadHoldRight(-1) ? "DRIGHT" : "      ", al::isPadHoldDown(-1) ? "DDOWN" : "     ", al::isPadHoldLeft(-1) ? "DLEFT" : "     ");
#endif
}
