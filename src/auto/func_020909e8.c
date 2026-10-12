#include "m2c.h"

M2C_UNK func_02090228();                            /* extern */

void func_020909e8(void *arg0, s32 arg1, s32 arg2) {
    s32 var_r1;

    if (arg2 != 0) {
        var_r1 = M2C_FIELD(arg0, s32 *, 0x3CC) | (1 << arg1);
    } else {
        var_r1 = M2C_FIELD(arg0, s32 *, 0x3CC) & ~(1 << arg1);
    }
    M2C_FIELD(arg0, s32 *, 0x3CC) = var_r1;
    func_02090228();
}
