#pragma once

#include "maths.mem.h"

namespace maths {

    template<typename T, unsigned int S> class buf { public:
        T data[S];

        virtual ~buf() {};
        buf() { mem::set<T>(data, T{ 0 }, S); };
        buf(const T& a) { mem::set<T>(data, a, S); };
        buf(const T* a) { mem::cpy<T>(data, a, S); };
        buf(const buf& a) { mem::cpy<T>(data, a, S); };
        buf(const T(&a)[S]) { mem::cpy<T>(data, a, S); };
        
        operator T* () { return data; };
        operator const T* ()const { return data; };
        buf operator+(const T& a) { buf n{ *this }; n += a; return n; };
        buf operator-(const T& a) { buf n{ *this }; n -= a; return n; };
        buf operator*(const T& a) { buf n{ *this }; n *= a; return n; };
        buf operator/(const T& a) { buf n{ *this }; n /= a; return n; };
        buf operator+(const T* a) { buf n{ *this }; n += a; return n; };
        buf operator-(const T* a) { buf n{ *this }; n -= a; return n; };
        buf operator*(const T* a) { buf n{ *this }; n *= a; return n; };
        buf operator/(const T* a) { buf n{ *this }; n /= a; return n; };
        buf& operator=(const T* a) { mem::cpy<T>(data, a, S); return*this; };
        buf& operator=(const T& a) { mem::set<T>(data, a, S); return*this; };
        buf& operator=(const buf& a) { mem::cpy<T>(data, a, S); return*this; };
        buf& operator=(const T(&a)[S]) { mem::cpy<T>(data, a, S); return*this; };
        buf& operator+=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] += a; return*this; };
        buf& operator-=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] -= a; return*this; };
        buf& operator*=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] *= a; return*this; };
        buf& operator/=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] /= a; return*this; };
        buf& operator+=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] += a[i]; return*this; };
        buf& operator-=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] -= a[i]; return*this; };
        buf& operator*=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] *= a[i]; return*this; };
        buf& operator/=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] /= a[i]; return*this; };
    };

}; // namespace maths