#include "m2c.h"

/* s16 sine/cosine pairs: [i * 2] = sin, [i * 2 + 1] = cos, i = angle >> 4 */
extern const s16 data_020f88c4[];

void func_020c8244(s32 *m, s16 s, s16 c);

enum {
    FX32_SHIFT        = 12,      /* 20.12 fixed-point fraction bits */
    FX32_HALF         = 0x800,    /* rounding term added before the shift */
    ANGLE_INDEX_SHIFT = 4 /* u16 angle >> 4 = sine table entry */
};

typedef struct {
    u16 v;
} Ang;

static inline int ang_eq(u16 a, Ang b) {
    return a == b.v;
}

static inline int ang_is(u16 a, u16 v) {
    return ang_eq(a, (Ang) {v});
}

static inline s32 fx_sin(u16 a) {
    return data_020f88c4[(a >> ANGLE_INDEX_SHIFT) * 2];
}

static inline s32 fx_cos(u16 a) {
    return data_020f88c4[(a >> ANGLE_INDEX_SHIFT) * 2 + 1];
}

static inline s32 fx_mul(s32 a, s32 b) {
    return ((s64) a * b + FX32_HALF) >> FX32_SHIFT;
}

/*
 * Build the 3x3 fixed-point rotation matrix m (9 s32 entries) from three
 * u16 angles rot[0..2] (callers pass an object's rotation and matrix).
 * When rot[0] and rot[2] are both zero only rot[1] remains, and the
 * matrix is built by func_020c8244 from the sine/cosine of rot[1].
 * func_01ffa958 multiplies vectors by the resulting matrix.
 */
void func_01ffa6f8(s32 *m, u16 *rot) {
    s32 sx, cx, sy, cy, sz, cz;
    s32 sxsz, sxcz;

    if ((ang_is(rot[0], 0) && ang_is(rot[2], 0)) != 0) {
        func_020c8244(m, data_020f88c4[(rot[1] >> ANGLE_INDEX_SHIFT) * 2],
                      data_020f88c4[(rot[1] >> ANGLE_INDEX_SHIFT) * 2 + 1]);
        return;
    }
    sx   = fx_sin(rot[0]);
    cx   = fx_cos(rot[0]);
    sy   = fx_sin(rot[1]);
    cy   = fx_cos(rot[1]);
    sz   = fx_sin(rot[2]);
    cz   = fx_cos(rot[2]);
    sxsz = fx_mul(sx, sz);
    sxcz = fx_mul(sx, cz);
    m[0] = fx_mul(cy, cz) + fx_mul(sy, sxsz);
    m[1] = fx_mul(cx, sz);
    m[2] = fx_mul(cy, sxsz) - fx_mul(sy, cz);
    m[3] = fx_mul(sy, sxcz) - fx_mul(sz, cy);
    m[4] = fx_mul(cx, cz);
    m[5] = fx_mul(sy, sz) + fx_mul(sxcz, cy);
    m[6] = fx_mul(cx, sy);
    m[7] = -sx;
    m[8] = fx_mul(cx, cy);
}
