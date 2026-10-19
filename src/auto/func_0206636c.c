#include "m2c.h"

void func_0206636c(void *arg0, s32 *arg1, s32 arg2, u16 *arg3, s32 arg4, s32 arg5) {
    s32 temp_r5;
    s32 temp_r4;
    s32 var_r6;

    if (arg2-- == 0) {
        return;
    }
    do {
        temp_r5 = M2C_FIELD(arg0, s32 *, 0x28);
        temp_r4 = temp_r5 / 4;
        var_r6  = temp_r4 - 1;
        {
            s32 *var_r5 = (s32 *) ((arg5 * temp_r5) + arg4);
            if (temp_r4 != 0) {
                do {
                    *var_r5 = *arg1;
                    arg1 += 1;
                    var_r5 += 1;
                } while (var_r6--);
            }
        }
        if (M2C_FIELD(arg0, s32 *, 0x2C) == 1) {
            *arg3 = (u16) arg5;
        } else {
            if (M2C_FIELD(arg0, s32 *, 0x10) == -1) {
                *arg3 = (u16) (arg5 | (*arg3 & 0xF000));
            } else {
                *arg3 = (u16) (arg5 | M2C_FIELD(arg0, s32 *, 0x14));
            }
        }
        arg3 += M2C_FIELD(arg0, s32 *, 0x24);
        arg5 += 1;
    } while (arg2--);
}
