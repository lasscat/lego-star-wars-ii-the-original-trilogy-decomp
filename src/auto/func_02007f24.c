#include "m2c.h"

s32 func_020e20d8();                                /* extern */
M2C_UNK func_020e21f0(M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */

void func_02007f24(s32 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    *arg0 = 0;
    func_020e21f0(0, 0x40B00000, arg1, arg2);
    *arg0 = func_020e20d8();
}
