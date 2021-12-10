#ifndef SEAD_DECOMPRESSOR_H_
#define SEAD_DECOMPRESSOR_H_

#include <sead/basis/seadTypes.h>
#include <sead/container/seadTList.h>
#include <sead/heap/seadDisposer.h>
#include <sead/prim/seadSafeString.h>
#include <sead/resource/seadResource.h>
#include <sead/resource/seadResourceMgr.h>

namespace sead
{
class Decompressor : public TListNode<Decompressor*>, public IDisposer
{
public:
    Decompressor(const SafeString& name) : TListNode<Decompressor*>(this), IDisposer(), mExt(name) {}

    virtual ~Decompressor()
    {
        if (ResourceMgr::instance() != NULL)
            ResourceMgr::instance()->unregisterDecompressor(this);
    }

    virtual u8* tryDecompFromDevice(const ResourceMgr::LoadArg& loadArg, Resource* resource,
                                    u32* outSize, u32* outAllocSize, bool* outAllocated) = 0;

    const SafeString& getName() const { return mExt; }
    void setName(const SafeString& name) { mExt = name; }

protected:
    FixedSafeString<32> mExt;
};

}  // namespace sead

#endif  // SEAD_DECOMPRESSOR_H_
