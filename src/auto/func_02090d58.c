#include "m2c.h"

M2C_UNK func_02090d7c();                            /* extern */

s32 func_02090d58(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x924) == 0) {
        return;
    }
    func_02090d7c();
    return M2C_FIELD(arg0, u8 *, 0x924) = 0U;
}
