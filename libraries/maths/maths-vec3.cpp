#include "maths.h"
using namespace maths;

// ** Object Definitions *************************
    
    vec3::vec3() : vec3(0, 0, 0) {}
    vec3::vec3(float n) : vec3(n, n, n) {}
    vec3::vec3(const vec3 & n) : vec3(n.x, n.y, n.z) {}
    vec3::vec3(float n, const vec2 & v) : vec3(n, v.x,v.y) {}
    vec3::vec3(const vec2 & v, float n) : vec3(v.x,v.y, n) {}
    vec3::vec3(float x, float y, float z) { this->x = x, this->y = y, this->z = z; }
    void vec3::operator=(const vec3 & n) { this->x = n.x, this->y = n.y, this->z = n.z; }
    float & vec3::operator[](const int index) { return (&this->x)[index]; }
    const float & vec3::operator[](const int index) const { return (&this->x)[index]; }
    
// ** Method Definitions *************************

    vec3 maths::operator+(const float  bb, const vec3 & aa) { return vec3(aa.x + bb, aa.y + bb, aa.z + bb); }
    vec3 maths::operator+(const vec3 & aa, const float  bb) { return vec3(aa.x + bb, aa.y + bb, aa.z + bb); }
    vec3 maths::operator+(const vec3 & aa, const vec3 & bb) { return vec3(aa.x + bb.x, aa.y + bb.y, aa.z + bb.z); }
    vec3 maths::operator-(const float  bb, const vec3 & aa) { return vec3(aa.x - bb, aa.y - bb, aa.z - bb); }
    vec3 maths::operator-(const vec3 & aa, const float  bb) { return vec3(aa.x - bb, aa.y - bb, aa.z - bb); }
    vec3 maths::operator-(const vec3 & aa, const vec3 & bb) { return vec3(aa.x - bb.x, aa.y - bb.y, aa.z - bb.z); }
    vec3 maths::operator*(const float  bb, const vec3 & aa) { return vec3(aa.x * bb, aa.y * bb, aa.z * bb); }
    vec3 maths::operator*(const vec3 & aa, const float  bb) { return vec3(aa.x * bb, aa.y * bb, aa.z * bb); }
    vec3 maths::operator*(const vec3 & aa, const vec3 & bb) { return vec3(aa.x * bb.x, aa.y * bb.y, aa.z * bb.z); }
    vec3 maths::operator/(const float  bb, const vec3 & aa) { return vec3(aa.x / bb, aa.y / bb, aa.z / bb); }
    vec3 maths::operator/(const vec3 & aa, const float  bb) { return vec3(aa.x / bb, aa.y / bb, aa.z / bb); }
    vec3 maths::operator/(const vec3 & aa, const vec3 & bb) { return vec3(aa.x / bb.x, aa.y / bb.y, aa.z / bb.z); }
    bool maths::operator==(const vec3 & aa, const vec3 & bb) { return aa.x == bb.x && aa.y == bb.y && aa.z == bb.z; }
    bool maths::operator!=(const vec3 & aa, const vec3 & bb) { return aa.x != bb.x || aa.y != bb.y || aa.z != bb.z; }

// ***********************************************