#pragma once

namespace maths
{
    // ** Object Declarations ************************

        // vec2 :: declaration
        struct vec2
        {
            float x, y;
            // methods
            vec2();
            vec2(float n);
            vec2(const vec2 & n);
            vec2(float x, float y);
            void operator=(const vec2 & n);
            float & operator[](const int index);
            const float & operator[](const int index) const;
        };
        // vec3 :: declaration
        struct vec3
        {
            float x, y, z;
            // methods
            vec3();
            vec3(float n);
            vec3(const vec3 & n);
            vec3(float n, const vec2 & v);
            vec3(const vec2 & v, float n);
            vec3(float x, float y, float z);
            void operator=(const vec3 & n);
            float & operator[](const int index);
            const float & operator[](const int index) const;
        };
        // vec4 :: declaration
        struct vec4
        {
            float x, y, z, w;
            // methods
            vec4();
            vec4(float n);
            vec4(const vec4 & n);
            vec4(float n, const vec3 & v);
            vec4(const vec3 & v, float n);
            vec4(float x, float y, float z, float w);
            void operator=(const vec4 & n);
            float & operator[](const int index);
            const float & operator[](const int index) const;
        };
        // mat2 :: declaration
		struct mat2
		{
            vec2 elements[2];
            // methods
            mat2();
			mat2(float n);
			mat2(const mat2 & n);
			void operator=(const mat2 & n);
			vec2 & operator[](const int index);
            const vec2 & operator[](const int index) const;
		};
        // mat3 :: declaration
		struct mat3
		{
		    vec3 elements[3];
            // methods
		    mat3();
		    mat3(float n);
		    mat3(const mat3 & n);
		    void operator=(const mat3 & n);
            vec3 & operator[](const int index);
            const vec3 & operator[](const int index) const;
		};
        // mat4 :: declaration
        struct mat4
        {
            vec4 elements[4];
            // methods
            mat4();
            mat4(float n);
            mat4(const mat4 & n);
            void operator=(const mat4 & n);
            vec4 & operator[](const int index);
            const vec4 & operator[](const int index) const;
        };

    // ** Method Declarations ************************

        // maths :: core methods
        float dot(const vec2 & v1, const vec2 & v2);
        float dot(const vec3 & v1, const vec3 & v2);
        float dot(const vec4 & v1, const vec4 & v2);
        float length(const vec2 & vec);
        float length(const vec3 & vec);
        float length(const vec4 & vec);
        mat4 scale(const vec3 & vec);
        vec3 cross(const vec3 & v1, const vec3 & v2);
        mat4 rotate(const vec3 & vec, float angle);
        vec2 normalize(const vec2 & vec);
        vec3 normalize(const vec3 & vec);
        vec4 normalize(const vec4 & vec);
        mat4 translate(const vec3 & vec);
        mat4 perspective(float fov, float ar, float near, float far);

        // vec2 :: operator overloading
        vec2 operator+(const float n, const vec2 & v2);
        vec2 operator-(const float n, const vec2 & v2);
        vec2 operator*(const float n, const vec2 & v2);
        vec2 operator/(const float n, const vec2 & v2);
        vec2 operator+(const vec2 & v1, const float n);
        vec2 operator-(const vec2 & v1, const float n);
        vec2 operator*(const vec2 & v1, const float n);
        vec2 operator/(const vec2 & v1, const float n);
        vec2 operator+(const vec2 & v1, const vec2 & v2);
        vec2 operator-(const vec2 & v1, const vec2 & v2);
        vec2 operator*(const vec2 & v1, const vec2 & v2);
        vec2 operator/(const vec2 & v1, const vec2 & v2);
        bool operator==(const vec2 & v1, const vec2 & v2);
        bool operator!=(const vec2 & v1, const vec2 & v2);

        // vec3 :: operator overloading
        vec3 operator+(const float n, const vec3 & v2);
        vec3 operator-(const float n, const vec3 & v2);
        vec3 operator*(const float n, const vec3 & v2);
        vec3 operator/(const float n, const vec3 & v2);
        vec3 operator+(const vec3 & v1, const float n);
        vec3 operator-(const vec3 & v1, const float n);
        vec3 operator*(const vec3 & v1, const float n);
        vec3 operator/(const vec3 & v1, const float n);
        vec3 operator+(const vec3 & v1, const vec3 & v2);
        vec3 operator-(const vec3 & v1, const vec3 & v2);
        vec3 operator*(const vec3 & v1, const vec3 & v2);
        vec3 operator/(const vec3 & v1, const vec3 & v2);
        bool operator==(const vec3 & v1, const vec3 & v2);
        bool operator!=(const vec3 & v1, const vec3 & v2);

        // vec4 :: operator overloading
        vec4 operator+(const float n, const vec4 & v2);
        vec4 operator-(const float n, const vec4 & v2);
        vec4 operator*(const float n, const vec4 & v2);
        vec4 operator/(const float n, const vec4 & v2);
        vec4 operator+(const vec4 & v1, const float n);
        vec4 operator-(const vec4 & v1, const float n);
        vec4 operator*(const vec4 & v1, const float n);
        vec4 operator/(const vec4 & v1, const float n);
        vec4 operator+(const vec4 & v1, const vec4 & v2);
        vec4 operator-(const vec4 & v1, const vec4 & v2);
        vec4 operator*(const vec4 & v1, const vec4 & v2);
        vec4 operator/(const vec4 & v1, const vec4 & v2);
        bool operator==(const vec4 & v1, const vec4 & v2);
        bool operator!=(const vec4 & v1, const vec4 & v2);

        // mat3 :: operator overloading
        vec2 operator*(const mat2 & aa, const vec2 & bb);
        mat2 operator*(const mat2 & aa, const mat2 & bb);
        bool operator==(const mat2 & aa, const mat2 & bb);
        bool operator!=(const mat2 & aa, const mat2 & bb);

        // mat3 :: operator overloading
        vec3 operator*(const mat3 & aa, const vec3 & bb);
        mat3 operator*(const mat3 & aa, const mat3 & bb);
        bool operator==(const mat3 & aa, const mat3 & bb);
        bool operator!=(const mat3 & aa, const mat3 & bb);

        // mat4 :: operator overloading
        vec4 operator*(const mat4 & aa, const vec4 & bb);
        mat4 operator*(const mat4 & aa, const mat4 & bb);
        bool operator==(const mat4 & aa, const mat4 & bb);
        bool operator!=(const mat4 & aa, const mat4 & bb);

	// ***********************************************
} // namespace maths