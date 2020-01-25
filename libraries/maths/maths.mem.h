#pragma once

namespace maths
{
    namespace mem
    {
        // defaults
        typedef char      i08;
        typedef short     i16;
        typedef long      i32;
        typedef long long i64;
        typedef float     f32;
        typedef double    f64;

        // signed types
        typedef signed char      s08;
        typedef signed short     s16;
        typedef signed long      s32;
        typedef signed long long s64;

        // unsigned types
        typedef unsigned char      u08;
        typedef unsigned short     u16;
        typedef unsigned long      u32;
        typedef unsigned long long u64;

        // [memory] allocate memory
        template<typename T> static inline T* alc(const u64& cap)
        {
            return cap ? new T[cap] : 0;
        }

        // [memory] get data index
        template<typename T> static inline u64 idx(const T* const ref, const u64& cap, const T& val)
        {
            for (u64 i = 0; i < cap; i++) if (ref[i] == val) return i; return cap;
        }

        // [memory] move memory data
        template<typename T> static inline void mov(T& lhs, T& rhs)
        {
            lhs = rhs; rhs = T{};
        }

        // [memory] swap memory data
        template<typename T> static inline void swp(T& lhs, T& rhs)
        {
            static T t; t = lhs; lhs = rhs; rhs = t;
        }

        // [memory] release memory
        template<typename T> static inline void del(T* ref, const u64& cap)
        {
            if (cap) delete[] ref;
        }

        // [memory] set memory values
        template<typename T> static inline void set(T* ref, const T& rhs, const u64& cap, const u32& off = 0)
        {
            for (u32 i = off; i < cap; i++) ref[i] = rhs;
        }

        // [memory] copy memory values
        template<typename T> static inline void cpy(T* ref, const T* const rhs, const u64& cap, const u32& off = 0)
        {
            for (u32 i = off; i < cap; i++) ref[i] = rhs[i];
        }

        // [memory] compare memory values
        template<typename T> static inline bool cmp(const T* const lhs, const T* const rhs, const u64& cap)
        {
            for (u32 i = 0; i < cap; i++) if (lhs[i] != rhs[i]) return 0; return cap;
        }

    }; // namespace mem
}; // namespace maths