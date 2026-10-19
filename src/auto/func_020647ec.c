#include "m2c.h"
void func_020647ec(u8 *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x2E) != 0 && M2C_FIELD(arg0, u16 *, 0x30) == 0) {
        M2C_FIELD(arg0, u8 *, 0x54) = 1;
        M2C_FIELD(arg0, u8 *, 0x55) += 1;
        {
            u8 b                                                 = M2C_FIELD(arg0, u8 *, 0x55);
            M2C_FIELD((void *) 0x04000280, volatile u16 *, 0)    = 0;
            M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x10) = b;
        }
        M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x18) = 5;
        M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x1C) = 0;
        do {
        } while (M2C_FIELD((void *) 0x04000280, volatile u16 *, 0) & 0x8000);
        M2C_FIELD(arg0, u8 *, 0x55)                                   = *(volatile u32 *) 0x040002A8;
        M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x55) * 2, u8 *, 0x4A) = M2C_FIELD(arg0, u16 *, 0x2A);
        M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x55) * 2, u8 *, 0x4B) = M2C_FIELD(arg0, u16 *, 0x2C);
        return;
    }
    {
        M2C_FIELD(arg0, u8 *, 0x54) = 0;
        M2C_FIELD(arg0, u8 *, 0x55) += 1;
        {
            u8 b                                                 = M2C_FIELD(arg0, u8 *, 0x55);
            M2C_FIELD((void *) 0x04000280, volatile u16 *, 0)    = 0;
            M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x10) = b;
        }
        M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x18) = 5;
        M2C_FIELD((void *) 0x04000280, volatile u32 *, 0x1C) = 0;
        do {
        } while (M2C_FIELD((void *) 0x04000280, volatile u16 *, 0) & 0x8000);
        M2C_FIELD(arg0, u8 *, 0x55)                                   = *(volatile u32 *) 0x040002A8;
        M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x55) * 2, u8 *, 0x4A) = 0xFF;
        M2C_FIELD(arg0 + M2C_FIELD(arg0, u8 *, 0x55) * 2, u8 *, 0x4B) = 0xFF;
    }
}
