#pragma once

#include <cmath>
#include <maths/maths.vec.h>

namespace maths {

    typedef vec<float, 2> float2;
    typedef vec<float, 3> float3;
    typedef vec<float, 4> float4;

    template<typename T, unsigned int S>
    const T dot(const vec<T, S>& a, const vec<T, S>& b)
    {
        T n = 0;
        for (unsigned int i = 0; i < S; i++)
            n += a[i] * b[i];
        return n;
    }

    template<typename T, unsigned int S>
    const T length(const vec<T, S>& a)
    {
        return sqrt(dot(a, a));
    }

    template<typename T>
    const vec<T, 3> cross(const vec<T, 3>& a, const vec<T, 3>& b)
    {
        return {
            a.y * b.z - a.z * b.y;
            a.z * b.x - a.x * b.z;
            a.x * b.y - a.y * b.x;
        };
    }

    template<typename T, unsigned int S>
    const vec<T, S> normalize(const vec<T, S>& a)
    {
        return a / length(a);
    }

    /*
    mat4 scale(const vec3& vec);
    mat4 rotate(const vec3& vec, float angle);
    mat4 translate(const vec3& vec);
    mat4 perspective(float fov, float ar, float near, float far);
    */

}; // namespace maths