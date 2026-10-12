#include "m2c.h"

void func_0205401c(void *arg0, s32 arg1) {
    if (arg1 < 0) {
        M2C_FIELD(arg0, s16 *, 0xC) = (s16) (0 - arg1);
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) ((M2C_FIELD(arg0, u16 *, 0xA) & ~0xC0) | 0xC0);
    } else if (arg1 > 0) {
        M2C_FIELD(arg0, s16 *, 0xC) = (s16) arg1;
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) ((M2C_FIELD(arg0, u16 *, 0xA) & ~0xC0) | 0x80);
    } else {
        M2C_FIELD(arg0, s16 *, 0xC) = 0;
        M2C_FIELD(arg0, u16 *, 0xA) = (u16) (M2C_FIELD(arg0, u16 *, 0xA) & ~0xC0);
    }
    M2C_FIELD(arg0, u8 *, 0x1C) = (u8) (M2C_FIELD(arg0, u8 *, 0x1C) | 4);
}
