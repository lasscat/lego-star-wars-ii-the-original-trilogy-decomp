#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02065be8(void *, u16, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_020660c0(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_02066708(M2C_UNK);                         /* extern */

void func_02076bc0(void *arg0, s32 arg1) {
    M2C_UNK var_r4;

    var_r4 = 3;
    if (arg1 != 0) {
        var_r4 = 6;
    }
    func_020660c0(arg0 + 0x54, 0xC, 0x15, 0xA, 0x30);
    func_020660c0(arg0 + 0x54, 0xC, 0x16, 0xA, 0x30);
    func_0206574c(arg0 + 0x54, var_r4, -2);
    func_02065be8(arg0 + 0x54, M2C_FIELD(arg0, u16 *, 0x84), 0x80, 0xA8, func_02066708(0x69), 1);
}
