#include "m2c.h"

extern void func_02007f24(s32 *a0, s32 a1, s32 a2);
extern s32 func_0200aef8(void *a, void *b, s32 r);
extern s32 func_020964c8(void *a, void *b);

enum {
    SHAPE_FLAT_RADIUS  = 1,
    SHAPE_CYLINDER     = 2,
    HALF_SCALE_HI_WORD = 0x3FE00000,
};

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V;

typedef struct {
    u8 pad0[4];
    V c;
    s32 r10;
    s32 r14;
    u8 pad18[7];
    u8 f1f;
    u8 pad20[12];
    u8 kind;
} A;

/*
 * Point-in-volume test of point p against shape a (shape type in a->kind).
 * Kind 1: only the XZ-plane distance check against radius r14 (y zeroed on both points).
 * Kind 2: XZ-plane distance check against radius r10, then p->y must lie within the
 *         centre y +/- r14 * 0.5 (func_02007f24 yields 0.5 in 20.12 fixed point scaling).
 * Other kinds are delegated to func_020964c8 (box test). Returns 1 when p is inside.
 * f1f != 0 adds an early accept on the XZ test (meaning of f1f not proved).
 */
s32 func_020972e0(A *a, V *p) {
    V flat_p1;
    V flat_c1;
    V flat_p2;
    V flat_c2;
    s32 half0;
    s32 half1;
    s32 v;
    s32 limit;
    volatile A *vol_a =
        a; // FAKE: volatile view fixes load order/colouring of r14 and centre-y reads (as in neighbour func_020964c8)

    if (a->kind == SHAPE_FLAT_RADIUS) {
        flat_p1.x = p->x;
        flat_p1.y = p->y;
        flat_p1.z = p->z;
        flat_p1.y = 0;
        flat_c1.x = a->c.x;
        flat_c1.y = a->c.y;
        flat_c1.z = a->c.z;
        flat_c1.y = 0;
        if ((a->f1f != 0 && func_0200aef8(&flat_c1, &flat_p1, a->r14) != 0) || func_0200aef8(&a->c, p, a->r14) != 0) {
            return 1;
        }
        return 0;
    }
    if (a->kind == SHAPE_CYLINDER) {
        flat_p2.x = p->x;
        flat_p2.y = p->y;
        flat_p2.z = p->z;
        flat_p2.y = 0;
        flat_c2.x = a->c.x;
        flat_c2.y = a->c.y;
        flat_c2.z = a->c.z;
        flat_c2.y = 0;
        if (a->f1f != 0 && func_0200aef8(&flat_c2, &flat_p2, a->r10) != 0) {
            goto hit;
        }
        if (func_0200aef8(&flat_c2, &flat_p2, a->r10) == 0) {
            goto miss;
        }
        func_02007f24(&half0, 0, HALF_SCALE_HI_WORD);
        v     = (s32) (((s64) vol_a->r14 * half0 + 0x800) >> 12);
        limit = vol_a->c.y - v;
        if (p->y < limit) {
            goto miss;
        }
        func_02007f24(&half1, 0, HALF_SCALE_HI_WORD);
        v     = (s32) (((s64) vol_a->r14 * half1 + 0x800) >> 12);
        limit = vol_a->c.y + v;
        if (p->y > limit) {
            goto miss;
        }
    hit:
        return 1;
    miss:
        return 0;
    }
    return func_020964c8(a, p);
}
