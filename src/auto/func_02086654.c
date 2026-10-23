#include "m2c.h"

typedef struct {
    u8 pad[0x4400];
    u32 bits[0x1100];
} Inner;

typedef struct {
    u8 kind;
    u8 pad;
    s16 id;
} T1;

typedef struct {
    u8 pad[0x20];
    u16 kind;
    u16 id;
} T2;

typedef struct {
    u8 pad[0x114];
    Inner f;
} Obj;

extern T1 data_020f4910[];
extern T2 data_020f6ba8[];

extern void func_020865ac(Obj *, u16);
extern void func_02086600(Obj *, u16);

void func_02086654(Obj *self, s32 arg1) {
    u16 i;
    u32 idx;
    u32 *p;
    u32 *bits;
    u32 bit;
    u32 msk;

    p    = (u32 *) ((u8 *) self + 0x114);
    bit  = arg1 & 0x1f;
    msk  = 1 << bit;
    idx  = arg1 >> 5;
    bits = (u32 *) ((u8 *) p + 0x4400);
    bits[idx] &= ~msk;
    bits[idx] |= msk;

    for (i = 0; i < 250; i++) {
        if (data_020f4910[i].kind == 3 && data_020f4910[i].id == arg1) {
            func_020865ac(self, i);
        }
    }
    for (i = 0; i < 40; i++) {
        if (data_020f6ba8[i].kind == 3 && data_020f6ba8[i].id == arg1) {
            func_02086600(self, i);
        }
    }
}
