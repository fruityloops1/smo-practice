#pragma once

namespace al {
struct ExecuteOrder {
    const char* sVar1;
    const char* sVar2;
    int iVar1;
    const char* sVar3;
};

struct ExecuteTableOrder {
    const char* sVar1;
    al::ExecuteOrder* mExecuteOrder;
    int iVar1;
};
}
