#include "m2c.h"
void func_020c7fa8(void *arg0, void *arg1) {
    s32 temp_r2;
    M2C_FIELD(arg0, s32 *, 0)    = M2C_FIELD(arg1, s32 *, 0x18);
    temp_r2                      = M2C_FIELD(arg1, s32 *, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x14) = temp_r2;
    M2C_FIELD(arg0, s32 *, 4)    = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = M2C_FIELD(arg1, u16 *, 0x2E) * (temp_r2 * -2 + 0x2000) * 8;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}
