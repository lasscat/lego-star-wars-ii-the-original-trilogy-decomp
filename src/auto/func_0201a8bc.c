#include "m2c.h"

s32 func_020608fc(void *);                          /* extern */
M2C_UNK func_0206090c(void *, M2C_UNK);             /* extern */
M2C_UNK func_020609ac(s32, M2C_UNK);                /* extern */
extern s32 data_027e02a8;

void func_0201a8bc(void *arg0) {
    M2C_UNK var_r1;
    s32 temp_r5;
    u32 temp_r0;

    temp_r0 = (u32) (M2C_FIELD(arg0, volatile s32 *, 0x10) << 0x16) >> 0x1E;
    if ((temp_r0 != 1) && (temp_r0 != 3)) {
        return;
    }
    M2C_FIELD(arg0, volatile s32 *, 0x10) = (s32) (M2C_FIELD(arg0, volatile s32 *, 0x10) & ~0x300);
    temp_r5 = func_020608fc(arg0 + 0x10);
    func_0206090c(arg0 + 0x10, 0);
    if (data_027e02a8 & 0x200) {
        var_r1 = 0;
    } else if (M2C_FIELD(arg0, volatile s32 *, 8) & 0x80000000) {
        var_r1 = 0;
    } else {
        var_r1 = 1;
    }
    func_020609ac(temp_r5, var_r1);
}
