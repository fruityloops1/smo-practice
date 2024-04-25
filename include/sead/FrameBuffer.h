#pragma once

namespace sead {

struct DrawContext;

class LogicalFrameBuffer;

class FrameBuffer {
public:
    void bind(DrawContext* context) const;
};

}
