#include "m2c.h"

M2C_UNK func_02067838(s32, M2C_UNK);                /* extern */

void func_02067624(void *arg0, s32 arg1, M2C_UNK arg2) {
    func_02067838(M2C_FIELD(arg0, s32 *, 4) + (arg1 * 8), arg2);
}
