#include "m2c.h"

s32 func_0205e540(s32, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_0205e5b0(s32);                         /* extern */
M2C_UNK func_0205e6e0(s32, s32, s32);               /* extern */
M2C_UNK func_020cbf9c();                            /* extern */
M2C_UNK func_020cc03c(s32, s32, s32);               /* extern */
M2C_UNK func_020cc0ac();                            /* extern */
M2C_UNK func_020cc0f4();                            /* extern */
M2C_UNK func_020cc13c(s32, s32, s32);               /* extern */
M2C_UNK func_020cc1a8();                            /* extern */
M2C_UNK func_020cc1ec();                            /* extern */
M2C_UNK func_020cc204(s32, s32, s32);               /* extern */
M2C_UNK func_020cc268();                            /* extern */
M2C_UNK func_020cc2a8();                            /* extern */
M2C_UNK func_020cc2c0(s32, s32, s32);               /* extern */
M2C_UNK func_020cc324();                            /* extern */
M2C_UNK func_020cdd40(s32, s32);                    /* extern */

void func_02055d58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 var_r5;
    s32 var_r9;

    var_r9 = arg0;
    var_r5 = 0;
    if (var_r9 & 3) {
        temp_r4 = arg3 * 2;
        temp_r0 = func_0205e540(temp_r4, 3, 4);
        var_r5 = temp_r0;
        func_0205e6e0(temp_r0, var_r9, temp_r4);
        var_r9 = var_r5;
    }
    temp_r4_2 = arg3 * 2;
    func_020cdd40(var_r9, temp_r4_2);
    if (arg5 == 0) {
        if (arg4 == 0) {
            func_020cbf9c();
            func_020cc03c(var_r9, (arg2 + (arg1 << 0xC)) * 2, temp_r4_2);
            func_020cc0ac();
        } else if (arg4 == 1) {
            func_020cc0f4();
            func_020cc13c(var_r9, (arg2 + (arg1 << 0xC)) * 2, temp_r4_2);
            func_020cc1a8();
        }
    } else if (arg4 == 0) {
        func_020cc1ec();
        func_020cc204(var_r9, (arg2 + (arg1 << 0xC)) * 2, temp_r4_2);
        func_020cc268();
    } else if (arg4 == 1) {
        func_020cc2a8();
        func_020cc2c0(var_r9, (arg2 + (arg1 << 0xC)) * 2, temp_r4_2);
        func_020cc324();
    }
    if (var_r5 == 0) {
        return;
    }
    func_0205e5b0(var_r5);
}
