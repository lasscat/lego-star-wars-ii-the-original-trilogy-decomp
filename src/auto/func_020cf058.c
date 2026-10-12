#include "m2c.h"

M2C_UNK func_01ffd488(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_020cee9c(M2C_UNK);                     /* extern */
M2C_UNK func_020cef80(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020cf004(M2C_UNK, M2C_UNK, u32, M2C_UNK); /* extern */

void func_020cf058(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, u32 arg3) {
    func_020cef80(arg0, 0x10000000);
    func_020cf004(arg0, arg1, arg3, 0);
    if (arg3 == 0) {
        return;
    }
    func_020cee9c(arg0);
    func_01ffd488(arg0, arg1, arg2, 0x92600000 | (arg3 >> 1));
}
