#include "m2c.h"

/* 20.12 fixed point; FX_HALF is added before the shift to round. */
enum {
    FX_FRAC_BITS = 12,
    FX_HALF      = 0x800
};

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3;

typedef struct {
    s32 d;
    V3 n;
} Plane;

/* Two coordinates per axis (x, y, z); func_0204c74c offsets each pair by one position component. */
typedef struct {
    s32 v[3][2];
} Box;

extern s32 data_020fe498;
extern s32 FX_Div(s32, s32);

/* Vertical offset that puts one corner of the box on the plane n.p + (d - data_020fe498) = 0.
 * Each corner coordinate is the second of its axis pair when the negated normal component is >= 0.
 * A plane with n.y == 0 has no height, so the result is 0. */
void func_0204e5a0(s32 *out, Box *box, Plane *plane) {
    V3 *n = &plane->n;
    s32 dist;
    s32 dx;
    s32 ny;
    s32 pz;
    s32 den;
    s32 dy;
    s32 dz;
    s32 cx;
    s32 cy;
    s32 cz;
    s32 px;

    dist = plane->d - data_020fe498;
    ny   = plane->n.y;
    if (ny == 0) {
        *out = 0;
        return;
    }

    dx  = -n->x;
    dz  = -n->z;
    dy  = -n->y;
    cy  = box->v[1][dy >= 0 ? 1 : 0];
    den = -ny;
    cz  = box->v[2][dz >= 0 ? 1 : 0];
    pz  = (s32) (((s64) cz * plane->n.z + FX_HALF) >> FX_FRAC_BITS);
    cx  = box->v[0][dx >= 0 ? 1 : 0];
    px  = (s32) (((s64) cx * plane->n.x + FX_HALF) >> FX_FRAC_BITS);
    px += pz;
    /* plane height at (cx, cz) minus the corner's own y */
    *out = FX_Div(px + dist, den) - cy;
}
