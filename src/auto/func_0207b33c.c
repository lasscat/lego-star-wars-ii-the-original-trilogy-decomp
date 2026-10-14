#include "m2c.h"

s32 func_0207b33c(void *arg0) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x6BB);
    if ((temp_r0 != 9) && (temp_r0 != 0x12) && (temp_r0 != 0x17) && (temp_r0 != 0x20) && (temp_r0 != 0x32) &&
        (temp_r0 != 0x35) && (temp_r0 != 0x36) && (temp_r0 != 0x37) && (temp_r0 != 0x3B)) {
        return 1;
    }
    return 0;
}
