#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02065a78(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_020660e4(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_02066708(s32);                             /* extern */

void func_02077f04(s32 arg0, s32 arg1) {
    func_020660e4(arg0 + 0x40, 0, 0x11, 0x1E, 0);
    func_020660e4(arg0 + 0x40, 0, 0x12, 0x1E, 0);
    func_020660e4(arg0 + 0x40, 0, 0x13, 0x1E, 0);
    func_020660e4(arg0 + 0x40, 0, 0x14, 0x1E, 0);
    func_020660e4(arg0 + 0x40, 0, 0x15, 0x1E, 0);
    func_020660e4(arg0 + 0x40, 0, 0x16, 0x1E, 0);
    func_020660e4(arg0 + 0x40, 0, 0x17, 0x1E, 0);
    func_020660e4(arg0 + 0x40, 0, 0x10, 0x1E, 0);
    if (arg1 >= 0x535) {
        return;
    }
    func_0206574c(arg0 + 0x40, 9, -1);
    func_02065a78(arg0 + 0x40, 0x89, 0x72, 0x8D, 0xC8, func_02066708(arg1), 1);
}
