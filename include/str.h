/**
 * @file str.h
 * @brief Operations for strings.
 */

#pragma once

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

int strcmp(char const *str1, char const *str2);
u64 strlen(char const *str);

char* strcpy(char* dest, char const* src);

#ifdef __cplusplus
}
#endif