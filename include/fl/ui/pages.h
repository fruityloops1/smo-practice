#pragma once

namespace fl {
namespace ui {

    class PracticeUI;

#define _PAGE(N)                          \
    namespace N {                         \
        void update(fl::ui::PracticeUI&); \
    }

    _PAGE(about);
    _PAGE(debug);
    _PAGE(info);
    _PAGE(misc);
    _PAGE(modes);
    _PAGE(mooninfo);
    _PAGE(options);
    _PAGE(stages);
    _PAGE(tas);

#undef _PAGE

} // namespace ui
} // namespace fl

#include "fl/ui/ui.h"