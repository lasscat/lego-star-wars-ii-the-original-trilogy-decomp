#include "m2c.h"

enum {
    REG_DIVCNT      = 0x04000280,
    REG_DIV_NUMER   = 0x04000290,
    REG_DIV_DENOM   = 0x04000298,
    REG_DIV_RESULT  = 0x040002a0,
    REG_SQRTCNT     = 0x040002b0,
    REG_SQRT_RESULT = 0x040002b4,
    REG_SQRT_PARAM  = 0x040002b8,
    DIV_MODE_64_64  = 2,
    SQRT_MODE_64    = 1,
    MATH_BUSY       = 0x8000,
};

typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad00[0x28];
    s32 scale_xz;
    s32 scale_y;
} Shape;

extern Vec3 data_020ff9b4;

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void vec_normalize(Vec3 *d, const Vec3 *s) {
    s64 t;
    s32 sqrt;
    s64 div;

    t = (s64) s->x * s->x;
    t += (s64) s->y * s->y;
    t += (s64) s->z * s->z;

    (*(vu16 *) REG_DIVCNT)    = DIV_MODE_64_64;
    (*(vu64 *) REG_DIV_NUMER) = 1LL << 56;
    (*(vu64 *) REG_DIV_DENOM) = t;

    (*(vu16 *) REG_SQRTCNT)   = SQRT_MODE_64;
    (*(u64 *) REG_SQRT_PARAM) = t << 2;

    while ((*(vu16 *) REG_SQRTCNT) & MATH_BUSY) {
    }
    sqrt = (s32) (*(vu32 *) REG_SQRT_RESULT);

    while ((*(vu16 *) REG_DIVCNT) & MATH_BUSY) {
    }
    div = (s64) (*(u64 *) REG_DIV_RESULT);

    div *= sqrt;

    d->x = (s32) ((div * s->x + (1LL << 44)) >> 45);
    d->y = (s32) ((div * s->y + (1LL << 44)) >> 45);
    d->z = (s32) ((div * s->z + (1LL << 44)) >> 45);
}

static inline void vec_unit_self(Vec3 *v) {
    if (v->x == 0 && v->y == 0 && v->z == 0) {
        vec_set(v, &data_020ff9b4);
    } else {
        vec_normalize(v, v);
    }
}

enum {
    FX32_SHIFT = 12,
    FX32_HALF  = 0x800,
    FX32_ONE   = 0x1000,
};

static inline s32 fx_mul(s32 a, s32 b) {
    s64 t = a;
    t     = (t * b + FX32_HALF) >> FX32_SHIFT;
    return (s32) t;
}

/* Scales v by the shape's xz and y factors (each >> 6). If the scaled x^2 + z^2
   exceeds y^2, out = v with y cleared, normalized (data_020ff9b4 if zero);
   otherwise out = (0, +-FX32_ONE, 0) by the sign of v.y. */
void func_0204cb60(Vec3 *out, Shape *shape, Vec3 v) {
    Vec3 p;
    s32 xx;
    s32 yy;
    s32 zz;

    p.x = shape->scale_xz;
    p.z = shape->scale_xz;
    p.x = fx_mul(v.x, p.x) >> 6;
    p.y = fx_mul(v.y, shape->scale_y) >> 6;
    yy  = fx_mul(p.y, p.y);
    p.z = fx_mul(v.z, p.z) >> 6;
    zz  = fx_mul(p.z, p.z);
    xx  = fx_mul(p.x, p.x);

    if (xx + zz > yy) {
        v.y = 0;
        vec_unit_self(&v);
        out->x = v.x;
        out->y = v.y;
        out->z = v.z;
    } else if (v.y > 0) {
        out->x = 0;
        out->y = FX32_ONE;
        out->z = 0;
    } else {
        out->x = 0;
        out->y = -FX32_ONE;
        out->z = 0;
    }
}
