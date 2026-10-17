#include "m2c.h"

void func_0208f730(void *arg0, s32 arg1) {
    s32 var_lr;
    u8 temp_ip;

    var_lr = 0;
    do {
        temp_ip = *(s8 *) (arg1 + var_lr);
        var_lr += 1;
        if (temp_ip != 0xFF) {
            M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) | (1 << temp_ip));
        }
    } while (var_lr < 8U);
}