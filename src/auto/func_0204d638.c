#include "m2c.h"

typedef struct {
    s32 pad0;
    s32 x;
    s32 y;
    s32 z;
    u8 pad10[0x18];
    s32 halfHeight;
    s32 radius;
} Shape;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Point;

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + 0x800) >> 12);
}

/* Point-in-cylinder test: vertical extent first, then XZ distance vs. radius. */
s32 func_0204d638(Shape *a, Point *p) {
    s32 h    = a->halfHeight;
    s32 aMax = a->y;
    s32 aMin = aMax;
    s32 dx;
    s32 dz;
    s32 rr;

    aMax += h;
    aMin -= h;
    if (aMax < p->y) {
        return 0;
    }
    if (aMin > p->y) {
        return 0;
    }

    dx = p->x;
    rr = a->radius;
    dz = p->z;
    dx -= a->x;
    dz -= a->z;
    dx = FxMul(dx, dx);
    dz = FxMul(dz, dz);
    rr = FxMul(rr, rr);
    if (dx + dz <= rr) {
        return 1;
    }
    return 0;
}
