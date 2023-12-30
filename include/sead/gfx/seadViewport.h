/**
 * @file viewport.h
 * @brief Basic Viewport class.
 */

#pragma once

#include <types.h>
#include <sead/math/seadVector.h>

namespace sead
{
    class Viewport
    {
    public:
        Viewport();
        Viewport(f32, f32, f32, f32);

        void project(sead::Vector2<f32> *, sead::Vector3<f32> const &) const;
        void apply(sead::DrawContext*, sead::LogicalFrameBuffer const&) const;
       // void project(sead::Vector2<f32> *, sead::Vector3<f32> const &) const;

        f32 _8;
        f32 Viewport_xC;
        f32 _10;
        f32 _14;
    };
};
