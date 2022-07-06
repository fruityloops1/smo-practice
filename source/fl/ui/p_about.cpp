#include "fl/ui/pages.h"

void fl::ui::about::update(PracticeUI& ui) {
	ui.printf("Welcome to the Practice Mod!\n\n");
#if SMOVER == 100
	ui.printf("Press left stick to hide/unhide the menu.\n");
#endif
#if SMOVER == 130
	ui.printf("Press L + left D-pad to hide/unhide the menu.\n");
#endif
	ui.printf("Press L + right D-pad to disable/enable the menu.\n\n");
    ui.printf("Originally created by Fruityloops#8500\n");
    ui.printf("TAS-Tools implemented by Mars2030#8008\n");
    ui.printf("1.3-improvements by Ontwikseltsaar\n");
    ui.printf("Further updates by MonsterDruide1#7702\n");
    ui.printf("Big thanks to CraftyBoss and bryce_____!\n");
    ui.printf("Special thanks to the TAS community!\n");
}
