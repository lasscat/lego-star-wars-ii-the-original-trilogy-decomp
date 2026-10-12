#include "m2c.h"

M2C_UNK func_02065a78(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_020660e4(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s32 func_02066708(s32);                             /* extern */

void func_02077e60(s32 arg0, s32 arg1) {
    func_020660e4(arg0 + 0x40, 0, 0x13, 0x1E, 0);
    func_020660e4(arg0 + 0x70, 0, 0x11, 0x1E, 0);
    func_020660e4(arg0 + 0x70, 0, 0x12, 0x1E, 0);
    if (arg1 >= 0x535) {
        return;
    }
    func_02065a78(arg0 + 0x70, 0x89, 0x80, 0x8D, 0xB4, func_02066708(arg1), 1);
}
