#include "m2c.h"

M2C_UNK func_020cf3dc(M2C_UNK, s32, M2C_UNK);       /* extern */

s32 func_020d2050(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    func_020cf3dc(arg1, M2C_FIELD(arg0, s32 *, 0x28) + arg2, arg3);
    return 0;
}
