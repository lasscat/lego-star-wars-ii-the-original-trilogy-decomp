#include "m2c.h"
s32 func_020e48dc(M2C_UNK, s32, M2C_UNK *);
s32 func_020e4104(M2C_UNK arg0, void *arg1) {
    M2C_UNK buf[2];
    s32 v;
    u8 *p;
    u32 i;
    p = M2C_FIELD(arg1, u8 **, 0xC);
    for (i = 0; i < (u32) M2C_FIELD(arg1, u32 *, 0); i++) {
        v = M2C_FIELD(p, u8 *, 0) | (M2C_FIELD(p, u8 *, 1) << 8) | (M2C_FIELD(p, u8 *, 2) << 0x10) |
            (M2C_FIELD(p, u8 *, 3) << 0x18);
        buf[1] = v;
        if (func_020e48dc(arg0, v, buf) != 0) {
            return 1;
        }
        p += 4;
    }
    return 0;
}
