#pragma once

#include "debugMenu.hpp"
#include <game/Player/PlayerActorHakoniwa.h>
#include <game/StageScene/StageScene.h>
#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>

namespace fl
{

class PracticeUI
{
private:
    sead::Vector3f savedTrans;
    sead::Quatf savedQuat;
    bool saved = false;
    bool teleportEnabled = false;
    s8 reloadStageForPos = -1;
    sead::Vector3f reloadStagePos;
    sead::Quatf reloadStageQuat;
    StageScene* stageScene;

    bool inputEnabled = true;
    bool hideShineCounter = false;
    bool nextFrameNoLeftInput = false;
    bool nextFrameNoRightInput = false;

    #if(SMOVER==130)
    char textBuffer[4096];
    u32 printPos;
    #endif

    void savePosition(PlayerActorHakoniwa& player);
    void loadPosition(PlayerActorHakoniwa& player);
public:
    static inline PracticeUI& instance() {static PracticeUI ui; return ui;}
    void update(StageScene& stageScene);
    #if(SMOVER==100)
    void menu(sead::TextWriter& p);
    #endif
    #if(SMOVER==130)
    void menu();
    #endif

    inline StageScene* getStageScene() {return stageScene;}

    bool shineRefresh = false;
    bool gotShineRefresh = false;
    bool alwaysWarp = false;
    bool disableAutoSave = false;
    bool skipBowser = false;

    bool isModeDiverOrJungleGymRom = false;
    bool isModeDiverRom = false;
    bool isModeE3LiveRom = false;
    bool isModeE3MovieRom = false;
    bool isModeEpdMovieRom = false;
    bool isModeJungleGymRom = false;
    
    enum Page : u8
    {
        About, Options, Stage, Misc, Info, Info2, Tas, MoonInfo, Modes, Debug
    };

    enum MofumofuPattern : s8
    {
        Random = -1, Ghost = 0, Nose = 1, C = 2, W = 3, J = 4, Medal = 5, Plane = 6, Five = 7, Hangman = 8, Spanish = 9, Siblings = 10,
        Snake = 11, Eight = 12, Mushroom = 13, Z = 14, Tetris = 15, Ear = 16, Bomb = 17, Bird = 18, L = 19, O = 20, Star = 21
    };
    MofumofuPattern curPattern = Random;

    struct MofumofuPatternEntry
    {
        const char* typeStr;
        MofumofuPattern type;
        int target;
        bool reverse;
    };

    constexpr static const MofumofuPatternEntry mPatternEntries[22] = {
        {"Ghost", Ghost, 0, false}, {"Nose", Nose, 0, true}, {"C", C, 1, false}, {"W", W, 1, true}, {"J", J, 2, false}, {"Medal", Medal, 2, true}, {"Plane", Plane, 3, false}, {"5", Five, 3, true}, {"Hangman", Hangman, 4, false}, {"Spanish", Spanish, 4, true},
        {"Siblings", Siblings, 5, false}, {"Snake", Snake, 5, true}, {"8", Eight, 6, false}, {"Mushroom", Mushroom, 6, true}, {"Z", Z, 7, false}, {"Tetris", Tetris, 7, true}, {"Ear", Ear, 8, false}, {"Bomb", Bomb, 8, true}, {"Bird", Bird, 9, false}, {"L", L, 9, true}, {"O", O, 10, false}, {"Star", Star, 10, true}
    };

    Page curPage = About;
    u8 curLine = 0;
};

}