#include "m2c.h"

M2C_UNK func_0205e6e0(s32, s32, s32);               /* extern */

void func_020ba6cc(void *arg0, s32 arg1, u32 arg2) {
    s32 var_r4;
    u32 temp_r2;
    u32 temp_r3;

    temp_r2 = M2C_FIELD(arg0, u32 *, 4);
    if (M2C_FIELD(arg0, u8 *, 0x2C) == 1) {
        var_r4 = 2;
    } else {
        var_r4 = 1;
    }
    if (temp_r2 == 0) {
        func_0205e6e0(arg1, (var_r4 * (M2C_FIELD(arg0, s32 *, 8) - arg2)) + M2C_FIELD(arg0, s32 *, 0), arg2 * var_r4);
        return;
    }
    if (temp_r2 < arg2) {
        func_0205e6e0(arg1, (var_r4 * ((M2C_FIELD(arg0, s32 *, 8) + temp_r2) - arg2)) + M2C_FIELD(arg0, s32 *, 0),
                      var_r4 * (arg2 - temp_r2));
        temp_r3 = M2C_FIELD(arg0, u32 *, 4);
        func_0205e6e0((var_r4 * (arg2 - temp_r3)) + arg1, M2C_FIELD(arg0, s32 *, 0), temp_r3 * var_r4);
        return;
    }
    func_0205e6e0(arg1, (var_r4 * (temp_r2 - arg2)) + M2C_FIELD(arg0, s32 *, 0), arg2 * var_r4);
}
