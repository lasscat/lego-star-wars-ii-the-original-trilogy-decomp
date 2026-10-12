#include "m2c.h"

M2C_UNK func_0202c1a8(s32, s32);                    /* extern */
s32 func_02038af0(s32, s32, s32, u8);               /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */

void func_02058fd0(M2C_UNK arg0, void *arg1) {
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r1;

    temp_r5 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    temp_r4 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 2), M2C_FIELD(arg1, u8 *, 3));
    if ((temp_r5 != 0) && (temp_r4 != 0)) {
        temp_r0 = func_0205e80c(0x70, 1, 4);
        var_r1 = temp_r0;
        if (var_r1 != 0) {
            var_r1 = func_02038af0(temp_r0, temp_r5, temp_r4, M2C_FIELD(arg1, u8 *, 4));
        }
        func_0202c1a8(temp_r5 + 0x5E0, var_r1);
    }
}
