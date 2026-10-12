#include "m2c.h"

M2C_UNK func_020acbc4();                            /* extern */

void func_0209f55c(void *arg0, s32 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0xAC) = arg2;
    M2C_FIELD(arg0, s16 *, 0xAE) = 0xF5;
    M2C_FIELD(arg0, s8 *, 0xB1) = 0;
    func_020acbc4(arg0, arg1);
    M2C_FIELD(arg0, u16 *, 0xB2) = (u16) ((M2C_FIELD(arg0, u16 *, 0xB2) & ~1) | 1);
}
