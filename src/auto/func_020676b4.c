#include "m2c.h"

M2C_UNK func_020679b8(s32);                         /* extern */

void func_020676b4(void *arg0, s32 arg1) {
    func_020679b8(M2C_FIELD(arg0, s32 *, 4) + ((arg1 - 1) * 8));
}
