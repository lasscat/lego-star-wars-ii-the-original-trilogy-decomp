#include "m2c.h"

s32 func_0202d7c0(void *arg0, u32 *arg1, u32 *arg2) {
    s32 var_lr;
    u8 temp_ip;
    u8 temp_r1;

    temp_ip = M2C_FIELD(arg0, u8 *, 3);
    var_lr  = 0;
    if ((u32) temp_ip < (u32) *arg1) {
        *arg1  = (u32) temp_ip;
        var_lr = 1;
    }
    temp_r1 = M2C_FIELD(arg0, u8 *, 2);
    if ((u32) temp_r1 > (u32) *arg2) {
        var_lr = 1;
        *arg2  = (u32) temp_r1;
    }
    return var_lr;
}
