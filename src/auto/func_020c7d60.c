#include "m2c.h"

void func_020c7d60(void *arg0, void *arg1) {
    s32 temp_r2;
    s32 temp_r3;

    temp_r2                      = M2C_FIELD(arg1, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0)    = temp_r2;
    temp_r3                      = M2C_FIELD(arg1, s32 *, 0x1C);
    M2C_FIELD(arg0, s32 *, 0x14) = temp_r3;
    M2C_FIELD(arg0, s32 *, 4)    = 0;
    M2C_FIELD(arg0, s32 *, 0x30) =
        (0 - (s32) (((s64) temp_r2 * M2C_FIELD(arg1, s32 *, 0x24)) >> 8)) * M2C_FIELD(arg1, u16 *, 0x2C);
    M2C_FIELD(arg0, s32 *, 0x34) = M2C_FIELD(arg1, u16 *, 0x2E) * (temp_r3 * -2 + 0x2000) * 8 +
                                   M2C_FIELD(arg1, u16 *, 0x2E) * (s32) (((s64) temp_r3 * M2C_FIELD(arg1, s32 *, 0x28)) >> 8);
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
}
