#include "m2c.h"

M2C_UNK func_02066b4c(M2C_UNK, s32, s32);           /* extern */
M2C_UNK memset(M2C_UNK *, M2C_UNK, s32);     /* extern */

void func_0209bd08(s32 arg0, s32 arg1, M2C_UNK arg2, s32 arg3) {
    u8 sp0[24];

    memset(sp0, 0, arg3 + 1);
    func_02066b4c(arg2, arg3, (arg1 * 0x18) + (arg0 + 0x51));
}
