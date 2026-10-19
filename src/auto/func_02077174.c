#include "m2c.h"
s8 func_02077174(void *arg0) {
    u8 temp_r1_2;
    temp_r1_2 = M2C_FIELD(arg0, u8 *, 0xD0);
    if (temp_r1_2 == 1) {
        return M2C_FIELD((arg0 + M2C_FIELD(arg0, s8 *, 0xD2)), s8 *, 0x137);
    }
    if (temp_r1_2 == 0) {
        return M2C_FIELD((arg0 + M2C_FIELD(arg0, s8 *, 0xD2)), s8 *, 0x130);
    }
    return M2C_FIELD((arg0 + M2C_FIELD(arg0, s8 *, 0xD2)), s8 *, 0x13E);
}
