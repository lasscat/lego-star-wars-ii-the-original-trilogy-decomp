#include "m2c.h"

void *func_020bd700();                              /* extern */

void *func_020bdcfc(void *arg0) {
    void *temp_r0;

    temp_r0 = func_020bd700();
    M2C_FIELD(arg0, s32 *, 0x68) = (s32) M2C_FIELD(temp_r0, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x6C) = (s32) M2C_FIELD(temp_r0, s32 *, 4);
    return temp_r0 + 8;
}
