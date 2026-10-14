#include "m2c.h"

void func_02055630(void *arg0) {
    s32 temp_r2;

    temp_r2                   = M2C_FIELD(arg0, s32 *, 4) + 1;
    M2C_FIELD(arg0, s32 *, 4) = temp_r2;
    if (temp_r2 <= (s32) M2C_FIELD(arg0, s32 *, 0x10)) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
}
