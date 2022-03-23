#pragma once

#include <fl/ui/ui.h>

namespace fl {
namespace ui {

    class PracticeUI;

    class Page {
    public:
        Page(const char* name)
            : mPageName(name)
        {
        }
        virtual ~Page() = default;

        virtual void update(PracticeUI& ui) = 0;
        inline const char* getName() const { return mPageName; };

    private:
        const char* mPageName;
    };

} // namespace ui
} // namespace fl