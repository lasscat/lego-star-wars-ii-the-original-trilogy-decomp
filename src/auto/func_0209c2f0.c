#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02065be8(s32, s32, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_020661b4(s32, s32);                    /* extern */
s32 func_02066708(s32);                             /* extern */

void func_0209c2f0(s32 arg0, s32 *arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    func_020661b4(arg0 + 0x34, arg2);
    if (arg2 > 0) {
        func_0206574c(arg0 + 0x34, 3, -1);
    } else if (arg2 == 0) {
        func_0206574c(arg0 + 0x34, 0, -1);
    } else {
        func_0206574c(arg0 + 0x34, 9, -1);
    }
    *arg1 = func_02065be8(arg0 + 0x34, *arg1, arg3, arg4, func_02066708(0x292), 1);
}
