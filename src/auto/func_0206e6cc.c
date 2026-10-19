#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02065be8(s32, s32, M2C_UNK, s32, s32, s32); /* extern */
s32 func_02066708(s32);                             /* extern */

void func_0206e6cc(void *arg0, s32 arg1) {
    s32 temp_r0;
    u32 var_r7;
    s32 var_r8;

    M2C_FIELD(arg0, s32 *, 0x20) = 0xF0;
    var_r7                       = 0;
    var_r8                       = 0x48;
    do {
        temp_r0 = M2C_FIELD(arg0, s32 *, 0xC);
        if (var_r7 == arg1) {
            func_0206574c(temp_r0, 3, -2);
        } else {
            func_0206574c(temp_r0, 0, -2);
        }
        if ((var_r7 == 0) && (M2C_FIELD(arg0, u8 *, 0x24) == 0)) {
            M2C_FIELD(arg0, s32 *, 0x20) =
                func_02065be8(M2C_FIELD(arg0, s32 *, 0xC), M2C_FIELD(arg0, s32 *, 0x20), 0x80, 0x48, func_02066708(0x37), 1);
        } else {
            if (M2C_FIELD(arg0, u8 *, 0x24) == 0) {
                func_0206574c(M2C_FIELD(arg0, s32 *, 0xC), 0xC, -2);
            }
            M2C_FIELD(arg0, s32 *, 0x20) = func_02065be8(M2C_FIELD(arg0, s32 *, 0xC), M2C_FIELD(arg0, s32 *, 0x20), 0x80,
                                                         var_r8, func_02066708(var_r7 + 0x38), 1);
        }
        var_r8 += 0x20;
        var_r7 += 1;
    } while (var_r7 < 2U);
}
