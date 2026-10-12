#include "m2c.h"

M2C_UNK func_02067ca0(void *, u8, M2C_UNK, u8, s32); /* extern */

s32 func_0206cf9c(void *arg0, s32 arg1) {
    s32 var_r4;

    var_r4 = 0;
    M2C_FIELD(arg0, s32 *, 0x78) = (s32) (M2C_FIELD(arg0, s32 *, 0x78) + arg1);
    M2C_FIELD(arg0, s32 *, 0x7C) = (s32) (M2C_FIELD(arg0, s32 *, 0x7C) - arg1);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x78) >= 0x80) {
        M2C_FIELD(arg0, s32 *, 0x78) = 0x80;
        M2C_FIELD(arg0, s32 *, 0x7C) = 0x80;
        var_r4 = 1;
    }
    func_02067ca0(arg0 + 0x4C, (u8) M2C_FIELD(arg0, s32 *, 0x78), 0, (u8) M2C_FIELD(arg0, s32 *, 0x7C), 0xFF);
    return var_r4;
}
