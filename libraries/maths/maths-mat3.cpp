#include "maths.h"
using namespace maths;

// ** Object Definitions *************************
    
    mat3::mat3() { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = 0; }
    mat3::mat3(float n) { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = y == x ? n : 0; }
    mat3::mat3(const mat3 & n) { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = n.elements[y][x]; }
    void mat3::operator=(const mat3 & n) { for (int y = 0; y < 3; y++) for (int x = 0; x < 3; x++) this->elements[y][x] = n.elements[y][x]; }
    vec3 & mat3::operator[](const int index) { return this->elements[index]; }
    const vec3 & mat3::operator[](const int index) const { return this->elements[index]; }

// ** Method Definitions *************************

    vec3 maths::operator*(const mat3 & aa, const vec3 & bb)
    {
        vec3 result;
        result.x = aa.elements[0][0] * bb.x + aa.elements[1][0] * bb.y + aa.elements[2][0] * bb.z;
        result.y = aa.elements[0][1] * bb.x + aa.elements[1][1] * bb.y + aa.elements[2][1] * bb.z;
        result.z = aa.elements[0][2] * bb.x + aa.elements[1][2] * bb.y + aa.elements[2][2] * bb.z;
        return result;
    }
    mat3 maths::operator*(const mat3 & aa, const mat3 & bb)
    {
        mat3 result;
        for (int y = 0; y < 3; y++)
            for (int x = 0; x < 3; x++)
                for (int i = 0; i < 3; i++) result[y][x] += aa.elements[i][x] * bb.elements[y][i];
        return result;
    }
    bool maths::operator==(const mat3 & aa, const mat3 & bb)
    {
        for (int i = 0; i < 3; i++)
            if (aa.elements[i] != bb.elements[i]) return false;
        return true;
    }
    bool maths::operator!=(const mat3 & aa, const mat3 & bb)
    {
        for (int i = 0; i < 3; i++)
            if (aa.elements[i] != bb.elements[i]) return true;
        return false;
    }

// ***********************************************