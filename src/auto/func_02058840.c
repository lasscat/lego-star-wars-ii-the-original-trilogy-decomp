#include "m2c.h"

s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */
M2C_UNK func_020a0370(s32, s32);                    /* extern */
M2C_UNK func_020a99a8();                            /* extern */
s32 func_020aaeb4();                                /* extern */

void func_02058840(M2C_UNK arg0, void *arg1) {
    s32 temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == 0) {
        return;
    }
    func_020a0370(func_020aaeb4(), temp_r0);
    func_020aaeb4();
    func_020a99a8();
}
