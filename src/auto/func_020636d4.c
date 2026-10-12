#include "m2c.h"

M2C_UNK func_020636fc(M2C_UNK, s32);                /* extern */

void func_020636d4(M2C_UNK arg0) {
    s32 var_r4;

    var_r4 = 0;
    do {
        func_020636fc(arg0, var_r4);
        var_r4 += 1;
    } while (var_r4 < 5);
}
