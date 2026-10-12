#include "m2c.h"

M2C_UNK func_020cdd40(M2C_UNK, s32);                /* extern */
M2C_UNK func_020cdd68();                            /* extern */
M2C_UNK func_020dccf0(M2C_UNK, s32, M2C_UNK);       /* extern */

void func_020da9e8(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_020cdd40(arg2, (arg0 + 0x1F) & ~0x1F);
    func_020cdd68();
    func_020dccf0(arg2, arg0, arg1);
}
