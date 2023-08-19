#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/hio/HioNode.h"

namespace al {

class EventFlowDataHolder;

class IUseEventFlowData {
public:
    virtual EventFlowDataHolder* getEventFlowDataHolder() const = 0;
};

class EventFlowExecutor : public al::HioNode, public al::IUseEventFlowData {

};

}
