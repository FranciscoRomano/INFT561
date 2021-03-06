#pragma once

#include "maths.swz.h"

namespace maths {

    template<typename T, unsigned int S> class vec { public:
        union {
            T data[S];
            // 1 parameter swizzle
            swz1<T, 0> x, r;
            swz1<T, 1> y, g;
            swz1<T, 2> z, b;
            swz1<T, 3> w, a;
            // 2 parameter swizzle
            swz2<T, 0, 0> xx, rr;
            swz2<T, 0, 1> xy, rg;
            swz2<T, 0, 2> xz, rb;
            swz2<T, 0, 3> xw, ra;
            swz2<T, 1, 0> yx, gr;
            swz2<T, 1, 1> yy, gg;
            swz2<T, 1, 2> yz, gb;
            swz2<T, 1, 3> yw, ga;
            swz2<T, 2, 0> zx, br;
            swz2<T, 2, 1> zy, bg;
            swz2<T, 2, 2> zz, bb;
            swz2<T, 2, 3> zw, ba;
            swz2<T, 3, 0> wx, ar;
            swz2<T, 3, 1> wy, ag;
            swz2<T, 3, 2> wz, ab;
            swz2<T, 3, 3> ww, aa;
            // 3 parameter swizzle
            swz3<T, 0, 0, 0> xxx, rrr;
            swz3<T, 0, 0, 1> xxy, rrg;
            swz3<T, 0, 0, 2> xxz, rrb;
            swz3<T, 0, 0, 3> xxw, rra;
            swz3<T, 0, 1, 0> xyx, rgr;
            swz3<T, 0, 1, 1> xyy, rgg;
            swz3<T, 0, 1, 2> xyz, rgb;
            swz3<T, 0, 1, 3> xyw, rga;
            swz3<T, 0, 2, 0> xzx, rbr;
            swz3<T, 0, 2, 1> xzy, rbg;
            swz3<T, 0, 2, 2> xzz, rbb;
            swz3<T, 0, 2, 3> xzw, rba;
            swz3<T, 0, 3, 0> xwx, rar;
            swz3<T, 0, 3, 1> xwy, rag;
            swz3<T, 0, 3, 2> xwz, rab;
            swz3<T, 0, 3, 3> xww, raa;
            swz3<T, 1, 0, 0> yxx, grr;
            swz3<T, 1, 0, 1> yxy, grg;
            swz3<T, 1, 0, 2> yxz, grb;
            swz3<T, 1, 0, 3> yxw, gra;
            swz3<T, 1, 1, 0> yyx, ggr;
            swz3<T, 1, 1, 1> yyy, ggg;
            swz3<T, 1, 1, 2> yyz, ggb;
            swz3<T, 1, 1, 3> yyw, gga;
            swz3<T, 1, 2, 0> yzx, gbr;
            swz3<T, 1, 2, 1> yzy, gbg;
            swz3<T, 1, 2, 2> yzz, gbb;
            swz3<T, 1, 2, 3> yzw, gba;
            swz3<T, 1, 3, 0> ywx, gar;
            swz3<T, 1, 3, 1> ywy, gag;
            swz3<T, 1, 3, 2> ywz, gab;
            swz3<T, 1, 3, 3> yww, gaa;
            swz3<T, 2, 0, 0> zxx, brr;
            swz3<T, 2, 0, 1> zxy, brg;
            swz3<T, 2, 0, 2> zxz, brb;
            swz3<T, 2, 0, 3> zxw, bra;
            swz3<T, 2, 1, 0> zyx, bgr;
            swz3<T, 2, 1, 1> zyy, bgg;
            swz3<T, 2, 1, 2> zyz, bgb;
            swz3<T, 2, 1, 3> zyw, bga;
            swz3<T, 2, 2, 0> zzx, bbr;
            swz3<T, 2, 2, 1> zzy, bbg;
            swz3<T, 2, 2, 2> zzz, bbb;
            swz3<T, 2, 2, 3> zzw, bba;
            swz3<T, 2, 3, 0> zwx, bar;
            swz3<T, 2, 3, 1> zwy, bag;
            swz3<T, 2, 3, 2> zwz, bab;
            swz3<T, 2, 3, 3> zww, baa;
            swz3<T, 3, 0, 0> wxx, arr;
            swz3<T, 3, 0, 1> wxy, arg;
            swz3<T, 3, 0, 2> wxz, arb;
            swz3<T, 3, 0, 3> wxw, ara;
            swz3<T, 3, 1, 0> wyx, agr;
            swz3<T, 3, 1, 1> wyy, agg;
            swz3<T, 3, 1, 2> wyz, agb;
            swz3<T, 3, 1, 3> wyw, aga;
            swz3<T, 3, 2, 0> wzx, abr;
            swz3<T, 3, 2, 1> wzy, abg;
            swz3<T, 3, 2, 2> wzz, abb;
            swz3<T, 3, 2, 3> wzw, aba;
            swz3<T, 3, 3, 0> wwx, aar;
            swz3<T, 3, 3, 1> wwy, aag;
            swz3<T, 3, 3, 2> wwz, aab;
            swz3<T, 3, 3, 3> www, aaa;
            // 4 parameter swizzle
            swz4<T, 0, 0, 0, 0> xxxx, rrrr;
            swz4<T, 0, 0, 0, 1> xxxy, rrrg;
            swz4<T, 0, 0, 0, 2> xxxz, rrrb;
            swz4<T, 0, 0, 0, 3> xxxw, rrra;
            swz4<T, 0, 0, 1, 0> xxyx, rrgr;
            swz4<T, 0, 0, 1, 1> xxyy, rrgg;
            swz4<T, 0, 0, 1, 2> xxyz, rrgb;
            swz4<T, 0, 0, 1, 3> xxyw, rrga;
            swz4<T, 0, 0, 2, 0> xxzx, rrbr;
            swz4<T, 0, 0, 2, 1> xxzy, rrbg;
            swz4<T, 0, 0, 2, 2> xxzz, rrbb;
            swz4<T, 0, 0, 2, 3> xxzw, rrba;
            swz4<T, 0, 0, 3, 0> xxwx, rrar;
            swz4<T, 0, 0, 3, 1> xxwy, rrag;
            swz4<T, 0, 0, 3, 2> xxwz, rrab;
            swz4<T, 0, 0, 3, 3> xxww, rraa;
            swz4<T, 0, 1, 0, 0> xyxx, rgrr;
            swz4<T, 0, 1, 0, 1> xyxy, rgrg;
            swz4<T, 0, 1, 0, 2> xyxz, rgrb;
            swz4<T, 0, 1, 0, 3> xyxw, rgra;
            swz4<T, 0, 1, 1, 0> xyyx, rggr;
            swz4<T, 0, 1, 1, 1> xyyy, rggg;
            swz4<T, 0, 1, 1, 2> xyyz, rggb;
            swz4<T, 0, 1, 1, 3> xyyw, rgga;
            swz4<T, 0, 1, 2, 0> xyzx, rgbr;
            swz4<T, 0, 1, 2, 1> xyzy, rgbg;
            swz4<T, 0, 1, 2, 2> xyzz, rgbb;
            swz4<T, 0, 1, 2, 3> xyzw, rgba;
            swz4<T, 0, 1, 3, 0> xywx, rgar;
            swz4<T, 0, 1, 3, 1> xywy, rgag;
            swz4<T, 0, 1, 3, 2> xywz, rgab;
            swz4<T, 0, 1, 3, 3> xyww, rgaa;
            swz4<T, 0, 2, 0, 0> xzxx, rbrr;
            swz4<T, 0, 2, 0, 1> xzxy, rbrg;
            swz4<T, 0, 2, 0, 2> xzxz, rbrb;
            swz4<T, 0, 2, 0, 3> xzxw, rbra;
            swz4<T, 0, 2, 1, 0> xzyx, rbgr;
            swz4<T, 0, 2, 1, 1> xzyy, rbgg;
            swz4<T, 0, 2, 1, 2> xzyz, rbgb;
            swz4<T, 0, 2, 1, 3> xzyw, rbga;
            swz4<T, 0, 2, 2, 0> xzzx, rbbr;
            swz4<T, 0, 2, 2, 1> xzzy, rbbg;
            swz4<T, 0, 2, 2, 2> xzzz, rbbb;
            swz4<T, 0, 2, 2, 3> xzzw, rbba;
            swz4<T, 0, 2, 3, 0> xzwx, rbar;
            swz4<T, 0, 2, 3, 1> xzwy, rbag;
            swz4<T, 0, 2, 3, 2> xzwz, rbab;
            swz4<T, 0, 2, 3, 3> xzww, rbaa;
            swz4<T, 0, 3, 0, 0> xwxx, rarr;
            swz4<T, 0, 3, 0, 1> xwxy, rarg;
            swz4<T, 0, 3, 0, 2> xwxz, rarb;
            swz4<T, 0, 3, 0, 3> xwxw, rara;
            swz4<T, 0, 3, 1, 0> xwyx, ragr;
            swz4<T, 0, 3, 1, 1> xwyy, ragg;
            swz4<T, 0, 3, 1, 2> xwyz, ragb;
            swz4<T, 0, 3, 1, 3> xwyw, raga;
            swz4<T, 0, 3, 2, 0> xwzx, rabr;
            swz4<T, 0, 3, 2, 1> xwzy, rabg;
            swz4<T, 0, 3, 2, 2> xwzz, rabb;
            swz4<T, 0, 3, 2, 3> xwzw, raba;
            swz4<T, 0, 3, 3, 0> xwwx, raar;
            swz4<T, 0, 3, 3, 1> xwwy, raag;
            swz4<T, 0, 3, 3, 2> xwwz, raab;
            swz4<T, 0, 3, 3, 3> xwww, raaa;
            swz4<T, 1, 0, 0, 0> yxxx, grrr;
            swz4<T, 1, 0, 0, 1> yxxy, grrg;
            swz4<T, 1, 0, 0, 2> yxxz, grrb;
            swz4<T, 1, 0, 0, 3> yxxw, grra;
            swz4<T, 1, 0, 1, 0> yxyx, grgr;
            swz4<T, 1, 0, 1, 1> yxyy, grgg;
            swz4<T, 1, 0, 1, 2> yxyz, grgb;
            swz4<T, 1, 0, 1, 3> yxyw, grga;
            swz4<T, 1, 0, 2, 0> yxzx, grbr;
            swz4<T, 1, 0, 2, 1> yxzy, grbg;
            swz4<T, 1, 0, 2, 2> yxzz, grbb;
            swz4<T, 1, 0, 2, 3> yxzw, grba;
            swz4<T, 1, 0, 3, 0> yxwx, grar;
            swz4<T, 1, 0, 3, 1> yxwy, grag;
            swz4<T, 1, 0, 3, 2> yxwz, grab;
            swz4<T, 1, 0, 3, 3> yxww, graa;
            swz4<T, 1, 1, 0, 0> yyxx, ggrr;
            swz4<T, 1, 1, 0, 1> yyxy, ggrg;
            swz4<T, 1, 1, 0, 2> yyxz, ggrb;
            swz4<T, 1, 1, 0, 3> yyxw, ggra;
            swz4<T, 1, 1, 1, 0> yyyx, gggr;
            swz4<T, 1, 1, 1, 1> yyyy, gggg;
            swz4<T, 1, 1, 1, 2> yyyz, gggb;
            swz4<T, 1, 1, 1, 3> yyyw, ggga;
            swz4<T, 1, 1, 2, 0> yyzx, ggbr;
            swz4<T, 1, 1, 2, 1> yyzy, ggbg;
            swz4<T, 1, 1, 2, 2> yyzz, ggbb;
            swz4<T, 1, 1, 2, 3> yyzw, ggba;
            swz4<T, 1, 1, 3, 0> yywx, ggar;
            swz4<T, 1, 1, 3, 1> yywy, ggag;
            swz4<T, 1, 1, 3, 2> yywz, ggab;
            swz4<T, 1, 1, 3, 3> yyww, ggaa;
            swz4<T, 1, 2, 0, 0> yzxx, gbrr;
            swz4<T, 1, 2, 0, 1> yzxy, gbrg;
            swz4<T, 1, 2, 0, 2> yzxz, gbrb;
            swz4<T, 1, 2, 0, 3> yzxw, gbra;
            swz4<T, 1, 2, 1, 0> yzyx, gbgr;
            swz4<T, 1, 2, 1, 1> yzyy, gbgg;
            swz4<T, 1, 2, 1, 2> yzyz, gbgb;
            swz4<T, 1, 2, 1, 3> yzyw, gbga;
            swz4<T, 1, 2, 2, 0> yzzx, gbbr;
            swz4<T, 1, 2, 2, 1> yzzy, gbbg;
            swz4<T, 1, 2, 2, 2> yzzz, gbbb;
            swz4<T, 1, 2, 2, 3> yzzw, gbba;
            swz4<T, 1, 2, 3, 0> yzwx, gbar;
            swz4<T, 1, 2, 3, 1> yzwy, gbag;
            swz4<T, 1, 2, 3, 2> yzwz, gbab;
            swz4<T, 1, 2, 3, 3> yzww, gbaa;
            swz4<T, 1, 3, 0, 0> ywxx, garr;
            swz4<T, 1, 3, 0, 1> ywxy, garg;
            swz4<T, 1, 3, 0, 2> ywxz, garb;
            swz4<T, 1, 3, 0, 3> ywxw, gara;
            swz4<T, 1, 3, 1, 0> ywyx, gagr;
            swz4<T, 1, 3, 1, 1> ywyy, gagg;
            swz4<T, 1, 3, 1, 2> ywyz, gagb;
            swz4<T, 1, 3, 1, 3> ywyw, gaga;
            swz4<T, 1, 3, 2, 0> ywzx, gabr;
            swz4<T, 1, 3, 2, 1> ywzy, gabg;
            swz4<T, 1, 3, 2, 2> ywzz, gabb;
            swz4<T, 1, 3, 2, 3> ywzw, gaba;
            swz4<T, 1, 3, 3, 0> ywwx, gaar;
            swz4<T, 1, 3, 3, 1> ywwy, gaag;
            swz4<T, 1, 3, 3, 2> ywwz, gaab;
            swz4<T, 1, 3, 3, 3> ywww, gaaa;
            swz4<T, 2, 0, 0, 0> zxxx, brrr;
            swz4<T, 2, 0, 0, 1> zxxy, brrg;
            swz4<T, 2, 0, 0, 2> zxxz, brrb;
            swz4<T, 2, 0, 0, 3> zxxw, brra;
            swz4<T, 2, 0, 1, 0> zxyx, brgr;
            swz4<T, 2, 0, 1, 1> zxyy, brgg;
            swz4<T, 2, 0, 1, 2> zxyz, brgb;
            swz4<T, 2, 0, 1, 3> zxyw, brga;
            swz4<T, 2, 0, 2, 0> zxzx, brbr;
            swz4<T, 2, 0, 2, 1> zxzy, brbg;
            swz4<T, 2, 0, 2, 2> zxzz, brbb;
            swz4<T, 2, 0, 2, 3> zxzw, brba;
            swz4<T, 2, 0, 3, 0> zxwx, brar;
            swz4<T, 2, 0, 3, 1> zxwy, brag;
            swz4<T, 2, 0, 3, 2> zxwz, brab;
            swz4<T, 2, 0, 3, 3> zxww, braa;
            swz4<T, 2, 1, 0, 0> zyxx, bgrr;
            swz4<T, 2, 1, 0, 1> zyxy, bgrg;
            swz4<T, 2, 1, 0, 2> zyxz, bgrb;
            swz4<T, 2, 1, 0, 3> zyxw, bgra;
            swz4<T, 2, 1, 1, 0> zyyx, bggr;
            swz4<T, 2, 1, 1, 1> zyyy, bggg;
            swz4<T, 2, 1, 1, 2> zyyz, bggb;
            swz4<T, 2, 1, 1, 3> zyyw, bgga;
            swz4<T, 2, 1, 2, 0> zyzx, bgbr;
            swz4<T, 2, 1, 2, 1> zyzy, bgbg;
            swz4<T, 2, 1, 2, 2> zyzz, bgbb;
            swz4<T, 2, 1, 2, 3> zyzw, bgba;
            swz4<T, 2, 1, 3, 0> zywx, bgar;
            swz4<T, 2, 1, 3, 1> zywy, bgag;
            swz4<T, 2, 1, 3, 2> zywz, bgab;
            swz4<T, 2, 1, 3, 3> zyww, bgaa;
            swz4<T, 2, 2, 0, 0> zzxx, bbrr;
            swz4<T, 2, 2, 0, 1> zzxy, bbrg;
            swz4<T, 2, 2, 0, 2> zzxz, bbrb;
            swz4<T, 2, 2, 0, 3> zzxw, bbra;
            swz4<T, 2, 2, 1, 0> zzyx, bbgr;
            swz4<T, 2, 2, 1, 1> zzyy, bbgg;
            swz4<T, 2, 2, 1, 2> zzyz, bbgb;
            swz4<T, 2, 2, 1, 3> zzyw, bbga;
            swz4<T, 2, 2, 2, 0> zzzx, bbbr;
            swz4<T, 2, 2, 2, 1> zzzy, bbbg;
            swz4<T, 2, 2, 2, 2> zzzz, bbbb;
            swz4<T, 2, 2, 2, 3> zzzw, bbba;
            swz4<T, 2, 2, 3, 0> zzwx, bbar;
            swz4<T, 2, 2, 3, 1> zzwy, bbag;
            swz4<T, 2, 2, 3, 2> zzwz, bbab;
            swz4<T, 2, 2, 3, 3> zzww, bbaa;
            swz4<T, 2, 3, 0, 0> zwxx, barr;
            swz4<T, 2, 3, 0, 1> zwxy, barg;
            swz4<T, 2, 3, 0, 2> zwxz, barb;
            swz4<T, 2, 3, 0, 3> zwxw, bara;
            swz4<T, 2, 3, 1, 0> zwyx, bagr;
            swz4<T, 2, 3, 1, 1> zwyy, bagg;
            swz4<T, 2, 3, 1, 2> zwyz, bagb;
            swz4<T, 2, 3, 1, 3> zwyw, baga;
            swz4<T, 2, 3, 2, 0> zwzx, babr;
            swz4<T, 2, 3, 2, 1> zwzy, babg;
            swz4<T, 2, 3, 2, 2> zwzz, babb;
            swz4<T, 2, 3, 2, 3> zwzw, baba;
            swz4<T, 2, 3, 3, 0> zwwx, baar;
            swz4<T, 2, 3, 3, 1> zwwy, baag;
            swz4<T, 2, 3, 3, 2> zwwz, baab;
            swz4<T, 2, 3, 3, 3> zwww, baaa;
            swz4<T, 3, 0, 0, 0> wxxx, arrr;
            swz4<T, 3, 0, 0, 1> wxxy, arrg;
            swz4<T, 3, 0, 0, 2> wxxz, arrb;
            swz4<T, 3, 0, 0, 3> wxxw, arra;
            swz4<T, 3, 0, 1, 0> wxyx, argr;
            swz4<T, 3, 0, 1, 1> wxyy, argg;
            swz4<T, 3, 0, 1, 2> wxyz, argb;
            swz4<T, 3, 0, 1, 3> wxyw, arga;
            swz4<T, 3, 0, 2, 0> wxzx, arbr;
            swz4<T, 3, 0, 2, 1> wxzy, arbg;
            swz4<T, 3, 0, 2, 2> wxzz, arbb;
            swz4<T, 3, 0, 2, 3> wxzw, arba;
            swz4<T, 3, 0, 3, 0> wxwx, arar;
            swz4<T, 3, 0, 3, 1> wxwy, arag;
            swz4<T, 3, 0, 3, 2> wxwz, arab;
            swz4<T, 3, 0, 3, 3> wxww, araa;
            swz4<T, 3, 1, 0, 0> wyxx, agrr;
            swz4<T, 3, 1, 0, 1> wyxy, agrg;
            swz4<T, 3, 1, 0, 2> wyxz, agrb;
            swz4<T, 3, 1, 0, 3> wyxw, agra;
            swz4<T, 3, 1, 1, 0> wyyx, aggr;
            swz4<T, 3, 1, 1, 1> wyyy, aggg;
            swz4<T, 3, 1, 1, 2> wyyz, aggb;
            swz4<T, 3, 1, 1, 3> wyyw, agga;
            swz4<T, 3, 1, 2, 0> wyzx, agbr;
            swz4<T, 3, 1, 2, 1> wyzy, agbg;
            swz4<T, 3, 1, 2, 2> wyzz, agbb;
            swz4<T, 3, 1, 2, 3> wyzw, agba;
            swz4<T, 3, 1, 3, 0> wywx, agar;
            swz4<T, 3, 1, 3, 1> wywy, agag;
            swz4<T, 3, 1, 3, 2> wywz, agab;
            swz4<T, 3, 1, 3, 3> wyww, agaa;
            swz4<T, 3, 2, 0, 0> wzxx, abrr;
            swz4<T, 3, 2, 0, 1> wzxy, abrg;
            swz4<T, 3, 2, 0, 2> wzxz, abrb;
            swz4<T, 3, 2, 0, 3> wzxw, abra;
            swz4<T, 3, 2, 1, 0> wzyx, abgr;
            swz4<T, 3, 2, 1, 1> wzyy, abgg;
            swz4<T, 3, 2, 1, 2> wzyz, abgb;
            swz4<T, 3, 2, 1, 3> wzyw, abga;
            swz4<T, 3, 2, 2, 0> wzzx, abbr;
            swz4<T, 3, 2, 2, 1> wzzy, abbg;
            swz4<T, 3, 2, 2, 2> wzzz, abbb;
            swz4<T, 3, 2, 2, 3> wzzw, abba;
            swz4<T, 3, 2, 3, 0> wzwx, abar;
            swz4<T, 3, 2, 3, 1> wzwy, abag;
            swz4<T, 3, 2, 3, 2> wzwz, abab;
            swz4<T, 3, 2, 3, 3> wzww, abaa;
            swz4<T, 3, 3, 0, 0> wwxx, aarr;
            swz4<T, 3, 3, 0, 1> wwxy, aarg;
            swz4<T, 3, 3, 0, 2> wwxz, aarb;
            swz4<T, 3, 3, 0, 3> wwxw, aara;
            swz4<T, 3, 3, 1, 0> wwyx, aagr;
            swz4<T, 3, 3, 1, 1> wwyy, aagg;
            swz4<T, 3, 3, 1, 2> wwyz, aagb;
            swz4<T, 3, 3, 1, 3> wwyw, aaga;
            swz4<T, 3, 3, 2, 0> wwzx, aabr;
            swz4<T, 3, 3, 2, 1> wwzy, aabg;
            swz4<T, 3, 3, 2, 2> wwzz, aabb;
            swz4<T, 3, 3, 2, 3> wwzw, aaba;
            swz4<T, 3, 3, 3, 0> wwwx, aaar;
            swz4<T, 3, 3, 3, 1> wwwy, aaag;
            swz4<T, 3, 3, 3, 2> wwwz, aaab;
            swz4<T, 3, 3, 3, 3> wwww, aaaa;
        };

        virtual ~vec() {};
        vec() { mem::set<T>(data, T{ 0 }, S); };
        vec(const T& a) { mem::set<T>(data, a, S); };
        vec(const T* a) { mem::cpy<T>(data, a, S); };
        vec(const vec& a) { mem::cpy<T>(data, a, S); };
        vec(const T(&a)[S]) { mem::cpy<T>(data, a, S); };
        vec(const T& a, const T& b) : vec({ a, b }) {};
        vec(const T& a, const vec<T, 2>& b) : vec({ a, b.x, b.y }) {};
        vec(const vec<T, 2>& a, const T& b) : vec({ a.x, a.y, b }) {};
        vec(const T& a, const vec<T, 3>& b) : vec({ a, b.x, b.y, b.z }) {};
        vec(const vec<T, 3>& a, const T& b) : vec({ a.x, a.y, a.z, b }) {};
        vec(const vec<T, 2>& a, const vec<T, 2>& b) : vec({ a.x, a.y, b.x, b.y }) {};
        template<unsigned int A1>
        vec(const swz1<T, A1>& n) : vec((T)n) {}
        template<unsigned int A1, unsigned int A2>
        vec(const swz2<T, A1, A2>& n) : vec((buf<T, 2>)n) {}
        template<unsigned int A1, unsigned int A2, unsigned int A3>
        vec(const swz3<T, A1, A2, A3>& n) : vec((buf<T, 3>)n) {}
        template<unsigned int A1, unsigned int A2, unsigned int A3, unsigned int A4>
        vec(const swz4<T, A1, A2, A3, A4>& n) : vec((buf<T, 4>)n) {}

        operator T* () { return data; };
        operator const T* ()const { return data; };
        vec operator+(const T& a) { vec n{ *this }; n += a; return n; };
        vec operator-(const T& a) { vec n{ *this }; n -= a; return n; };
        vec operator*(const T& a) { vec n{ *this }; n *= a; return n; };
        vec operator/(const T& a) { vec n{ *this }; n /= a; return n; };
        vec operator+(const T* a) { vec n{ *this }; n += a; return n; };
        vec operator-(const T* a) { vec n{ *this }; n -= a; return n; };
        vec operator*(const T* a) { vec n{ *this }; n *= a; return n; };
        vec operator/(const T* a) { vec n{ *this }; n /= a; return n; };
        vec& operator=(const T* a) { mem::cpy<T>(data, a, S); return*this; };
        vec& operator=(const T& a) { mem::set<T>(data, a, S); return*this; };
        vec& operator=(const vec& a) { mem::cpy<T>(data, a, S); return*this; };
        vec& operator=(const T(&a)[S]) { mem::cpy<T>(data, a, S); return*this; };
        template<unsigned int A1>
        vec& operator=(const swz1<T, A1>& n) { mem::set<T>(data, (T)a, S); return*this; }
        vec& operator+=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] += a; return*this; };
        vec& operator-=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] -= a; return*this; };
        vec& operator*=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] *= a; return*this; };
        vec& operator/=(const T& a) { for (unsigned int i = 0; i < S; i++)data[i] /= a; return*this; };
        vec& operator+=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] += a[i]; return*this; };
        vec& operator-=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] -= a[i]; return*this; };
        vec& operator*=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] *= a[i]; return*this; };
        vec& operator/=(const T* a) { for (unsigned int i = 0; i < S; i++)data[i] /= a[i]; return*this; };
    };

}; // namespace maths