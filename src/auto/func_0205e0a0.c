#include "m2c.h"

M2C_UNK func_0205e144(void *, s32, s32);            /* extern */
s32 func_0205e818(s32, u8, M2C_UNK);                /* extern */
s32 func_020e4600(s32, s32, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK func_0205e130;

void func_0205e0a0(void *arg0) {
    s32 var_r0;
    u16 var_r5;

    var_r5 = M2C_FIELD(arg0, u16 *, 0x1C);
    if (var_r5 == 0) {
        var_r5 = (u16) M2C_FIELD(arg0, u8 *, 0x21);
    }
    var_r0 = func_0205e818(var_r5 * 0xC, M2C_FIELD(arg0, u8 *, 0x20), 4);
    if (var_r0 != 0) {
        var_r0 = func_020e4600(var_r0, var_r5, 0xC, 0, &func_0205e130, 0);
    }
    M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 0x22) * 4)), s32 *, 4) = var_r0;
    func_0205e144(arg0, M2C_FIELD(arg0, u8 *, 0x22), var_r5);
    M2C_FIELD(arg0, u16 *, 0x1C) = (u16) (M2C_FIELD(arg0, u16 *, 0x1C) + var_r5);
    M2C_FIELD(arg0, u8 *, 0x22)  = (u8) (M2C_FIELD(arg0, u8 *, 0x22) + 1);
}
