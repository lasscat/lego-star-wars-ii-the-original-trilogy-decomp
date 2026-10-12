#include "m2c.h"

M2C_UNK func_01ffd488(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_020cca48(M2C_UNK, M2C_UNK (*)(s32), s32); /* extern */
M2C_UNK func_020cee9c(M2C_UNK);                     /* extern */
M2C_UNK func_020cf004(M2C_UNK, M2C_UNK, u32, M2C_UNK); /* extern */

void func_020ced40(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, u32 arg3, M2C_UNK (*arg4)(s32), s32 arg5) {
    func_020cf004(arg0, arg1, arg3, 0);
    if (arg3 == 0) {
        if (arg4 == NULL) {
            return;
        }
        arg4(arg5);
        return;
    }
    func_020cee9c(arg0);
    if (arg4 != NULL) {
        func_020cca48(arg0, arg4, arg5);
        func_01ffd488(arg0, arg1, arg2, (arg3 >> 2) | 0xC4000000);
        return;
    }
    func_01ffd488(arg0, arg1, arg2, (arg3 >> 2) | 0x84000000);
}
