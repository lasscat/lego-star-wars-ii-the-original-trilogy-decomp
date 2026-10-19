#include "m2c.h"

s32 _dfix();                                /* extern */
M2C_UNK _dmul(M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */

void func_02007f24(s32 *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    *arg0 = 0;
    _dmul(0, 0x40B00000, arg1, arg2);
    *arg0 = _dfix();
}
