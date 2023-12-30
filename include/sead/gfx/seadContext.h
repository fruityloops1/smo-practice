/**
 * @file context.h
 * @brief Basic draw context implementation.
 */

#pragma once

#include <sead/thread/seadCriticalSection.h>
#include <sead/heap/seadHeap.h>
#include <sead/hostio/seadHostIONode.h>
#include <sead/gfx/seadColor.h>
#include "types.h"

namespace sead
{
    class DrawContext
    {
    public:
        DrawContext();
        virtual ~DrawContext();

        u32 _8;
        u32 DrawContext_xC;
        u64 _10;
        u8 _18[0xC0-0x18];
        u64 _C0;
        u64 _C8;
        u64 _D0;
        u64 _D8;
        u64 _E0;
        u64 _E8;
    };

    class DrawLockContext : public sead::hostio::Node
    {
    public:
        DrawLockContext();

        void initialize(sead::Heap *);
        void lock();
        void unlock();
        void genMessage(sead::hostio::Context *);

        u32 _8;
        u32 DrawLockContext_xC;
        sead::CriticalSection mContextSection; // _10
    };

    class GraphicsContextMRT {
public:
    virtual ~GraphicsContextMRT();

    bool mDepthTestEnable;
    bool mDepthWriteEnable;
    int mDepthFunc;
    int mCullFace;
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int iVar7;
    int iVar8;
    int iVar9;
    int iVar10;
    int iVar11;
    int iVar12;
    int iVar13;
    int iVar14;
    int iVar15;
    int iVar16;
    int iVar17;
    int iVar18;
    int iVar19;
    int iVar20;
    int iVar21;
    int iVar22;
    int iVar23;
    int iVar24;
    int iVar25;
    int iVar26;
    int iVar27;
    int iVar28;
    int iVar29;
    int iVar30;
    int iVar31;
    int iVar32;
    int iVar33;
    int iVar34;
    int iVar35;
    int iVar36;
    int iVar37;
    int iVar38;
    int iVar39;
    int iVar40;
    int iVar41;
    int iVar42;
    int iVar43;
    int iVar44;
    int iVar45;
    int iVar46;
    int iVar47;
    int iVar48;
    int iVar49;
    sead::Color4f mBlendColor;
    bool bVar1;
    int iVar50;
    int iVar51;
    int iVar52;
    bool mStencilTestEnable;
    int mStencilFunc;
    int mStencilRef;
    int mStencilValueMask;
    int iVar53;
    int iVar54;
    int iVar55;
    int iVar56;
    int mPolygonMode;
    int iVar57;
    bool bVar2;
    bool bVar3;
    bool bVar4;
};
};
