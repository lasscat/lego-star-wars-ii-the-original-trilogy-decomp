#include "m2c.h"

M2C_UNK func_0209ce9c(M2C_UNK, u8);                 /* extern */
extern M2C_UNK data_0210930c;

void func_0209ce58(M2C_UNK arg0) {
    u8 var_r5;

    var_r5 = 0;
    do {
        if (M2C_FIELD(((M2C_UNK *)((s8 *)&data_0210930c + (var_r5 * 4))), s32 *, 0x4C) != 0) {
            func_0209ce9c(arg0, var_r5);
        }
        var_r5 += 1;
    } while ((u32) var_r5 < 4U);
}
