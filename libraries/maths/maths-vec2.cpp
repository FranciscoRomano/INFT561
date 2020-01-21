#include "maths.h"
using namespace maths;

// ** Object Definitions *************************
    
    vec2::vec2() : vec2(0, 0) {}
    vec2::vec2(float n) : vec2(n, n) {}
    vec2::vec2(const vec2 & n) : vec2(n.x, n.y) {}
    vec2::vec2(float x, float y) { this->x = x, this->y = y; }
    void vec2::operator=(const vec2 & n) { this->x = n.x, this->y = n.y; }
    float & vec2::operator[](const int index) { return (&this->x)[index]; }
    const float & vec2::operator[](const int index) const { return (&this->x)[index]; }
    
// ** Method Definitions *************************

    vec2 maths::operator+(const float  bb, const vec2 & aa) { return vec2(aa.x + bb, aa.y + bb); }
    vec2 maths::operator+(const vec2 & aa, const float  bb) { return vec2(aa.x + bb, aa.y + bb); }
    vec2 maths::operator+(const vec2 & aa, const vec2 & bb) { return vec2(aa.x + bb.x, aa.y + bb.y); }
    vec2 maths::operator-(const float  bb, const vec2 & aa) { return vec2(aa.x - bb, aa.y - bb); }
    vec2 maths::operator-(const vec2 & aa, const float  bb) { return vec2(aa.x - bb, aa.y - bb); }
    vec2 maths::operator-(const vec2 & aa, const vec2 & bb) { return vec2(aa.x - bb.x, aa.y - bb.y); }
    vec2 maths::operator*(const float  bb, const vec2 & aa) { return vec2(aa.x * bb, aa.y * bb); }
    vec2 maths::operator*(const vec2 & aa, const float  bb) { return vec2(aa.x * bb, aa.y * bb); }
    vec2 maths::operator*(const vec2 & aa, const vec2 & bb) { return vec2(aa.x * bb.x, aa.y * bb.y); }
    vec2 maths::operator/(const float  bb, const vec2 & aa) { return vec2(aa.x / bb, aa.y / bb); }
    vec2 maths::operator/(const vec2 & aa, const float  bb) { return vec2(aa.x / bb, aa.y / bb); }
    vec2 maths::operator/(const vec2 & aa, const vec2 & bb) { return vec2(aa.x / bb.x, aa.y / bb.y); }
    bool maths::operator==(const vec2 & aa, const vec2 & bb) { return aa.x == bb.x && aa.y == bb.y; }
    bool maths::operator!=(const vec2 & aa, const vec2 & bb) { return aa.x != bb.x || aa.y != bb.y; }

// ***********************************************