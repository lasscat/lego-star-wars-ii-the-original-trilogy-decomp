#include "m2c.h"

M2C_UNK func_0205e778(u32, s32, s32);
s32 func_020cdf48(M2C_UNK);
s32 func_020cdf5c(M2C_UNK);
extern s32 data_020edc3c[];

void func_0205e464(void) {
    s32 temp_r5;
    s32 var_r6;
    u32 var_r7;
    s32 var_r1;
    s32 temp_r4;

    var_r6  = (func_020cdf5c(0) + 3) & ~3;
    temp_r5 = func_020cdf48(0);
    var_r1  = var_r6;
    var_r7  = 0;
    do {
        var_r6 += data_020edc3c[var_r7] & ~3;
        func_0205e778(var_r7, var_r1, var_r6);
        var_r7 += 1;
        var_r1 = var_r6;
    } while (var_r7 < 3U);
    func_0205e778(3U, var_r1, (temp_r5 & ~3) - 4);
    temp_r4 = func_020cdf5c(4);
    func_0205e778(4U, (temp_r4 + 3) & ~3, func_020cdf48(4) & ~3);
}
