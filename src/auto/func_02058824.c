#include "m2c.h"

M2C_UNK func_020a95d4(s32, u8, s32);                /* extern */
s32 func_020aaeb4();                                /* extern */

void func_02058824(s32 arg0, void *arg1) {
    func_020a95d4(func_020aaeb4(), M2C_FIELD(arg1, u8 *, 4), M2C_FIELD(arg1, s32 *, 0));
}
