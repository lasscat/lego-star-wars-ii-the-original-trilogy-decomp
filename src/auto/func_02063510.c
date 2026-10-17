#include "m2c.h"

u16 func_02063510(u16 *arg0, u32 arg1) {
    u16 *var_r0;
    u16 temp_r1;
    u16 var_r2;
    u32 var_r3;

    var_r0 = arg0;
    var_r3 = arg1 >> 1;
    var_r2 = 0;
    if (var_r3 != 0) {
        do {
            temp_r1 = *var_r0;
            var_r0  = (u16 *) ((s8 *) var_r0 + 2);
            var_r3 -= 1;
            var_r2 += temp_r1;
        } while (var_r3 != 0);
    }
    return var_r2;
}
