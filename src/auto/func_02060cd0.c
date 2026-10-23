#include "m2c.h"

extern M2C_UNK data_021041c1;
M2C_UNK func_02060e6c(void *);                     /* extern */

void func_02060cd0(void *arg0, u32 arg1, u32 arg2) {
    u8 *p;
    u32 v;

    if (arg1 == 0xFF) {
        return;
    }
    if ((M2C_FIELD(arg0, u32 *, 0x8) & 0x80000) == 0x80000) {
        func_02060e6c(arg0);
    }
    p                            = (u8 *) &data_021041c1 + arg2 * 0x84;
    v                            = M2C_FIELD(arg0, u32 *, 0x14);
    M2C_FIELD(arg0, u32 *, 0x14) = (v & ~0xF000u) | ((u16) (arg1 << 12));
    p[arg1 * 8]++;
    v                           = M2C_FIELD(arg0, u32 *, 0x8);
    M2C_FIELD(arg0, u32 *, 0x8) = v | 0x80000;
}
