#include "m2c.h"

s32 func_0200aef8(void *, void *, s32);             /* extern */
s32 func_020296a4(void *, void *, M2C_UNK);         /* extern */
extern s32 data_02104d90;

s32 func_02029894(void *arg0, void *arg1) {
    s32 var_r6;
    s32 var_r7;
    volatile s32 sp0;
    s32 temp;
    void *temp_r1;

    var_r6 = 1;
    var_r7 = var_r6;
    sp0    = 0xA000;
    if ((func_0200aef8(arg1 + 0xB0, arg0 + 0x7C, 0xA000) != 0) && (M2C_FIELD(arg1, u8 *, 0x5D6) == 0)) {
        var_r7 = 0;
    }
    if ((var_r7 == 0) && ((data_02104d90 & 1) == 0)) {
        var_r6 = 0;
    }
    if (var_r6 != 0) {
        temp_r1 = arg1 + 0xB0;
        if ((arg0 + 0x7C) != temp_r1) {
            M2C_FIELD(arg0, s32 *, 0x7C) = M2C_FIELD(temp_r1, s32 *, 0);
            M2C_FIELD(arg0, s32 *, 0x80) = M2C_FIELD(temp_r1, s32 *, 4);
            M2C_FIELD(arg0, s32 *, 0x84) = M2C_FIELD(temp_r1, s32 *, 8);
        }
        M2C_FIELD(arg0, u8 *, 0x92) = 0;
    } else {
        temp                        = M2C_FIELD(arg0, u8 *, 0x92) + 1;
        M2C_FIELD(arg0, u8 *, 0x92) = temp;
        if (((u32) temp & 0xFF) >= 0x5A) {
            temp_r1 = arg1 + 0xB0;
            if ((arg0 + 0x7C) != temp_r1) {
                M2C_FIELD(arg0, s32 *, 0x7C) = M2C_FIELD(temp_r1, s32 *, 0);
                M2C_FIELD(arg0, s32 *, 0x80) = M2C_FIELD(temp_r1, s32 *, 4);
                M2C_FIELD(arg0, s32 *, 0x84) = M2C_FIELD(temp_r1, s32 *, 8);
            }
            M2C_FIELD(arg0, u8 *, 0x92) = 0;
            if ((M2C_FIELD(arg1, s32 *, 0x1B8) & 2) && (func_020296a4(arg0, arg1, 2) != 0)) {
                return 1;
            }
        }
    }
    return 0;
}
