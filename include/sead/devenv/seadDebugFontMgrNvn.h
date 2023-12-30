#pragma once

// #include "sead/heap/seadHeap.h"
#include "seadFontBase.h"
#include "types.h"

namespace sead {

    struct Heap;
    struct DrawContext;

    class DebugFontMgrNvn : public FontBase {
        public:
            DebugFontMgrNvn(void);
            virtual ~DebugFontMgrNvn();

            static DebugFontMgrNvn *sInstance;

            void initialize(sead::Heap *, const char *, const char*, unsigned int);
            void initializeFromBinary(sead::Heap *, void *, unsigned long, void *, unsigned long, unsigned int);
            static sead::DebugFontMgrNvn *createInstance(sead::Heap *);
            void swapUniformBlockBuffer(void);

            virtual float getHeight(void) const {
                return 16.f;
            };
            virtual float getWidth(void) const {
                return 8.f;
            };
            virtual float getCharWidth(char16_t) const {
                return 8.f;
            };
            virtual int getEncoding(void) const {
                return 2;
            };
            virtual int getMaxDrawNum(void) const {
                return 0x80;
            };
            virtual void begin(sead::DrawContext *) const;
            virtual void end(sead::DrawContext *) const;
            //print
            
    };

    class DebugFontMgrJis1Nvn : public FontBase {
        public:
            DebugFontMgrJis1Nvn(void);

            static DebugFontMgrJis1Nvn *sInstance;

            void initialize(sead::Heap *, const char *, const char *, const char *, unsigned int);
            void initializeFromBinary(sead::Heap* heap, void* shader, ulong shaderLength, void* font, ulong fontLength, void const* table, unsigned int);
            static sead::DebugFontMgrJis1Nvn *createInstance(sead::Heap *);
            void swapUniformBlockBuffer(void);
            
            virtual float getHeight(void) const {
                return 16.f;
            };
            virtual float getWidth(void) const {
                return 8.f;
            };
            virtual float getCharWidth(char16_t) const {
                return 8.f;
            };
            virtual int getEncoding(void) const {
                return 2;
            };
            virtual int getMaxDrawNum(void) const {
                return 0x80;
            };
            virtual void begin(sead::DrawContext *) const;
            virtual void end(sead::DrawContext *) const;
            //print
            
    };
}
