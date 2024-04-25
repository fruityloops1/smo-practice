#pragma once

#include "al/hio/HioNode.h"

namespace al {
class ExecutorListBase : public al::HioNode {
public:
    ExecutorListBase(const char*);
    virtual ~ExecutorListBase();
    virtual void executeList() const = 0;
    virtual bool isActive() const = 0;

    const char* mName;
};
}
