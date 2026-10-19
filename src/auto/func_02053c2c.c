#include "m2c.h"

M2C_UNK func_02053b8c(M2C_UNK, s32, s32, u16);      /* extern */

void func_02053c2c(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 i;
    s32 j;

    for (i = arg1; i < arg1 + arg3; i++) {
        for (j = arg2; j < arg2 + arg4; j++) {
            func_02053b8c(arg0, i, j, (u16) arg5);
        }
    }
}
