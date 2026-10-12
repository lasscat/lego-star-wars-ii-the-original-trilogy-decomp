#include "m2c.h"

M2C_UNK func_020aae4c(s16 *, s32, u8);              /* extern */
s32 func_020aaeb4();                                /* extern */

void func_0204a5bc(s16 *arg0, void *arg1) {
    u8 temp_r4;

    temp_r4 = M2C_FIELD(arg1, u8 *, 0xC);
    if (temp_r4 == 4) {
        *arg0 = 0;
        return;
    }
    func_020aae4c(arg0, func_020aaeb4(), temp_r4);
}
