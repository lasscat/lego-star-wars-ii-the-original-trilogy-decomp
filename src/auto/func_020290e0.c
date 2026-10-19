#include "m2c.h"

M2C_UNK func_02029068(u16 *, M2C_UNK, s32);         /* extern */

void func_020290e0(u16 *arg0, M2C_UNK arg1, s32 arg2) {
    u16 sp2;
    u16 sp0;
    u16 *var_r1;

    if (arg2 != 0) {
        func_02029068(&sp2, arg1, arg2 + 0xB0);
        var_r1 = &sp2;
    } else {
        sp0    = 0;
        var_r1 = &sp0;
    }
    *arg0 = *var_r1;
}
