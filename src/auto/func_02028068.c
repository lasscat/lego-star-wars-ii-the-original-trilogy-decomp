#include "m2c.h"

typedef struct {
    u8 pad0[0x40];
    u8 flag;
    u8 pad1[0x6f];
    s32 x;
    s32 y;
    s32 z;
} Obj;

extern void func_020293f8(s32 *, void *);

/* True when b is above a by more than a's range, the 3D distance is under 1.0 (hardware
 * sqrt) and b's flag byte is clear. */
s32 func_02028068(Obj *a, Obj *b) {
    s32 range;
    s32 limit;
    s32 *lp;
    s64 t;
    s32 r;

    r = a != 0; // FAKE: flag chain stands in for the && chain to match the original branch layout
    if (r) {
        r = b != 0;
    }
    if (r) {
        func_020293f8(&range, a);
        r = (b->y - a->y) > range;
    }
    if (r) {
        limit = 0x10000;
        lp    = &limit; // FAKE: address-taken limit keeps it in a stack slot reloaded after the sqrt wait
        t     = (s64) (a->z - b->z) * (a->z - b->z);
        t += (s64) (a->x - b->x) * (a->x - b->x) + (s64) (a->y - b->y) * (a->y - b->y);
        *(volatile u16 *) 0x040002B0 = 1;
        *(u64 *) 0x040002B8          = t << 2;
        while (*(volatile u16 *) 0x040002B0 & 0x8000) {
        }
        r = ((s32) * (volatile u32 *) 0x040002B4 + 1) >> 1 < *lp;
    }
    if (r) {
        r = b->flag == 0;
    }
    return r;
}
