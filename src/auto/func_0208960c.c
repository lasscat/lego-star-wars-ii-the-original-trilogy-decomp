#include "m2c.h"

s8 func_0208960c(void *arg0, s32 arg1) {
    s8 temp_r2;
    s8 var_ip;
    void *var_r0;

    var_r0 = arg0;
    var_ip = 0;
loop_1:
    temp_r2 = M2C_FIELD(var_r0, s8 *, 0x28CC);
    if ((temp_r2 != -1) && (arg1 != temp_r2)) {
        var_ip += 1;
        var_r0 += 0xA;
        if ((s32) var_ip < 7) {
            goto loop_1;
        }
    }
    return var_ip;
}
