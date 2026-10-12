#include "m2c.h"

M2C_UNK func_020d27ec(M2C_UNK, M2C_UNK);            /* extern */
s32 func_020d60d4();                                /* extern */

void func_020d2d38(M2C_UNK arg0) {
    M2C_UNK var_r1;

    if (func_020d60d4() != 0) {
        var_r1 = 5;
    } else {
        var_r1 = 0;
    }
    func_020d27ec(arg0, var_r1);
}
