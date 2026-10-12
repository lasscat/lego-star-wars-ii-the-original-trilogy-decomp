#include "m2c.h"

M2C_UNK func_0205eb98();                            /* extern */

void func_0205eb6c(void *arg0, s32 arg1, s32 arg2) {
    func_0205eb98();
    M2C_FIELD(arg0, s32 *, 0x24) = arg1;
    if (arg2 != 0) {
        M2C_FIELD(arg0, s32 *, 0x20) = (s32) (M2C_FIELD(arg0, s32 *, 0x20) | 2);
    }
}
