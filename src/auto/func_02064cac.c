#include "m2c.h"

M2C_UNK func_02064dec(M2C_UNK, u16, M2C_UNK);       /* extern */

void func_02064cac(M2C_UNK arg0, u32 arg1, s32 arg2, M2C_UNK arg3) {
    u32 var_r1;

    if (arg1 == 0) {
        return;
    }
    if (arg2 == 1) {
        var_r1 = arg1 >> 5;
    } else {
        var_r1 = arg1 >> 6;
    }
    func_02064dec(arg0, (u16) var_r1, arg3);
}
