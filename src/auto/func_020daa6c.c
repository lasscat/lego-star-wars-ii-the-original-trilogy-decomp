#include "m2c.h"

M2C_UNK func_020cf19c(M2C_UNK, void *, M2C_UNK);    /* extern */
M2C_UNK func_020cf1b8(s32, void *, u16);            /* extern */
M2C_UNK func_020cf228(M2C_UNK, void *, M2C_UNK);    /* extern */
s32 func_020dab5c(s32, void *, M2C_UNK);            /* extern */
s32 func_020dac6c(s32);                             /* extern */

void func_020daa6c(void *arg0, void *arg1, s32 arg2) {
    s32 var_r0;
    s32 var_r7;

    func_020cf19c(0, arg0, 0x4C0);
    M2C_FIELD(arg0, s8 *, 0x4B2) = 0;
    if (func_020dab5c(M2C_FIELD(arg1, s32 *, 0xC), arg0, 1) == 0) {
        var_r7 = 1;
    } else {
        var_r7 = 0;
    }
    if (func_020dab5c(M2C_FIELD(arg1, s32 *, 0x10), arg0, 0) == 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if ((var_r7 | var_r0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x4B2) = 1;
        func_020cf228(0, arg0, 0x220);
    }
    M2C_FIELD(arg0, s32 *, 0x4B8) = (s32) M2C_FIELD(arg1, s32 *, 0x14);
    if (arg2 != 0) {
        func_020cf1b8(arg2, arg0 + 0x220, 0x16U);
    }
    M2C_FIELD(arg0, u8 *, 0x236) = (u8) M2C_FIELD(arg1, u8 *, 0x18);
    func_020cf1b8(M2C_FIELD(arg1, s32 *, 4), arg0 + 0x238, (u16) (func_020dac6c(M2C_FIELD(arg1, s32 *, 4)) * 2));
    func_020cf1b8(M2C_FIELD(arg1, s32 *, 8), arg0 + 0x298, 0xC0U);
    M2C_FIELD(arg0, s8 *, 0x358)  = 1;
    M2C_FIELD(arg0, s16 *, 0x35A) = 1;
    M2C_FIELD(arg0, s16 *, 0x4B0) = 1;
}
