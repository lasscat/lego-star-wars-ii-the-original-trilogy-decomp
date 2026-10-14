#include "m2c.h"

void *func_020aaeb4();                              /* extern */

void func_02057718(s32 arg0, u8 *arg1) {
    u8 temp_r4;

    temp_r4                                 = *arg1;
    M2C_FIELD(func_020aaeb4(), u8 *, 0x3D8) = temp_r4;
}
