#pragma once

#include <nn/os.h>

#include "sead/basis/seadTypes.h"

namespace sead
{
class ThreadLocalStorage
{
public:
    ThreadLocalStorage();
    ~ThreadLocalStorage();

    ThreadLocalStorage(const ThreadLocalStorage&) = delete;
    ThreadLocalStorage& operator=(const ThreadLocalStorage&) = delete;

    void setValue(uintptr_t value);
    uintptr_t getValue() const;

private:
    nn::os::TlsSlot mTlsSlot;
};
}  // namespace sead

#define SEAD_THREAD_THREAD_LOCAL_STORAGE_H_
#ifdef NNSDK
#include "thread/nin/seadThreadLocalStorageNin.hpp"
#else
#endif
#undef SEAD_THREAD_THREAD_LOCAL_STORAGE_H_
