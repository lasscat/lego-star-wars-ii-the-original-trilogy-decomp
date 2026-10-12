#include "m2c.h"

M2C_UNK func_020675d8(s32, M2C_UNK);                /* extern */

void func_02066fc8(void *arg0) {
    func_020675d8(M2C_FIELD(arg0, s32 *, 4), 1);
    func_020675d8(M2C_FIELD(arg0, s32 *, 4) + 0x28, 1);
}
