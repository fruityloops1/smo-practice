#include "fl/ui/pages.h"

void fl::ui::options::update(PracticeUI& ui)
{
    ui.toggle("Teleport", ui.teleportEnabled);
    ui.toggle("Moon Refresh", ui.shineRefresh);
    ui.toggle("Gray Moon Refresh", ui.gotShineRefresh);
    ui.toggle("Always Enable Warps", ui.alwaysWarp);
    ui.toggle("Disable Autosaving", ui.disableAutoSave);
    ui.toggle("Cloud Kingdom Bowser Skip", ui.skipBowser);
}