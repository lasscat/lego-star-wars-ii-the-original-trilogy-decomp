#include "m2c.h"

M2C_UNK func_020ab1a8(s32);                         /* extern */

void func_020acba8(void *arg0) {
    func_020ab1a8(arg0 + 4);
    M2C_FIELD(arg0, s8 *, 0x1C) = 0;
}
