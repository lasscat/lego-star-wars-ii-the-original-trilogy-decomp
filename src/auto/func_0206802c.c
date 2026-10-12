#include "m2c.h"

void *func_020aaeb4();                              /* extern */

void func_0206802c(void *arg0) {
    s32 temp_r2;
    s32 temp_r4;

    temp_r4 = M2C_FIELD(func_020aaeb4(), s32 *, 0x21C);
    temp_r2 = M2C_FIELD(func_020aaeb4(), s32 *, 0x220);
    if ((M2C_FIELD(arg0, s32 *, 0x48) == temp_r4) && (temp_r2 == M2C_FIELD(arg0, s32 *, 0x4C))) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x48) = temp_r4;
    M2C_FIELD(arg0, s32 *, 0x4C) = temp_r2;
}
