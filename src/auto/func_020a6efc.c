#include "m2c.h"

u32 func_02067b54(s32);                             /* extern */

u8 func_020a6efc(void *arg0, s32 arg1, s32 arg2) {
    u8 var_r4;

    var_r4 = arg2 + 1;
    if ((u32) var_r4 >= func_02067b54(M2C_FIELD(arg0, s32 *, 0x21C))) {
        if (M2C_FIELD(arg0, u8 *, 0x241) != 0) {
            var_r4 = 0;
        } else {
            var_r4 = arg1 - 1;
        }
    }
    return var_r4;
}
