#include "m2c.h"

extern void *data_02102900;

void func_02059b04(void) {
    s32 var_r0;

    if (data_02102900 != NULL) {
        var_r0 = M2C_FIELD(data_02102900, s32 *, 4);
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 4) {
        M2C_FIELD(data_02102900, s8 *, 0xBC) = 1;
    }
}
