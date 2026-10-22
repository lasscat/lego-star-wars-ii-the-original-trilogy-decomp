#include "m2c.h"

typedef struct {
    s32 f0;
} Reg0;

typedef struct {
    u32 f00;
    u8 pad04[0x34];
    u32 f38;
    u8 pad3c[0x58];
    u32 f94;
    u32 f98;
    u8 pad9c[0xb8];
    u32 f154;
} HwRegs;

extern Reg0 data_02102900;

extern void func_01ffa6f8(s32, s32);
extern void G3_MultMtx43(s32);

void func_020104d0(s32 a0) {
    s32 *p;
    s32 v;
    s32 m;
    s32 v1;
    s32 v2;
    s32 v3;
    volatile Reg0 *r0;
    volatile HwRegs *hw;

    p = data_02102900.f0;
    v = p ? *(s32 *) ((u8 *) p + 4) : 0;
    if (v != 4) {
        return;
    }
    if ((M2C_FIELD(a0, u16 *, 0xc) & 0x7e) == 0) {
        return;
    }

    M2C_FIELD(a0, u16 *, 0x1a8) &= ~0xc;
    r0     = (volatile Reg0 *) 0x4000444;
    r0->f0 = 0;

    if (M2C_FIELD(a0, u8 *, 0xd0) != 0) {
        M2C_FIELD(a0, u8 *, 0xd1) = 1;
        M2C_FIELD(a0, u8 *, 0xd0) = 0;
        func_01ffa6f8(a0 + 0x8c, a0 + 0xc8);
    }
    G3_MultMtx43(a0 + 0x8c);

    hw                          = (volatile HwRegs *) 0x400046c;
    m                           = M2C_FIELD(a0, s32 *, 0x1a4);
    v1                          = (s32) (((s64) m * M2C_FIELD(a0, s32 *, 0xc4) + 0x800) >> 12);
    v2                          = (s32) (((s64) m * M2C_FIELD(a0, s32 *, 0xc0) + 0x800) >> 12);
    v3                          = (s32) (((s64) m * M2C_FIELD(a0, s32 *, 0xbc) + 0x800) >> 12);
    hw->f00                     = v3;
    hw->f00                     = v2;
    hw->f00                     = v1;
    hw->f38                     = 0x30c1;
    hw->f94                     = 0;
    hw->f98                     = 0;
    hw->f154                    = M2C_FIELD(a0, s32 *, 0x198);
    hw->f154                    = M2C_FIELD(a0, s32 *, 0x19c);
    hw->f154                    = M2C_FIELD(a0, s32 *, 0x1a0);
    *(volatile u32 *) 0x4000448 = 1;

    M2C_FIELD(a0, u16 *, 0x1a8) |= 4;
}
