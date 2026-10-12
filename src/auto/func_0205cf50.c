#include "m2c.h"

M2C_UNK func_02059e4c(s32);                         /* extern */

void func_0205cf50(s32 arg0) {
    s32 var_r4;
    s32 var_r5;

    var_r5 = arg0;
    var_r4 = 0;
    do {
        func_02059e4c(var_r5);
        var_r4 += 1;
        var_r5 += 0xA;
    } while (var_r4 < 4);
}
