#include "m2c.h"

M2C_UNK func_02067a98(s32, s32);                    /* extern */

void func_020675d8(void *arg0, s32 arg1) {
    u32 temp_r4;

    if (arg1 == 0) {
        return;
    }
    temp_r4 = arg1 - 1;
    if ((temp_r4 == 0) && (M2C_FIELD(arg0, u8 *, 0x23) == 1)) {
        return;
    }
    if (temp_r4 >= (u32) M2C_FIELD(arg0, u16 *, 0x1A)) {
        return;
    }
    func_02067a98(M2C_FIELD(arg0, s32 *, 8) + (temp_r4 * 8), M2C_FIELD(arg0, s32 *, 0));
    if (temp_r4 == 0) {
        M2C_FIELD(arg0, u8 *, 0x23) = 1U;
    }
}
