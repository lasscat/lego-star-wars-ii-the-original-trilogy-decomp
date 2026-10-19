#include "m2c.h"

M2C_UNK func_020aa91c(s32, s32 *, M2C_UNK, u8, u8, u8); /* extern */
s32 func_020aaeb4();                                /* extern */

s32 func_020516f0(void *arg0, u8 arg1, u8 arg2) {
    s32 a;
    s32 b;
    s32 c;
    s32 sp8[3];

    c      = M2C_FIELD(arg0, s16 *, 4) << 0xC;
    b      = M2C_FIELD(arg0, s16 *, 2) << 0xC;
    a      = M2C_FIELD(arg0, s16 *, 0) << 0xC;
    sp8[0] = a;
    sp8[1] = b;
    sp8[2] = c;
    if (M2C_FIELD(arg0, u8 *, 9) != 0) {
        func_020aa91c(func_020aaeb4(), sp8, 3, M2C_FIELD(arg0, u8 *, 8), (s32) arg1, (s32) arg2);
    } else {
        func_020aa91c(func_020aaeb4(), sp8, 2, M2C_FIELD(arg0, u8 *, 8), (s32) arg1, (s32) arg2);
    }
    return 0;
}
