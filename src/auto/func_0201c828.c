#include "m2c.h"

u32 func_0201c828(s32 arg0) {
    u32 var_r2;
    u32 var_r3;
    s32 var_ip;
    u16 temp_r1;

    var_r2 = 0;
    var_r3 = 0;
    var_ip = 0;
    do {
        temp_r1 = M2C_FIELD((arg0 + (var_r3 * 2)), u16 *, 2);
        var_r3 += 1;
        var_r2 += temp_r1 << var_ip;
        var_ip += 8;
    } while (var_r3 < 4U);
    return var_r2;
}
