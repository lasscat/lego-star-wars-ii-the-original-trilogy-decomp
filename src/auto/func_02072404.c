#include "m2c.h"

M2C_UNK func_02053c2c(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */

void func_02072404(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xA4) = arg1;
    if (arg1 != 3) {
        return;
    }
    func_02053c2c(arg0 + 0x28, 0, 4, 0x20, 0xD, 0);
}
