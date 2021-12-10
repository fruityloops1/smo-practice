#pragma once

namespace nn
{
    namespace diag
    {
        struct ModuleInfo
        {
            const char* modulePath; // _0
            uintptr_t moduleAddr; // _8
            size_t moduleSize; // _C
        };

        size_t GetRequiredBufferSizeForGetAllModuleInfo();
        int GetAllModuleInfo(nn::diag::ModuleInfo **, void *, unsigned long);
    };
};