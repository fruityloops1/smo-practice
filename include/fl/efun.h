#pragma once

#include <types.h>

void free(void* __ptr);

#define EFUN_ARGS(...) __VA_ARGS__

#define EFUN(ADDR, RETURN_TYPE, NAME, ARGS) \
static auto NAME = (RETURN_TYPE (*) (ARGS)) ((((u64) free) - 0x009011C0) + ADDR)

#define WEFUN(ADDR, RETURN_TYPE, NAME, ARGS, ARG_NAMES) \
inline RETURN_TYPE NAME(ARGS) {\
    EFUN(ADDR, RETURN_TYPE, t_##NAME, EFUN_ARGS(ARGS));\
    return t_##NAME(ARG_NAMES);\
}


// class member function with arguments and return type
#define CEFUN(CLASS, ADDR, RETURN_TYPE, NAME, ARGS, ARG_NAMES) \
inline RETURN_TYPE NAME(ARGS) {\
    EFUN(ADDR, RETURN_TYPE, t_##NAME, EFUN_ARGS(CLASS*, ARGS));\
    return t_##NAME(this, ARG_NAMES);\
}

// class member function with no arguments and return type
#define CVEFUN(CLASS, ADDR, RETURN_TYPE, NAME) \
inline RETURN_TYPE NAME() {\
    EFUN(ADDR, RETURN_TYPE, t_##NAME, EFUN_ARGS(CLASS*));\
    return t_##NAME(this);\
}

// class member void function with arguments
#define VCEFUN(CLASS, ADDR, NAME, ARGS, ARG_NAMES) \
inline void NAME(ARGS) {\
    EFUN(ADDR, void, t_##NAME, EFUN_ARGS(CLASS*, ARGS));\
    t_##NAME(this, ARG_NAMES);\
}

#define VCEFUN_CTOR(CLASS, ADDR, ARGS, ARG_NAMES) \
inline CLASS(ARGS) {\
    EFUN(ADDR, void, t_##NAME, EFUN_ARGS(CLASS*, ARGS));\
    t_##NAME(this, ARG_NAMES);\
}

// class member void function with no arguments
#define VVCEFUN(CLASS, ADDR, NAME) \
inline void NAME(void) {\
    EFUN(ADDR, void, t_##NAME, EFUN_ARGS(CLASS*));\
    t_##NAME(this);\
}
