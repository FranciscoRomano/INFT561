#include "maths.h"
using namespace maths;

// ** Object Definitions *************************
    
    mat2::mat2() { for (int i = 0; i < 2; i++) this->elements[i] = vec2(0, 0); }
    mat2::mat2(float n) { for (int y = 0; y < 2; y++) for (int x = 0; x < 2; x++) this->elements[y][x] = y == x ? n : 0; }
    mat2::mat2(const mat2 & n) { for (int i = 0; i < 2; i++) this->elements[i] = n.elements[i]; }
    void mat2::operator=(const mat2 & n) { for (int i = 0; i < 2; i++) this->elements[i] = n.elements[i]; }
    vec2 & mat2::operator[](const int index) { return this->elements[index]; }
    const vec2 & mat2::operator[](const int index) const { return this->elements[index]; }

// ** Method Definitions *************************

    vec2 maths::operator*(const mat2 & aa, const vec2 & bb)
    {
        vec2 result;
        result.x = aa.elements[0][0] * bb.x + aa.elements[1][0] * bb.y;
        result.y = aa.elements[0][1] * bb.x + aa.elements[1][1] * bb.y;
        return result;
    }
    mat2 maths::operator*(const mat2 & aa, const mat2 & bb)
    {
        mat2 result(0);
        for (int y = 0; y < 2; y++)
            for (int x = 0; x < 2; x++)
                for (int i = 0; i < 2; i++) result[y][x] += aa.elements[i][x] * bb.elements[y][i];
        return result;
    }
    bool maths::operator==(const mat2 & aa, const mat2 & bb)
    {
        for (int i = 0; i < 2; i++)
            if (aa.elements[i] != bb.elements[i]) return false;
        return true;
    }
    bool maths::operator!=(const mat2 & aa, const mat2 & bb)
    {
        for (int i = 0; i < 2; i++)
            if (aa.elements[i] != bb.elements[i]) return true;
        return false;
    }

// ***********************************************