#include "m2c.h"

void func_0201e67c(void *arg0, void **arg1) {
    u16 temp_r1;

    temp_r1 = M2C_FIELD(*arg1, u16 *, 0xC);
    if ((temp_r1 != 1) && (temp_r1 != 0x10)) {
        return;
    }
    if ((u32) M2C_FIELD(arg0, u8 *, 0x1BC) <= 2U) {
        M2C_FIELD(arg0, u8 *, 0x1BC) = 3U;
    }
}
