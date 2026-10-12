#include "m2c.h"

s32 func_02073034();                                /* extern */

s32 func_020ad2a8(void *arg0, void *arg1) {
    s32 var_r4;

    var_r4 = 0;
    if (func_02073034() > 0) {
loop_1:
        if (M2C_FIELD(arg1, s32 *, 4) != M2C_FIELD(arg0, s32 *, 4)) {
            return 0;
        }
        var_r4 += 1;
        if (var_r4 >= func_02073034()) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    if (M2C_FIELD(arg1, u16 *, 0) == M2C_FIELD(arg0, u16 *, 0)) {
        return 1;
    }
    return 0;
}
