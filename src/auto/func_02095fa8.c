#include "m2c.h"

s32 func_02095fa8(s32 arg0, void *arg1) {
    u8 temp_r2;

    temp_r2 = M2C_FIELD(arg1, u8 *, 2);
    if (temp_r2 == 0xFF) {
        return 0;
    }
    return arg0 + 4 + (temp_r2 * 3);
}
