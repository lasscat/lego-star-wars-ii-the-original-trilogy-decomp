#include "m2c.h"

M2C_UNK func_020cdd20(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020ceb20(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020cec10(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_0205e724(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    func_020cdd20(arg1, arg3);
    if (arg4 == 0x20) {
        func_020ceb20(arg0, arg1, arg2, arg3);
        return;
    }
    func_020cec10(arg0, arg1, arg2, arg3);
}
