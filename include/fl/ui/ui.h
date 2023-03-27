#pragma once

#include "debugMenu.hpp"
#include "fl/ui/page.h"
#include "fl/ui/pages.h"
#include "fl/ui/ui.h"
#include <game/Player/PlayerActorHakoniwa.h>
#include <game/StageScene/StageScene.h>
#include <sead/container/seadPtrArray.h>
#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>
#include <str.h>
#include <fl/input.h>

namespace fl {
namespace ui {

    class Page;

    class PracticeUI {
    public:
        static inline PracticeUI& instance()
        {
            static PracticeUI ui;
            return ui;
        }

        void update(StageScene* stageScene);
#if (SMOVER == 100)
        void menu(sead::TextWriter& p);
#endif
#if (SMOVER == 130)
        void menu();
#endif

        inline StageScene* getStageScene()
        {
            return mStageScene;
        }
        template <typename... Args>
        void printf(const char* format, Args... args)
        {
            printPos += sprintf(textBuffer + printPos, format, args...);
        }
        void toggle(const char* name, bool& value);
        inline void cursor(int line)
        {
            if (curLine == line)
                printf(">");
        }
        template <typename F>
        void trigger(const char* name, F func)
        {
            cursor(curMaxLine);
            printf("%s\n", name);
            if (inputEnabled && !nextFrameNoRightInput && curLine == curMaxLine && isTriggerRight())
                func();
            curMaxLine++;
        }
        inline void addLine() { curMaxLine++; }

        bool teleportEnabled = false;
        bool shineRefresh = false;
        bool gotShineRefresh = false;
        bool alwaysWarp = false;
        bool disableAutoSave = false;
        bool skipBowser = false;
        bool disablePuppet = false;
        bool overrideBowserHat0 = false;
        bool reloadDUP = false;

        bool isModeDiverOrJungleGymRom = false;
        bool isModeDiverRom = false;
        bool isModeE3LiveRom = false;
        bool isModeE3MovieRom = false;
        bool isModeEpdMovieRom = false;
        bool isModeJungleGymRom = false;

        bool shouldRender = true;

        enum class Page : u8 {
            About = 0,
            Options = 1,
            Stage = 2,
            Misc = 3,
            Info = 4,
            Info2 = 5,
            InfoMighty = 6,
            InfoMighty2 = 7,
            Tas = 8,
            MoonInfo = 9,
            Modes = 10,
            Statistics = 11,
            Debug = 12
        };

        enum MofumofuPattern : s8 {
            Random = -1,
            Ghost = 0,
            Nose = 1,
            C = 2,
            W = 3,
            J = 4,
            Medal = 5,
            Plane = 6,
            Five = 7,
            Hangman = 8,
            Spanish = 9,
            Siblings = 10,
            Snake = 11,
            Eight = 12,
            Mushroom = 13,
            Z = 14,
            Tetris = 15,
            Ear = 16,
            Bomb = 17,
            Bird = 18,
            L = 19,
            O = 20,
            Star = 21
        };
        MofumofuPattern curPattern = Random;

        struct MofumofuPatternEntry {
            const char* typeStr;
            int target;
            bool reverse;
        };

        constexpr static const MofumofuPatternEntry mPatternEntries[22] = {
            { "Ghost", 0, false }, { "Nose", 0, true }, { "C", 1, false }, { "W", 1, true }, { "J", 2, false }, { "Medal", 2, true }, { "Plane", 3, false }, { "5", 3, true }, { "Hangman", 4, false }, { "Spanish", 4, true },
            { "Siblings", 5, false }, { "Snake", 5, true }, { "8", 6, false }, { "Mushroom", 6, true }, { "Z", 7, false }, { "Tetris", 7, true }, { "Ear", 8, false }, { "Bomb", 8, true }, { "Bird", 9, false }, { "L", 9, true }, { "O", 10, false }, { "Star", 10, true }
        };

        Page curPage = Page::About;
        u8 curLine = 0;
        bool inputEnabled = true;
        bool hideShineCounter = false;
        bool nextFrameNoLeftInput = false;
        bool nextFrameNoRightInput = false;

    private:
        StageScene* mStageScene { nullptr };
        u8 curMaxLine = 0;
        sead::Vector3f savedTrans;
        sead::Quatf savedQuat;
        bool saved = false;
        s8 reloadStageForPos = -1;
        sead::Vector3f reloadStagePos;
        sead::Quatf reloadStageQuat;

        char textBuffer[4096];
        u32 printPos;

        const struct {
            void (*const update)(PracticeUI&) { nullptr };
            const char* const name { nullptr };
        } mPages[13] {
            { fl::ui::about::update, "About" },
            { fl::ui::options::update, "Options" },
            { fl::ui::stages::update, "Stages" },
            { fl::ui::misc::update, "Miscellaneous" },
            { fl::ui::info::update, "Info" },
            { fl::ui::info2::update, "Info 2" },
            { fl::ui::infomighty::update, "Mighty Info" },
            { fl::ui::infomighty2::update, "Mighty Info 2" },
            { fl::ui::tas::update, "TAS" },
            { fl::ui::mooninfo::update, "Moon Info" },
            { fl::ui::modes::update, "Modes" },
            { fl::ui::statistics::update, "Statistics" },
            { fl::ui::debug::update, "Debug" }
        };

        void savePosition(PlayerActorHakoniwa& player);
        void loadPosition(PlayerActorHakoniwa& player);
    };

} // namespace ui
} // namespace fl
