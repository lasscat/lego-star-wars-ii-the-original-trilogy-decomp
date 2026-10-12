#include "m2c.h"

s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0209413c(s32, u16, u8, u8, s32);       /* extern */

s32 func_020513e8(void *arg0) {
    s32 temp_r0;

    temp_r0 = func_0205e80c(0xC, 0, 4);
    if (temp_r0 != 0) {
        func_0209413c(temp_r0, M2C_FIELD(arg0, u16 *, 8), M2C_FIELD(arg0, u8 *, 0xB), M2C_FIELD(arg0, u8 *, 0xC), 1);
    }
    return 0;
}
