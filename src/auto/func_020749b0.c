#include "m2c.h"

s32 func_02062a7c(M2C_UNK, M2C_UNK);                /* extern */

void func_020749b0(s32 arg0, void *arg1, M2C_UNK arg2, M2C_UNK arg3) {
    M2C_FIELD(arg1, s32 *, 8) = (s32) (M2C_FIELD(arg1, s32 *, 8) + (func_02062a7c(arg2, arg3) << 0xC));
}
