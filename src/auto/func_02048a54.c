#include "m2c.h"

M2C_UNK func_0204a5bc(u16 *, s32);                  /* extern */

void func_02048a54(void *arg0, s32 arg1) {
    u16 sp0;
    s32 var_r0;
    s32 v;

    M2C_FIELD(arg0, u8 *, 0x30) = (u8) arg1;
    v                           = arg1 & 0xFF;
    if (v != 1) {
        return;
    }
    func_0204a5bc(&sp0, M2C_FIELD(arg0, void **, 4) + 0x5CE);
    var_r0 = (s32) (s16) (u16) (M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0xCA) - sp0);
    if (var_r0 < 0) {
        var_r0 = 0 - var_r0;
    }
    if (var_r0 < 0x4000) {
        M2C_FIELD(arg0, s8 *, 0x1C) = 0;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x1C) = 1;
}
