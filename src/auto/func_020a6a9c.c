#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

enum {
    FX_SHIFT = 12,     /* 20.12 fixed point */
    FX_HALF  = 0x800,  /* rounding bias: 0.5 in 20.12 */
    FX_ONE   = 0x1000, /* 1.0 in 20.12 */
};

extern s32 FX_Div(s32 num, s32 den);

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + FX_HALF) >> FX_SHIFT);
}

static inline int vec_is_zero(const Vec3 *v) {
    return v->x == 0 && v->y == 0 && v->z == 0;
}

/*
 * *out = dot(b - a, d) / dot(d, d), clamped to [0, 1.0] in 20.12 fixed
 * point (each product rounded separately). This is the parameter of the
 * projection of b onto the line through a with direction d. A zero d
 * gives 0. The second argument is unused.
 */
void func_020a6a9c(s32 *out, void *unused, Vec3 *a, Vec3 *b, Vec3 *d) {
    int x, y, z;
    int num;
    int den;
    s64 t;

    *out = 0;
    if (!vec_is_zero(d)) {
        z   = b->z - a->z;
        z   = fx_mul(z, d->z);
        y   = b->y - a->y;
        y   = fx_mul(y, d->y);
        x   = b->x - a->x;
        x   = fx_mul(x, d->x);
        num = x;
        num += y;
        num += z;
        t   = d->z;
        t   = (t * t + FX_HALF) >> FX_SHIFT;
        z   = t;
        t   = d->y;
        t   = (t * t + FX_HALF) >> FX_SHIFT;
        y   = t;
        t   = d->x;
        t   = (t * t + FX_HALF) >> FX_SHIFT;
        x   = t;
        den = x;
        den += y;
        den += z;
        *out = FX_Div(num, den);
    } else {
        *out = 0;
    }
    if (*out < 0) {
        *out = 0;
    } else if (*out > FX_ONE) {
        *out = FX_ONE;
    }
}
