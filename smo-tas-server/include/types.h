#pragma once

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long s64;

typedef float f32;
typedef double f64;

namespace smo
{

    template<class T>
    struct Vector2
    {
        T x, y;
    };

    template<class T>
    struct Vector3
    {
        T x, y, z;
    };

    template<class T>
    struct Quat
    {
        T x, y, z, w;
    };

    typedef Vector2<float> Vector2f;
    typedef Vector2<int> Vector2i;
    
    typedef Vector3<float> Vector3f;
    typedef Vector3<int> Vector3i;

    typedef Quat<float> Quatf;
}