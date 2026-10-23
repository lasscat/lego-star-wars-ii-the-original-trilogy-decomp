#include "m2c.h"

typedef struct {
    s32 f00;
    s32 f04;
    s32 f08;
    u8 pad0[8];
    u8 f14[0x40];
    s32 f54;
    s32 f58;
    s32 f5c;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6c;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7c;
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8c;
    s32 f90;
    u8 pad[0xcc];
    u32 f160;
} Obj;

void MI_Copy64B(M2C_UNK, M2C_UNK);
M2C_UNK func_020c8bd0(M2C_UNK, M2C_UNK);

void func_020ace50(Obj *a) {
    s32 n8;
    s32 n4;
    s32 n0;
    if ((a->f160 << 28) >> 31) {
        MI_Copy64B((M2C_UNK *) &a->f14, (M2C_UNK *) &a->f54);
        func_020c8bd0((M2C_UNK *) &a->f54, (M2C_UNK *) &a->f54);
        n8 = -*(volatile s32 *) ((s8 *) a + 8);
        n4 = -a->f04;
        n0 = -a->f00;
        a->f84 += (s32) ((u64) (((s64) n0 * a->f54) + ((s64) n4 * a->f64) + ((s64) n8 * a->f74)) >> 12);
        a->f88 += (s32) ((u64) (((s64) n0 * a->f58) + ((s64) n4 * a->f68) + ((s64) n8 * a->f78)) >> 12);
        a->f8c += (s32) ((u64) (((s64) n0 * a->f5c) + ((s64) n4 * a->f6c) + ((s64) n8 * a->f7c)) >> 12);
        a->f90 += (s32) ((u64) (((s64) n0 * a->f60) + ((s64) n4 * a->f70) + ((s64) n8 * a->f80)) >> 12);
        a->f160 &= ~8;
    }
}
