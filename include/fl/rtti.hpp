#pragma once

#include <cstdint>
#include "al/nerve/NerveKeeper.h"

struct RttiStl {
    uintptr_t example;
    const char* name;
};

#define RTTI_WRAP(out, in)                                                      \
union {                                                                         \
    decltype(in) underlying;                                                    \
    uintptr_t vtbl;                                                             \
                                                                                \
    inline auto GetRtti() { return *reinterpret_cast<RttiStl **>(vtbl - 8); } \
    inline bool HasRtti() { return GetRtti() != NULL; }                         \
}* out = reinterpret_cast<decltype(out)>(in);
