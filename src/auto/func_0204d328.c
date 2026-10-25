#include "m2c.h"

typedef struct {
    s32 pad0;
    s32 x;
    s32 y;
    s32 z;
    u8 pad10[0x20];
    s32 radius;
} Sphere;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Point;

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + 0x800) >> 12);
}

/* Point-in-sphere test: squared distance from the centre vs. squared radius. */
s32 func_0204d328(Sphere *sphere, Point *p) {
    s32 dx = p->x;
    s32 dy = p->y;
    s32 dz = p->z;
    s32 r  = sphere->radius;
    s32 t;

    dx -= sphere->x;
    dy -= sphere->y;
    dz -= sphere->z;
    dx = FxMul(dx, dx);
    dy = FxMul(dy, dy);
    dz = FxMul(dz, dz);
    r  = FxMul(r, r);
    t  = dx + dy;
    return t + dz <= r;
}
