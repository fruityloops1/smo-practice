#include "fl/common.h"
#include "fl/ui/pages.h"
#include "game/GameData/GameDataFunction.h"

void fl::ui::debug::update(PracticeUI& ui)
{
	StageScene* stageScene = ui.getStageScene();
	if(isInGame) {
#if (SMOVER == 100)
		ui.printf(" Current Scenario: %d\n", GameDataFunction::getWorldScenarioNo(*stageScene->mHolder, GameDataFunction::getCurrentWorldId(*stageScene->mHolder)));
		ui.printf(" Current World ID: %d\n", GameDataFunction::getCurrentWorldId(*stageScene->mHolder));
		ui.printf(" Current Stage Name: %s\n", GameDataFunction::getCurrentStageName(*stageScene->mHolder));
		ui.printf(" Current Entry Name: %s\n", stageScene->mHolder->mGameDataFile->mStartId.cstr());
#endif
#if (SMOVER == 130)
		ui.printf(" Current Scenario: %d\n", stageScene->mHolder->mGameDataFile->getScenarioNo(GameDataFunction::getCurrentWorldId(stageScene->mHolder)));
		ui.printf(" Current World ID: %d\n", GameDataFunction::getCurrentWorldId(stageScene->mHolder));
		ui.printf(" Current Stage Name: %s\n", GameDataFunction::getCurrentStageName(stageScene->mHolder));
		ui.printf(" Current Entry Name: %s\n", stageScene->mHolder->mGameDataFile->mStartId.cstr());
#endif
		ui.printf(" Language: %s\n", stageScene->mHolder->getLanguage());
	}
	else {
		ui.printf(" Current Scenario: --\n");
		ui.printf(" Current World ID: --\n");
		ui.printf(" Current Stage Name: --\n");
		ui.printf(" Current Entry Name: --\n");
	}
	ui.printf("\n");
	ui.printf(" Practice Mod Version: %s\n", PRACTICE_VERSTR);
	ui.printf(" Your Game Version: %s\n", GAME_VERSION);
}
