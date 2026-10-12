#include "m2c.h"

void func_020250e8(void *arg0) {
    s8 temp_r3;

    temp_r3 = M2C_FIELD(arg0, s8 *, 0x1D8);
    if ((s32) temp_r3 > (s32) M2C_FIELD(arg0, u8 *, 0x1DC)) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x1D8) = (s8) (temp_r3 + 1);
    if ((s32) M2C_FIELD(arg0, s8 *, 0x1D8) >= (s32) M2C_FIELD(arg0, u8 *, 0x1DC)) {
        M2C_FIELD(arg0, s8 *, 0x232) = 1;
    }
}
