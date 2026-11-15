#include "m2c.h"

typedef volatile u64 vu64;
typedef volatile u32 vu32;
typedef volatile u16 vu16;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec;

extern Vec data_020ff9b4;

/* NDS hardware divider / square-root unit registers */
enum {
    REG_DIVCNT      = 0x04000280,
    REG_DIV_NUMER   = 0x04000290,
    REG_DIV_DENOM   = 0x04000298,
    REG_DIV_RESULT  = 0x040002A0,
    REG_SQRTCNT     = 0x040002B0,
    REG_SQRT_RESULT = 0x040002B4,
    REG_SQRT_PARAM  = 0x040002B8
};

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} PVec;

typedef struct {
    u8 pad0[4];
    PVec pos;
    u8 pad10[0x18];
    s32 radius;
} Shape;

static inline void vec_scale(Vec *d, const Vec *a, s32 s) {
    s32 z = (s32) (((s64) a->z * s + 0x800) >> 12);
    s32 y = (s32) (((s64) a->y * s + 0x800) >> 12);
    s32 x = (s32) (((s64) a->x * s + 0x800) >> 12);
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

static inline void vec_add(Vec *d, const Vec *a, const PVec *b) {
    s32 x, y, z;

    z    = a->z;
    z    = b->z + z;
    y    = a->y;
    y    = b->y + y;
    x    = a->x;
    x    = b->x + x;
    d->x = x;
    d->y = y;
    d->z = z;
}

/* Flattens dir onto the XZ plane, normalizes it (falls back to data_020ff9b4
   when zero), scales it by the fixed-point value at +0x28 and adds the
   vector at +4: out = pos + normalize(dir.x, 0, dir.z) * radius. */
void func_0204cf4c(Vec *out, Shape *base, Vec *dir) {
    s32 horiz;
    Vec v;
    Vec r;
    s64 t;
    s32 sqrt;
    s64 div;
    s32 scale;

    v.x   = dir->x;
    v.y   = dir->y;
    v.z   = dir->z;
    v.y   = 0;
    horiz = 1;
    if (v.x == 0 && v.z == 0) {
        horiz = 0;
    }

    if (horiz) {
        if ((v.x == 0) && (v.y == 0) && (v.z == 0)) {
            if (&v != &data_020ff9b4) {
                v.x = data_020ff9b4.x;
                v.y = data_020ff9b4.y;
                v.z = data_020ff9b4.z;
            }
        } else {
            t = (s64) v.x * v.x;
            t += (s64) v.y * v.y;
            t += (s64) v.z * v.z;

            (*(vu16 *) REG_DIVCNT)    = 2;
            (*(vu64 *) REG_DIV_NUMER) = 1LL << 56;
            (*(vu64 *) REG_DIV_DENOM) = t;

            (*(vu16 *) REG_SQRTCNT)   = 1;
            (*(u64 *) REG_SQRT_PARAM) = t << 2;

            while ((*(vu16 *) REG_SQRTCNT) & 0x8000) {
            }
            sqrt = (s32) (*(vu32 *) REG_SQRT_RESULT);

            while ((*(vu16 *) REG_DIVCNT) & 0x8000) {
            }
            div = (s64) (*(u64 *) REG_DIV_RESULT);

            div *= sqrt;

            v.x = (s32) ((div * v.x + (1LL << 44)) >> 45);
            v.y = (s32) ((div * v.y + (1LL << 44)) >> 45);
            v.z = (s32) ((div * v.z + (1LL << 44)) >> 45);
        }
    }

    scale = base->radius;
    vec_scale(&r, &v, scale);
    vec_add(out, &r, &base->pos);
}
