#include "m2c.h"

M2C_UNK func_02067800(s32);                         /* extern */
M2C_UNK func_020679f0(s32);                         /* extern */

void func_0206763c(void *arg0, s32 arg1) {
    u32 temp_r4;

    if (arg1 == 0) {
        return;
    }
    temp_r4 = arg1 - 1;
    if (temp_r4 == 0) {
        if (M2C_FIELD(arg0, u8 *, 0x24) == 1) {
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x24) = 1U;
        goto block_6;
    }
block_6:
    if (temp_r4 >= (u32) M2C_FIELD(arg0, u16 *, 0x18)) {
        return;
    }
    func_02067800(M2C_FIELD(arg0, s32 *, 4) + (temp_r4 * 8));
    if (M2C_FIELD(arg0, u8 *, 0x23) != 1) {
        return;
    }
    func_020679f0(M2C_FIELD(arg0, s32 *, 4) + (temp_r4 * 8));
}
