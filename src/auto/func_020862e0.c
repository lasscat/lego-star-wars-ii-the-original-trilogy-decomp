#include "m2c.h"

M2C_UNK func_02086600(M2C_UNK, s32);                /* extern */

void func_020862e0(M2C_UNK arg0) {
    s32 var_r4;

    var_r4 = 0;
    do {
        func_02086600(arg0, var_r4);
        var_r4 += 1;
    } while (var_r4 < 0x28);
}
