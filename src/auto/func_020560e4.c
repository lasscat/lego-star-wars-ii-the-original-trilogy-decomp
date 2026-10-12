#include "m2c.h"

M2C_UNK func_020676b4(s32, u8);                     /* extern */

void func_020560e4(void *arg0, u8 *arg1) {
    func_020676b4(M2C_FIELD(arg0, s32 *, 4) + 0x28, *arg1);
}
