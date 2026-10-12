#include "m2c.h"

s32 func_02052f9c();                                /* extern */
M2C_UNK func_02052fd8();                            /* extern */
s32 func_020d4ffc();                                /* extern */
s32 func_020d54b0(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32); /* extern */
s32 func_020d55ac(s32);                             /* extern */

s32 func_02052df8(void) {
    M2C_UNK sp14;
    s32 var_r4;

    var_r4 = 1;
    if (func_02052f9c() != 0) {
        if ((func_020d55ac(0x901) != 0) && (func_020d4ffc() != 0) && (func_020d54b0(0, &sp14, 1, 0, 0, 0, 6, 1, 0) == 1)) {
            var_r4 = 0;
        }
        func_02052fd8();
    }
    if (var_r4 == 0) {
        return 1;
    }
    return 0;
}
