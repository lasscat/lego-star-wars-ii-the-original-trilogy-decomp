#include "m2c.h"

M2C_UNK func_02055d0c(M2C_UNK, void *, s32, s32);   /* extern */

void func_02055d34(M2C_UNK arg0, s32 arg1, s32 arg2, void *arg3) {
    func_02055d0c(arg0, arg3 + (arg1 * 2), M2C_FIELD(arg3, s32 *, 0x200) + (arg1 * 2), arg2 * 2);
}
