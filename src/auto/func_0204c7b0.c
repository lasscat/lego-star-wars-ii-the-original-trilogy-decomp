#include "m2c.h"

void func_0204cb34(s32 *a0, s32 *a1, s32 a2, s32 a3, ...);

typedef struct {
    s32 x, y, z;
} V3;

#define SRC1 (*(volatile s32 *) ((s8 *) src + 4))

void func_0204c7b0(s32 *dest, s32 *src) {
    V3 z;
    V3 b;
    V3 a;
    volatile V3 X;
    V3 *p;
    s32 val;
    s32 idx;
    s32 v0;

    if (src[1] >= 0x40000000) {
        val = (((((u32) (SRC1 << 29)) >> 31) != 0) ? 1 : -1) << 12;
        z.x = 0;
        z.y = 0;
        z.z = 0;
        idx = ((u32) (SRC1 << 30)) >> 30;
        X.y = val;
        func_0204cb34((s32 *) &b, (s32 *) &z, idx, val);
        p = &b;
    } else {
        a.x = M2C_FIELD(src, s16 *, 4);
        a.y = M2C_FIELD(src, s16 *, 6);
        a.z = M2C_FIELD(src, s16 *, 8);
        p   = &a;
    }
    v0      = src[0];
    dest[0] = v0;
    X.z     = v0;
    dest[1] = p->x;
    X.x     = v0;
    dest[2] = p->y;
    dest[3] = p->z;
}
