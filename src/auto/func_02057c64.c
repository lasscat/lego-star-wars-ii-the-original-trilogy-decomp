#include "m2c.h"

M2C_UNK func_020a9974(s32, u8, u8, u8);             /* extern */
s32 func_020aaeb4();                                /* extern */

void func_02057c64(s32 arg0, void *arg1) {
    func_020a9974(func_020aaeb4(), M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2));
}
