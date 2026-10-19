#include "m2c.h"

s32 func_020608fc(void *);                          /* extern */
M2C_UNK func_0206090c(void *, s32);                 /* extern */
s32 func_02060928(M2C_UNK);                         /* extern */
extern s32 data_027e02a8;

s32 func_0201aa78(void *arg0) {
    M2C_UNK var_r0;
    s32 var_r5;
    u32 temp_r0;

    temp_r0 = (u32) (M2C_FIELD(arg0, s32 *, 0x10) << 0x16) >> 0x1E;
    if ((temp_r0 == 1) || (temp_r0 == 3)) {
        var_r5 = func_020608fc(arg0 + 0x10);
    } else {
        if (data_027e02a8 & 0x200) {
            var_r0 = 0;
        } else if (M2C_FIELD(arg0, s32 *, 8) & 0x80000000) {
            var_r0 = 0;
        } else {
            var_r0 = 1;
        }
        var_r5 = func_02060928(var_r0);
        func_0206090c(arg0 + 0x10, var_r5);
    }
    return var_r5;
}
