#include "m2c.h"

M2C_UNK func_0202da2c(s32, u8, u8, u8, s32, s32, s32, s32, s32); /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */
s32 func_020c9268(s32, M2C_UNK);                    /* extern */

void func_02057ee4(M2C_UNK arg0, void *arg1) {
    volatile s32 sp14;
    s32 temp_r0;
    u8 temp_r0_2;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == 0) {
        return;
    }
    temp_r0_2 = M2C_FIELD(arg1, u8 *, 9);
    if (temp_r0_2 == 0) {
        sp14 = -0x1000;
    } else {
        sp14 = func_020c9268(temp_r0_2 << 0xC, 0xA000);
    }
    func_0202da2c(temp_r0, M2C_FIELD(arg1, u8 *, 2), M2C_FIELD(arg1, u8 *, 3), M2C_FIELD(arg1, u8 *, 4),
                  (s32) M2C_FIELD(arg1, u8 *, 5), (s32) M2C_FIELD(arg1, u8 *, 6), (s32) M2C_FIELD(arg1, u8 *, 7),
                  (s32) M2C_FIELD(arg1, u8 *, 8), sp14);
}
