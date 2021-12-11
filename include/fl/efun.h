#pragma once

#include <types.h>

void free(void* __ptr);

#define EFUN_ARGS(...) __VA_ARGS__
#define EFUN(ADDR, RETURN_TYPE, NAME, ARGS) \
static auto NAME = (RETURN_TYPE (*) (ARGS)) ((((u64) free) - 0x009011C0) + ADDR)