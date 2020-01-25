#pragma once

#include "maths.buf.h"

namespace maths {

    template<typename T, unsigned int A1> class swz1 {
        T data[1];
    public:
        operator const T&() const { return data[A1]; };
        swz1& operator=(const T& n) { data[A1] = n; return *this; };
        template<unsigned int B1>
        swz1& operator=(swz1<T, B1>& n) { data[A1] = n[B1]; return *this; };
    };

    template<typename T, unsigned int A1, unsigned int A2> class swz2 {
        T data[1];
    public:
        operator const buf<T,2>() const { return { { data[A1], data[A2] } }; };
        swz2& operator=(const T& n) { data[A1] = data[A2] = n; return *this; };
        swz2& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; return *this; };
        template<unsigned int B1, unsigned int B2>
        swz2& operator=(swz2<T, B1, B2>& n) { data[A1] = n[B1]; data[A2] = n[B2]; return *this; };
    };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3> class swz3 {
        T data[1];
    public:
        operator const buf<T, 3>() const { return { { data[A1], data[A2], data[A3] } }; };
        swz3& operator=(const T& n) { data[A1] = data[A2] = data[A3] = n; return *this; };
        swz3& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; data[A3] = n[2]; return *this; };
        template<unsigned int B1, unsigned int B2, unsigned int B3>
        swz3& operator=(swz3<T, B1, B2, B3>& n) { data[A1] = n[B1]; data[A2] = n[B2]; data[A3] = n[B3]; return *this; };
    };

    template<typename T, unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4> class swz4 {
        T data[1];
    public:
        operator const buf<T, 4>() const { return { { data[A1], data[A2], data[A3], data[A4] } }; };
        swz4& operator=(const T& n) { data[A1] = data[A2] = data[A3] = data[A4] = n; return *this; };
        swz4& operator=(const T* n) { data[A1] = n[0]; data[A2] = n[1]; data[A3] = n[2]; data[A4] = n[3]; return *this; };
        template<unsigned int B1, unsigned int B2, unsigned int B3, unsigned int B4>
        swz4& operator=(swz4<T, B1, B2, B3, B4>& n) { data[A1] = n[B1]; data[A2] = n[B2]; data[A3] = n[B3]; data[A4] = n[B4]; return *this; };
    };

}; // namespace maths