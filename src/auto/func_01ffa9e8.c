#include "m2c.h"

/* s16 sine/cosine pairs: [i * 2] = sin, [i * 2 + 1] = cos, i = angle >> 4 */
extern const s16 data_020f88c4[];

typedef struct {
    s32 m[4][4];
} Mtx44;

enum {
    FX32_SHIFT        = 12,    /* 20.12 fixed-point fraction bits */
    FX32_HALF         = 0x800, /* rounding term added before the shift */
    ANGLE_INDEX_SHIFT = 4      /* u16 angle >> 4 = sine table entry */
};

static inline s32 fx_sin(u16 a) {
    return data_020f88c4[(a >> ANGLE_INDEX_SHIFT) * 2];
}

static inline s32 fx_cos(u16 a) {
    return data_020f88c4[(a >> ANGLE_INDEX_SHIFT) * 2 + 1];
}

static inline s32 fx_mul(s32 a, s32 b) {
    return ((s64) a * b + FX32_HALF) >> FX32_SHIFT;
}

typedef struct {
    u16 v;
} Angle;

/*
 * Build the rotation part (rows 0-2, columns 0-2) of the 4x4 fixed-point
 * matrix m from three u16 angles rot[0..2]; the other entries are not
 * written. The products are the same as in the 3x3 builder func_01ffa6f8.
 * func_020a0478 rebuilds an object's matrix at +0x60 from its angles at
 * +0x40; func_020a41f4 builds a local matrix from its angles at +0x40,
 * which func_01ffac98 then applies.
 */
void func_01ffa9e8(Mtx44 *m, Angle *rot) {
    s32 sx, cx, sy, cy, sz, cz;
    s32 sxsz, sxcz;

    sx         = fx_sin(rot[0].v);
    cx         = fx_cos(rot[0].v);
    sy         = fx_sin(rot[1].v);
    cy         = fx_cos(rot[1].v);
    sz         = fx_sin(rot[2].v);
    cz         = fx_cos(rot[2].v);
    sxsz       = fx_mul(sx, sz);
    sxcz       = fx_mul(sx, cz);
    m->m[0][0] = fx_mul(cy, cz) + fx_mul(sy, sxsz);
    m->m[0][1] = fx_mul(cx, sz);
    m->m[0][2] = fx_mul(cy, sxsz) - fx_mul(sy, cz);
    m->m[1][0] = fx_mul(sy, sxcz) - fx_mul(sz, cy);
    m->m[1][1] = fx_mul(cx, cz);
    m->m[1][2] = fx_mul(sy, sz) + fx_mul(sxcz, cy);
    m->m[2][0] = fx_mul(cx, sy);
    m->m[2][1] = -sx;
    m->m[2][2] = fx_mul(cx, cy);
}
