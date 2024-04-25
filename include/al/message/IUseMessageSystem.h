#pragma once

namespace al {
class MessageSystem;

class IUseMessageSystem {
public:
    virtual al::MessageSystem* getMessageSystem() const = 0;
};
}
