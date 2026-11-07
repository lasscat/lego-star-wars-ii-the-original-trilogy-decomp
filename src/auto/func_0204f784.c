#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    int z;
} Vec3;

typedef struct {
    s32 d;
    Vec3 n;
} Plane;

extern s32 FX_Div(s32, s32);

static inline s32 FX_MUL(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

void func_0204f784(s32 *out, const Vec3 *p, const Plane *pl) {
    s32 x  = p->x;
    s32 nz = pl->n.z;
    s32 t;
    s32 nx = pl->n.x;
    s32 ny = pl->n.y;
    int z;
    ny   = -ny;
    z    = FX_MUL(nz, p->z);
    t    = FX_MUL(nx, x);
    nz   = t + z;
    z    = nz + pl->d;
    *out = FX_Div(z, ny);
}
