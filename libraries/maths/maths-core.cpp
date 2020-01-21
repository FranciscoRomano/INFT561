#include <cmath>
#include "maths.h"
using namespace maths;

// ** Method Definitions *************************

    float maths::dot(const vec2 & v1, const vec2 & v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }
    float maths::dot(const vec3 & v1, const vec3 & v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }
    float maths::dot(const vec4 & v1, const vec4 & v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
    }
    float maths::length(const vec2 & v)
    {
        return std::sqrt(dot(v, v));
    }
    float maths::length(const vec3 & v)
    {
        return std::sqrt(dot(v, v));
    }
    float maths::length(const vec4 & v)
    {
        return std::sqrt(dot(v, v));
    }
    vec3 maths::cross(const vec3 & v1, const vec3 & v2)
    {
        vec3 result;
        result.x = v1.y * v2.z - v1.z * v2.y;
        result.y = v1.z * v2.x - v1.x * v2.z;
        result.z = v1.x * v2.y - v1.y * v2.x;
        return result;
    }
    mat4 maths::scale(const vec3 & v)
    {
        mat4 result;
        result[0] = vec4(v.x, 0.0, 0.0, 0.0);
        result[1] = vec4(0.0, v.y, 0.0, 0.0);
        result[2] = vec4(0.0, 0.0, v.z, 0.0);
        result[3] = vec4(0.0, 0.0, 0.0, 1.0);
        return result;
    }
    mat4 maths::rotate(const vec3 & v, float angle)
    {
        mat4 result(1);
        float const a = angle;
        float const c = cos(a);
        float const s = sin(a);
        vec3 axis(normalize(v));
        vec3 temp((1 - c) * axis);
        // right vector
        result[0][0] = c + temp[0] * axis[0];
        result[0][1] = temp[0] * axis[1] + s * axis[2];
        result[0][2] = temp[0] * axis[2] - s * axis[1];
        // up vector
        result[1][0] = temp[1] * axis[0] - s * axis[2];
        result[1][1] = c + temp[1] * axis[1];
        result[1][2] = temp[1] * axis[2] + s * axis[0];
        // foward vector
        result[2][0] = temp[2] * axis[0] + s * axis[1];
        result[2][1] = temp[2] * axis[1] - s * axis[0];
        result[2][2] = c + temp[2] * axis[2];
        return result;
    }
    mat4 maths::translate(const vec3 & v)
    {
        mat4 result(1);
        result[3] = vec4(v.x, v.y, v.z, 1.0);
        return result;
    }
    vec2 maths::normalize(const vec2 & v)
    {
        return v / length(v);
    }
    vec3 maths::normalize(const vec3 & v)
    {
        return v / length(v);
    }
    vec4 maths::normalize(const vec4 & v)
    {
        return v / length(v);
    }
    mat4 maths::perspective(float fov, float ar, float near, float far)
    {
        mat4 result;
        float thFOV = std::tan(fov / 2);
        float range = near - far;
        result[0][0] = 1 / (thFOV * ar);
        result[1][1] = 1 / thFOV;
        result[2][2] = (-near - far) / range;
        result[2][3] = 2 * far * near / range;
        result[3][2] = -1;
        return result;
    }

// ***********************************************