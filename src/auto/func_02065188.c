#include "m2c.h"

M2C_UNK func_020652f4();                            /* extern */
M2C_UNK NNS_G3dTexLoad(s32, M2C_UNK);                /* extern */
M2C_UNK NNS_G3dPlttLoad(s32, M2C_UNK);                /* extern */

void func_02065188(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0) {
        return;
    }
    if (arg2 != 0) {
        NNS_G3dTexLoad(arg1, 1);
        NNS_G3dPlttLoad(arg1, 1);
    } else {
        func_020652f4();
    }
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 2);
}
