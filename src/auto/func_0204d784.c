#include "m2c.h"

typedef struct {
    s32 pad0;
    s32 x;
    s32 y;
    s32 z;
    u8 pad10[0x18];
    s32 halfX;
    s32 halfY;
    s32 halfZ;
    u16 ang;
} Box;

typedef struct {
    s32 pad0;
    s32 x;
    s32 y;
    s32 z;
    u8 pad10[0x20];
    s32 radius;
} Sphere;

/* s16 {sin, cos} pairs indexed by (angle >> 4), read as [i * 2] and [i * 2 + 1]. */
extern const s16 data_020f88c4[];

static inline s32 fx_sin(u16 a) {
    return data_020f88c4[(a >> 4) * 2];
}

static inline s32 fx_cos(u16 a) {
    return data_020f88c4[(a >> 4) * 2 + 1];
}

enum {
    FX_SHIFT = 12,
    FX_HALF  = 0x800
};

static inline s32 fx_mul(s32 a, s32 b) {
    return ((s64) a * b + FX_HALF) >> FX_SHIFT;
}

static inline s32 Clamp(s32 v, s32 lim) {
    if (v < -lim) {
        return -lim;
    }
    if (v > lim) {
        return lim;
    }
    return v;
}

/*
 * Sphere vs Y-rotated box overlap test. The sphere centre offset is rotated
 * into box space by -box->ang (sin/cos table), each local axis is clamped to
 * the box half extents, and the squared distance from the centre to the
 * clamped point is compared with radius^2. Returns 1 on overlap, else 0.
 */
s32 func_0204d784(Box *box, Sphere *s) {
    int sn;
    int cs;
    int dx;
    int dz;
    int t;
    int u;
    int dy;
    int cx, cy, cz, r, d;

    sn = fx_sin(-box->ang);
    cs = fx_cos(-box->ang);
    dz = s->z;
    dx = s->x;
    dz -= box->z;
    dx -= box->x;
    dy = s->y - box->y;
    t  = dx;
    u  = fx_mul(dz, sn);
    dx = fx_mul(dx, cs);
    dx += u;
    u = fx_mul(t, sn);
    t = fx_mul(dz, cs);
    t -= u;
    cx = Clamp(dx, box->halfX);
    cy = Clamp(dy, box->halfY);
    cz = Clamp(t, box->halfZ);
    cx -= dx;
    cy -= dy;
    cz -= t;
    r = s->radius;
    d = fx_mul(cx, cx) + fx_mul(cy, cy);
    return d + fx_mul(cz, cz) <= fx_mul(r, r);
}
