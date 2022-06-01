#include "fl/common.h"
#include "fl/ui/pages.h"
#include "game/GameData/GameDataFunction.h"

void fl::ui::debug::update(PracticeUI& ui)
{
	StageScene* stageScene = ui.getStageScene();
#if (SMOVER == 100)
	ui.printf(" Current Scenario: %d\n", GameDataFunction::getWorldScenarioNo(*stageScene->mHolder, GameDataFunction::getCurrentWorldId(*stageScene->mHolder)));
	ui.printf(" Current World ID: %d\n", GameDataFunction::getCurrentWorldId(*stageScene->mHolder));
	ui.printf(" Current Stage Name: %s\n", GameDataFunction::getCurrentStageName(*stageScene->mHolder));
#endif
#if (SMOVER == 130)
	ui.printf(" Current Scenario: %d\n", GameDataFunction::getWorldScenarioNo(stageScene->mHolder, GameDataFunction::getCurrentWorldId(stageScene->mHolder)));
	ui.printf(" Current World ID: %d\n", GameDataFunction::getCurrentWorldId(stageScene->mHolder));
	ui.printf(" Current Stage Name: %s\n", GameDataFunction::getCurrentStageName(stageScene->mHolder));
#endif
	ui.printf(" Language: %s\n", stageScene->mHolder->getLanguage());
	ui.printf("\n");
	ui.printf(" Practice Mod Version: %s\n", PRACTICE_VERSTR);
}