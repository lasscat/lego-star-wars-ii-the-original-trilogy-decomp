#include "m2c.h"

void *func_020be664();                              /* extern */

void *func_020c06e4(void *arg0) {
    void *temp_r0;

    temp_r0                      = func_020be664();
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) M2C_FIELD(temp_r0, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(temp_r0, s32 *, 4);
    return temp_r0 + 8;
}
