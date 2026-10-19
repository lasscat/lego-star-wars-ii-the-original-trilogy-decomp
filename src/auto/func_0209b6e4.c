#include "m2c.h"

M2C_UNK func_0205e624(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_0205e84c(s32);                         /* extern */
M2C_UNK func_0209ce44(s32);                         /* extern */

s32 func_0209b6e4(void *arg0) {
    s32 sp[3];
    s32 temp_r5;
    u8 var_r2;

    M2C_FIELD(arg0, s8 *, 6)  = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    func_0205e624(arg0 + 0x14, 0, 8);
    func_0205e624(arg0 + 0x1C, 0, 8);
    func_0205e624(arg0 + 0x24, 0, 8);
    var_r2 = 0;
    do {
        M2C_FIELD((arg0 + var_r2), u8 *, 0x30) = var_r2;
        var_r2 += 1;
    } while ((u32) var_r2 < 4U);
    M2C_FIELD(arg0, s8 *, 0x41) = -1;
    M2C_FIELD(arg0, s8 *, 0x42) = 0;
    temp_r5                     = M2C_FIELD(arg0, s32 *, 0x10);
    if (temp_r5 != 0) {
        if (temp_r5 != 0) {
            func_0209ce44(temp_r5);
            func_0205e84c(temp_r5);
        }
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
    }
    sp[0] = 0;
    sp[1] = 0;
    sp[2] = 0;
    {
        s32 *src;
        src = sp;
        if (((s8 *) arg0 + 0x44) != (s8 *) src) {
            M2C_FIELD(arg0, s32 *, 0x44) = 0;
            M2C_FIELD(arg0, s32 *, 0x48) = src[1];
            M2C_FIELD(arg0, s32 *, 0x4C) = src[2];
        }
    }
    M2C_FIELD(arg0, s8 *, 0x41) = -1;
    M2C_FIELD(arg0, s8 *, 0x42) = 0;
    M2C_FIELD(arg0, s8 *, 6)    = 0;
    return 0;
}
