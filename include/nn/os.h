#pragma once

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nnosMutexType {
    u8 curState;            // _0
    bool isRecursiveMutex;  // _1
    s32 lockLevel;          // _2
    u8 _6[0x20 - 0xE];
} nnosMutexType;

namespace nn { namespace os { 
    struct TlsSlot {
        u32 slot;
    };
    Result AllocateTlsSlot(TlsSlot* slot_out, void (*)(u64));
    void FreeTlsSlot(TlsSlot slot);
    u64 GetTlsValue(TlsSlot slot);
    void SetTlsValue(TlsSlot slot, u64 value);
    u32 GetCurrentCoreNumber();
}}

void nnosInitializeMutex(nnosMutexType*, bool, s32);
void nnosFinalizeMutex(nnosMutexType*);
void nnosLockMutex(nnosMutexType*);
bool nnosTryLockMutex(nnosMutexType*);
void nnosUnlockMutex(nnosMutexType*);

//long long int llabs(long long int n);

#ifdef __cplusplus
}
#endif