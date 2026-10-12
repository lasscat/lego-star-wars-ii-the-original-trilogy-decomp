#include "m2c.h"

s32 func_0201aaec();                                /* extern */

void *func_020555c4(void *arg0, s32 arg1, void *arg2) {
    s32 temp_r0;

    M2C_FIELD(arg0, s32 *, 0) = arg1;
    temp_r0 = (s32) M2C_FIELD(arg2, s32 *, 0) >> (func_0201aaec() + 5);
    M2C_FIELD(arg0, s32 *, 0xC) = temp_r0;
    M2C_FIELD(arg0, s32 *, 4) = temp_r0;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) ((s32) M2C_FIELD(arg2, s32 *, 4) >> (func_0201aaec() + 5));
    M2C_FIELD(arg0, s32 *, 8) = (s32) ((s32) M2C_FIELD(arg2, s32 *, 0x10) >> (func_0201aaec() + 5));
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) ((s32) M2C_FIELD(arg2, s32 *, 0x14) >> (func_0201aaec() + 5));
    return arg0;
}
