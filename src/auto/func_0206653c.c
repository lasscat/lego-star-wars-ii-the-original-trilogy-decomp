#include "m2c.h"

M2C_UNK func_020665d8(M2C_UNK, s32, M2C_UNK, s32);  /* extern */

void func_0206653c(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (arg1 != 7) {
        func_020665d8(arg0, arg1, 0, arg6);
    }
    if (arg2 != 7) {
        func_020665d8(arg0, arg2, 3, arg6);
    }
    if (arg3 != 7) {
        func_020665d8(arg0, arg3, 6, arg6);
    }
    if (arg4 != 7) {
        func_020665d8(arg0, arg4, 9, arg6);
    }
    if (arg5 == 7) {
        return;
    }
    func_020665d8(arg0, arg5, 0xC, arg6);
}
