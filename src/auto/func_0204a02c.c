#include "m2c.h"

M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_020aa8f0(s32, s32, M2C_UNK, s32, s32, s32);/* extern */
s32 func_020aaeb4();                                /* extern */
extern M2C_UNK data_021027f8;

void *func_0204a02c(void *arg0, void *arg1, s32 arg2) {
    s32 var_r0;
    void *var_r2;

    M2C_FIELD(arg0, s32 *, 0) = arg2;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    var_r2                    = arg0 + 8;
    do {
        M2C_FIELD(var_r2, s32 *, 4) = 0;
        var_r2 += 0xC;
    } while ((u32) var_r2 < (u32) (arg0 + 0x68));
    M2C_FIELD(arg0, s8 *, 0x68) = 0;
    func_0205e624(arg0 + 8, 0, 0x60);
    if (M2C_FIELD(arg1, u8 *, 0x5DA) != M2C_FIELD(&data_021027f8, u8 *, 0x2A)) {
        var_r0 = 0;
    } else {
        var_r0 = func_020aa8f0(func_020aaeb4(), arg2 + 0xB0, 1, 0, 0xFF, 0);
    }
    M2C_FIELD(arg0, s32 *, 4) = var_r0;
    return arg0;
}
