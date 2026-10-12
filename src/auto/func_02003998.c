#include "m2c.h"

void func_02003998(void *arg0, s8 arg1) {
    s8 var_r1;

    var_r1 = arg1;
    if (var_r1 == 0xC) {
        var_r1 = 0xA;
    }
    M2C_FIELD(arg0, s8 *, 0x6F4) = var_r1;
}
