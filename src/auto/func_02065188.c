#include "m2c.h"

M2C_UNK func_020652f4();                            /* extern */
M2C_UNK func_020c3c74(s32, M2C_UNK);                /* extern */
M2C_UNK func_020c3d40(s32, M2C_UNK);                /* extern */

void func_02065188(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0) {
        return;
    }
    if (arg2 != 0) {
        func_020c3c74(arg1, 1);
        func_020c3d40(arg1, 1);
    } else {
        func_020652f4();
    }
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 2);
}
