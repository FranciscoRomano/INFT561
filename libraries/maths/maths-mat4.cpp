#include "maths.h"
using namespace maths;

// ** Object Definitions *************************
    
    mat4::mat4() { for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++) this->elements[y][x] = 0; }
    mat4::mat4(float n) { for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++) this->elements[y][x] = y == x ? n : 0; }
    mat4::mat4(const mat4 & n) { for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++) this->elements[y][x] = n.elements[y][x]; }
    void mat4::operator=(const mat4 & n) { for (int y = 0; y < 4; y++) for (int x = 0; x < 4; x++) this->elements[y][x] = n.elements[y][x]; }
    vec4 & mat4::operator[](const int index) { return this->elements[index]; }
    const vec4 & mat4::operator[](const int index) const { return this->elements[index]; }

// ** Method Definitions *************************

    vec4 maths::operator*(const mat4 & aa, const vec4 & bb)
    {
        vec4 result;
        result.x = aa.elements[0][0] * bb.x + aa.elements[1][0] * bb.y + aa.elements[2][0] * bb.z + aa.elements[3][0] * bb.w;
        result.y = aa.elements[0][1] * bb.x + aa.elements[1][1] * bb.y + aa.elements[2][1] * bb.z + aa.elements[3][1] * bb.w;
        result.z = aa.elements[0][2] * bb.x + aa.elements[1][2] * bb.y + aa.elements[2][2] * bb.z + aa.elements[3][2] * bb.w;
        result.w = aa.elements[0][3] * bb.x + aa.elements[1][3] * bb.y + aa.elements[2][3] * bb.z + aa.elements[3][3] * bb.w;
        return result;
    }
    mat4 maths::operator*(const mat4 & aa, const mat4 & bb)
    {
        mat4 result;
        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                for (int i = 0; i < 4; i++)
                    result[y][x] += aa.elements[i][x] * bb.elements[y][i];
        return result;
    }
    bool maths::operator==(const mat4 & aa, const mat4 & bb)
    {
        for (int i = 0; i < 4; i++)
            if (aa.elements[i] != bb.elements[i]) return false;
        return true;
    }
    bool maths::operator!=(const mat4 & aa, const mat4 & bb)
    {
        for (int i = 0; i < 4; i++)
            if (aa.elements[i] != bb.elements[i]) return true;
        return false;
    }

// ***********************************************