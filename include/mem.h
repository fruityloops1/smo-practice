#pragma once

#include "nn/mem.h"
#include <stddef.h>
#include <nn/init.h>

void* aligned_alloc(size_t alignment, size_t size);

#define alloc(SIZE) nn::init::GetAllocator()->Allocate(SIZE)
#define dealloc(PTR) nn::init::GetAllocator()->Free(PTR)
#define realloc(PTR, SIZE) nn::init::GetAllocator()->Reallocate(PTR, SIZE);