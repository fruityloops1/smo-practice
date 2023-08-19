#pragma once

namespace al {
class AreaObj;
class AreaObjGroup {
public:
    const char* mGroupName;
    al::AreaObj** mAreas;
    int mAreaCount;
    int mBufferSize;
};
}
