#include "m2c.h"

void *func_020aaeb4();                              /* extern */

void func_02057754(s32 arg0, u8 *arg1) {
    s8 var_r4;

    if (*arg1 != 0) {
        var_r4 = 1;
    } else {
        var_r4 = 0;
    }
    M2C_FIELD(func_020aaeb4(), s8 *, 0x3D9) = var_r4;
}
