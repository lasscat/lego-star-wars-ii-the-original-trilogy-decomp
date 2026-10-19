#include "m2c.h"

extern M2C_UNK data_02101b78;

s32 func_020539c8(s32 *arg0) {
    s32 t = *(s32 *) ((u8 *) &data_02101b78 + arg0[0] * 32 + 4) & 7;
    if (t == 1 && arg0[1] >= 3) {
        goto ret1;
    }
    if (t == 2 && arg0[1] >= 2) {
        goto ret1;
    }
    if (t == 4 && arg0[1] == 2) {
        goto ret1;
    }
    goto ret0;
ret1:
    return 1;
ret0:
    return 0;
}
