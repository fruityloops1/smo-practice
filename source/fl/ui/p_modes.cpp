#include "fl/common.h"
#include "fl/ui/pages.h"
#include "game/GameData/GameDataFunction.h"

void fl::ui::modes::update(PracticeUI& ui)
{
    ui.toggle("isModeDiverOrJungleGymRom", ui.isModeDiverOrJungleGymRom);
    ui.toggle("isModeDiverRom", ui.isModeDiverRom);
    ui.toggle("isModeJungleGymRom", ui.isModeJungleGymRom);
    ui.toggle("isModeE3LiveRom", ui.isModeE3LiveRom);
    ui.toggle("isModeE3MovieRom", ui.isModeE3MovieRom);
    ui.toggle("isModeEpdMovieRom", ui.isModeEpdMovieRom);
}