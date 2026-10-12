#include "m2c.h"

s32 func_02062a7c(M2C_UNK, s32);                    /* extern */

s32 func_0206704c(void *arg0) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u16 *, 0xC16);
    if (temp_r0 == 0) {
        return 0;
    }
    return M2C_FIELD(arg0, s32 *, 0) + (func_02062a7c(0, temp_r0 - 1) * 4);
}
