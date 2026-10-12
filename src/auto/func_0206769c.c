#include "m2c.h"

M2C_UNK func_02067908(s32, M2C_UNK);                /* extern */

void func_0206769c(void *arg0, s32 arg1, M2C_UNK arg2) {
    func_02067908(M2C_FIELD(arg0, s32 *, 4) + (arg1 * 8), arg2);
}
