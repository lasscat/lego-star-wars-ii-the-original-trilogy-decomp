#include "m2c.h"

void func_02004b44(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x6C4);
    if (temp_r1 & 1) {
        return;
    }
    if (temp_r1 & 2) {
        M2C_FIELD(arg0, u8 *, 0x6C4) = (u8) (temp_r1 & ~2);
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x6C4) = (u8) (temp_r1 | 2);
}
