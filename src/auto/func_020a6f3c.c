#include "m2c.h"

u32 func_02067b54(s32);                             /* extern */

u8 func_020a6f3c(void *arg0, s32 arg1) {
    u8 var_r4;

    var_r4 = arg1 - 1;
    if ((M2C_FIELD(arg0, u8 *, 0x241) != 0) && ((u32) var_r4 >= func_02067b54(M2C_FIELD(arg0, s32 *, 0x21C)))) {
        var_r4 = func_02067b54(M2C_FIELD(arg0, s32 *, 0x21C)) - 1;
    }
    return var_r4;
}
