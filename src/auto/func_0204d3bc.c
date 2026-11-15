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

typedef struct {
    s32 pad0;
    s32 x;
    s32 y;
    s32 z;
    u8 pad10[0x18];
    s32 halfHeight;
    s32 radius;
} Cylinder;

extern s32 FX_Div(s32, s32);
extern s32 FX_Sqrt(s32);
extern s32 func_0204d328(Sphere *sphere, Point *p);

enum {
    FX_SHIFT = 12,
    FX_HALF  = 0x800,
    PRESHIFT = 6
};

static inline s32 FxMul(s32 x, s32 y) {
    return (s32) (((s64) x * y + FX_HALF) >> FX_SHIFT);
}

/* Square of v >> PRESHIFT (the XZ distances are squared at the same scale). */
static inline s32 SqShift(s32 v) {
    v >>= PRESHIFT;
    return FxMul(v, v);
}

/* Sphere vs. upright cylinder overlap test (called from func_01ff84bc).
   d2 = squared XZ distance of the centres, each component shifted right by PRESHIFT first.
   Sphere centre above the top cap (cy + halfHeight) or below the bottom cap (cy - halfHeight):
   if d2 is within the cylinder radius, the vertical gap is compared with the sphere radius
   (the lower cap compares bottom - cy, as the target does); otherwise the cap rim point at
   radius along (cx - sx, cz - sz) from the axis is tested with func_0204d328.
   Between the caps: d2 against the square of the radius sum. */

s32 func_0204d3bc(Sphere *sphere, Cylinder *cyl) {
    s32 cy, h, top, bottom, y;
    s32 d2;
    s32 sz, cx, sx, cz;
    s32 dx, dz;
    Point p;
    Point q;

    sz     = sphere->z;
    cz     = cyl->z;
    sx     = sphere->x;
    cx     = cyl->x;
    cy     = cyl->y;
    h      = cyl->halfHeight;
    y      = sphere->y;
    top    = cy + h;
    bottom = cy - h;
    dz     = sz;
    dx     = sx;
    dz -= cz;
    dx -= cx;
    dz >>= PRESHIFT;
    dx >>= PRESHIFT;
    d2 = FxMul(dx, dx) + FxMul(dz, dz);

    if (y > top) {
        s32 r = cyl->radius;
        if (d2 <= SqShift(r)) {
            return y - top <= sphere->radius;
        }
        {
            s32 ex = cx - sx;
            s32 ez = cz - sz;
            s32 s  = FX_Sqrt(FX_Div(FxMul(r, r), FxMul(ex, ex) + FxMul(ez, ez)));
            p.x    = cx + FxMul(s, ex);
            p.y    = top;
            p.z    = cz + FxMul(s, ez);
            return func_0204d328(sphere, &p);
        }
    }
    if (y < bottom) {
        s32 r = cyl->radius;
        if (d2 <= SqShift(r)) {
            return bottom - cy <= sphere->radius;
        }
        {
            s32 ex = cx - sx;
            s32 ez = cz - sz;
            s32 s  = FX_Sqrt(FX_Div(FxMul(r, r), FxMul(ex, ex) + FxMul(ez, ez)));
            q.x    = cx + FxMul(s, ex);
            q.y    = bottom;
            q.z    = cz + FxMul(s, ez);
            return func_0204d328(sphere, &q);
        }
    }
    {
        return d2 <= SqShift(sphere->radius + cyl->radius);
    }
}
