#pragma once

#include "nn/mem.h"
#include <nn/init.h>
#include <stddef.h>

void* aligned_alloc(size_t alignment, size_t size);
extern "C" void free(void*);

//#define alloc(SIZE) nn::init::GetAllocator()->Allocate(SIZE)
//#define dealloc(PTR) nn::init::GetAllocator()->Free(PTR)
//#define realloc(PTR, SIZE) nn::init::GetAllocator()->Reallocate(PTR, SIZE);

#define alloc(SIZE) aligned_alloc(0x10, SIZE)
#define dealloc(PTR) free(PTR)
