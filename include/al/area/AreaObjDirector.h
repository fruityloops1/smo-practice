#pragma once

#include "al/iuse/IUseAreaObj.h"

namespace al {
class AreaObjFactory;
class AreaObjGroup;
class AreaObjMtxConnecterHolder;

class AreaObjDirector {
public:
    AreaObjGroup* getAreaObjGroup(const char*) const;

    AreaObjFactory* mFactory;
    AreaObjMtxConnecterHolder* mMtxConnecterHolder;
    AreaObjGroup** mAreaGroups;
    int mAreaGroupCount;
};

}
