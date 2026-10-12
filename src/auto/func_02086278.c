#include "m2c.h"

M2C_UNK func_02086458(M2C_UNK, s32);                /* extern */
extern u8 data_020eedac;

void func_02086278(M2C_UNK arg0) {
    s32 var_r4;
    u8 *var_r5;

    var_r5 = &data_020eedac;
    var_r4 = 0;
    do {
        if (*var_r5 != 6) {
            func_02086458(arg0, var_r4);
        }
        var_r4 += 1;
        var_r5 += 0x14;
    } while (var_r4 < 0x64);
}
