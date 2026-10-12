#include "m2c.h"

M2C_UNK func_02065188(M2C_UNK, M2C_UNK, s32);       /* extern */
extern s32 data_027e02a4;
extern s32 data_027e02a8;

s32 func_020ab900(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 var_r4;

    var_r4 = 0;
    if (data_027e02a8 & (4 << data_027e02a4)) {
        data_027e02a8 |= 0x80;
        var_r4 = 1;
    }
    func_02065188(arg2, arg1, var_r4);
    data_027e02a8 &= ~0x80;
    return var_r4;
}
