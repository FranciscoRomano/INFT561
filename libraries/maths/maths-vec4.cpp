#include "maths.h"
using namespace maths;

// ** Object Definitions *************************
    
    vec4::vec4() : vec4(0, 0, 0, 0) {}
    vec4::vec4(float n) : vec4(n, n, n, n) {}
    vec4::vec4(const vec4 & n) : vec4(n.x, n.y, n.z, n.w) {}
    vec4::vec4(float n, const vec3 & v) : vec4(n, v.x, v.y, v.z) {}
    vec4::vec4(const vec3 & v, float n) : vec4(v.x, v.y, v.z, n) {}
    vec4::vec4(float x, float y, float z, float w) { this->x = x, this->y = y, this->z = z, this->w = w; }
    void vec4::operator=(const vec4 & n) { this->x = n.x, this->y = n.y, this->z = n.z, this->w = n.w; }
    float & vec4::operator[](const int index) { return (&this->x)[index]; }
    const float & vec4::operator[](const int index) const { return (&this->x)[index]; }
    
// ** Method Definitions *************************
    
    vec4 maths::operator+(const float  bb, const vec4 & aa) { return vec4(aa.x + bb, aa.y + bb, aa.z + bb, aa.w + bb); }
    vec4 maths::operator+(const vec4 & aa, const float  bb) { return vec4(aa.x + bb, aa.y + bb, aa.z + bb, aa.w + bb); }
    vec4 maths::operator+(const vec4 & aa, const vec4 & bb) { return vec4(aa.x + bb.x, aa.y + bb.y, aa.z + bb.z, aa.w + bb.w); }
    vec4 maths::operator-(const float  bb, const vec4 & aa) { return vec4(aa.x - bb, aa.y - bb, aa.z - bb, aa.w - bb); }
    vec4 maths::operator-(const vec4 & aa, const float  bb) { return vec4(aa.x - bb, aa.y - bb, aa.z - bb, aa.w - bb); }
    vec4 maths::operator-(const vec4 & aa, const vec4 & bb) { return vec4(aa.x - bb.x, aa.y - bb.y, aa.z - bb.z, aa.w - bb.w); }
    vec4 maths::operator*(const float  bb, const vec4 & aa) { return vec4(aa.x * bb, aa.y * bb, aa.z * bb, aa.w * bb); }
    vec4 maths::operator*(const vec4 & aa, const float  bb) { return vec4(aa.x * bb, aa.y * bb, aa.z * bb, aa.w * bb); }
    vec4 maths::operator*(const vec4 & aa, const vec4 & bb) { return vec4(aa.x * bb.x, aa.y * bb.y, aa.z * bb.z, aa.w * bb.w); }
    vec4 maths::operator/(const float  bb, const vec4 & aa) { return vec4(aa.x / bb, aa.y / bb, aa.z / bb, aa.w / bb); }
    vec4 maths::operator/(const vec4 & aa, const float  bb) { return vec4(aa.x / bb, aa.y / bb, aa.z / bb, aa.w / bb); }
    vec4 maths::operator/(const vec4 & aa, const vec4 & bb) { return vec4(aa.x / bb.x, aa.y / bb.y, aa.z / bb.z, aa.w / bb.w); }
    bool maths::operator==(const vec4 & aa, const vec4 & bb) { return aa.x == bb.x && aa.y == bb.y && aa.z == bb.z && aa.w == bb.w; }
    bool maths::operator!=(const vec4 & aa, const vec4 & bb) { return aa.x != bb.x || aa.y != bb.y || aa.z != bb.z || aa.w == bb.w; }

// ***********************************************