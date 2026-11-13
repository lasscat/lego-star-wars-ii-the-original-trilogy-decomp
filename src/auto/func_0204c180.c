#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[0x28];
    s32 a;
    s32 b;
    s32 c;
} Basis;

typedef struct {
    s32 v;
} Fx;

/* 20.12 fixed point */
enum {
    FX_SHIFT = 12,
    FX_ROUND = 0x800,
    FX_ONE   = 0x1000
};

static inline s32 fxmul(s32 x, s32 y) {
    return (s32) (((s64) x * y + FX_ROUND) >> FX_SHIFT);
}

static inline void axis(Vec3 *out, s32 x, s32 y, s32 z) {
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline Fx *fx_abs(Fx *dst, Fx src) {
    if (src.v < 0) {
        dst->v = -src.v;
        return dst;
    }
    *dst = src;
    return dst;
}
static inline s32 absb(Fx b) {
    return b.v < 0 ? -b.v : b.v;
}
static inline int gt(const Fx *a, const Fx *b) {
    Fx r;
    s32 x = fx_abs(&r, *a)->v;
    return x > absb(*b);
}

/*
 * Writes to out the signed unit axis (+-FX_ONE on one component) along which
 * (v.x * b * c, v.y * a * c, v.z * a * b) has the largest magnitude, with
 * a, b, c read from m at +0x28/+0x2c/+0x30. Ties go to the later axis, and
 * a zero component gives the negative direction.
 */
void func_0204c180(Vec3 *out, Basis *m, Vec3 v) {
    struct {
        Fx x, y, z;
    } t;
    const Vec3 *pv = &v;
    t.x.v          = fxmul(pv->x, m->b);
    t.x.v          = fxmul(t.x.v, m->c);
    t.y.v          = fxmul(pv->y, m->a);
    t.y.v          = fxmul(t.y.v, m->c);
    t.z.v          = fxmul(pv->z, m->a);
    t.z.v          = fxmul(t.z.v, m->b);
    if (gt(&t.x, &t.y)) {
        if (gt(&t.x, &t.z)) {
            if (t.x.v > 0) {
                axis(out, FX_ONE, 0, 0);
                return;
            } else {
                axis(out, -FX_ONE, 0, 0);
                return;
            }
        }
        if (t.z.v > 0) {
            axis(out, 0, 0, FX_ONE);
            return;
        } else {
            axis(out, 0, 0, -FX_ONE);
            return;
        }
    } else {
        if (gt(&t.y, &t.z)) {
            if (t.y.v > 0) {
                axis(out, 0, FX_ONE, 0);
                return;
            } else {
                axis(out, 0, -FX_ONE, 0);
                return;
            }
        }
        if (t.z.v > 0) {
            axis(out, 0, 0, FX_ONE);
            return;
        } else {
            axis(out, 0, 0, -FX_ONE);
            return;
        }
    }
}
