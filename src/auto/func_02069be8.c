#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02065be8(s32, s32, s32, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_020661b4(s32, s32);                    /* extern */
s32 func_02066708(M2C_UNK);                         /* extern */

void func_02069be8(void *arg0, s32 arg1) {
    s32 var_r6;
    s32 var_r7;
    s32 var_r8;

    var_r6 = 0xC8;
    var_r7 = 0;
    var_r8 = 0x2B;
    do {
        if (var_r7 == arg1) {
            func_0206574c(M2C_FIELD(arg0, s32 *, 0x18), 3, -2);
        } else {
            func_0206574c(M2C_FIELD(arg0, s32 *, 0x18), 0, -2);
        }
        func_020661b4(M2C_FIELD(arg0, s32 *, 0x18), var_r7 + 1);
        if (var_r7 < 3) {
            var_r6 = func_02065be8(M2C_FIELD(arg0, s32 *, 0x18), var_r6, var_r8, 0x50, func_02066708(0x26), 1);
        } else {
            var_r6 = func_02065be8(M2C_FIELD(arg0, s32 *, 0x18), var_r6, 0x80, 0x90, func_02066708(0x58), 1);
        }
        var_r8 += 0x56;
        var_r7 += 1;
    } while (var_r7 < 4);
}
