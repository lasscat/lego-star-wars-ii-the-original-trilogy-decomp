#include "m2c.h"

M2C_UNK func_02090228();                            /* extern */

void func_020901d0(void *arg0) {
    s32 temp_r1;
    s32 temp_r2;
    s32 var_r3;
    u32 var_r2;

    var_r3 = 0;
    var_r2 = 0;
    do {
        temp_r1 = ((s32 *) arg0)[var_r2 + 0xF6];
        var_r2 += 1;
        var_r3 |= temp_r1;
    } while (var_r2 < 4U);
    M2C_FIELD(arg0, s8 *, 0x478) = 0;
    temp_r2                      = var_r3 | M2C_FIELD(arg0, s32 *, 0x3D0);
    temp_r2 &= ~M2C_FIELD(arg0, s32 *, 0x3D4);
    if (temp_r2 == M2C_FIELD(arg0, s32 *, 0x3CC)) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x3CC) = temp_r2;
    func_02090228();
}
