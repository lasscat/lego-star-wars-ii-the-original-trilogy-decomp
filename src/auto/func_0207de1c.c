#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02065be8(s32, s32, M2C_UNK, s32, s32, s32); /* extern */
s32 func_02066708(s32);                             /* extern */
s32 func_02086204(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_02104d90;

void func_0207de1c(void *arg0, s32 arg1) {
    s32 temp_r0;
    s32 var_r7;
    s32 var_r8;

    M2C_FIELD(arg0, s32 *, 0x2C) = 0x8C;
    var_r7                       = 0;
    var_r8                       = 0x45;
    do {
        if (((func_02086204(&data_02104d90, 0xA) == 0) || (var_r7 != 0)) &&
            (((u32) M2C_FIELD(arg0, u32 *, 0) < 0xFU) || (var_r7 != 0))) {
            temp_r0 = M2C_FIELD(arg0, s32 *, 8);
            if (var_r7 == arg1) {
                func_0206574c(temp_r0, 3, -2);
            } else {
                func_0206574c(temp_r0, 0, -2);
            }
            M2C_FIELD(arg0, s32 *, 0x2C) = func_02065be8(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x2C), 0x80, var_r8,
                                                         func_02066708(var_r7 + 0x14C), 1);
        }
        var_r7 += 1;
        var_r8 += 0x21;
    } while (var_r7 < 2);
}
