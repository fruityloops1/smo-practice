#include "al/nerve/Nerve.h"

namespace fl {

    const uintptr_t __module_start__ = ((uintptr_t)&malloc) - 0x724B94;
    
    inline const al::Nerve* getNerveAt(uintptr_t offset)
    {
        return (al::Nerve*) (__module_start__ + offset);
    }

    inline const void setNerveAt(al::IUseNerve* to, uintptr_t offset)
    {
        al::setNerve(to, getNerveAt(offset));
    }
}
