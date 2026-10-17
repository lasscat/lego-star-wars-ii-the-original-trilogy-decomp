#include "m2c.h"

M2C_UNK func_0206574c(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_02065be8(void *, s32, M2C_UNK, s32, s32, s32); /* extern */
s32 func_02066708(s32);                             /* extern */
extern void **data_021092f4;

void func_0209cadc(void *arg0) {
    s32 var_r8;
    u8 var_r9;

    var_r8 = 1;
    var_r9 = 0;
    do {
        if ((var_r9 == M2C_FIELD(arg0, u8 *, 0x8C)) && (M2C_FIELD(*data_021092f4, s32(**)(), 0x1C)(data_021092f4) == 0)) {
            func_0206574c(arg0 + 0x30, 3, -2);
        } else {
            func_0206574c(arg0 + 0x30, 0, -2);
        }
        var_r8 = func_02065be8(arg0 + 0x30, var_r8, 0x80, (var_r9 * 0x1C) + 0x3A, func_02066708(var_r9 + 0x2A5), 1);
        var_r9 += 1;
    } while ((u32) var_r9 < 4U);
}
