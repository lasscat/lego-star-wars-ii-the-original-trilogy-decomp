#include "m2c.h"

s32 func_020917b4(M2C_UNK *);                       /* extern */
extern M2C_UNK data_0210930c;

s8 func_0208a5b4(s32 arg0) {
    s8 var_r5;
    u8 var_r6;

    var_r5 = -1;
    var_r6 = 0;
loop_1:
    if (M2C_FIELD(((var_r6 * 0xA) + arg0), s8 *, 0x28CC) == func_020917b4(&data_0210930c)) {
        var_r5 = var_r6;
    } else {
        var_r6 = (u8) (var_r6 + 1);
        if ((u32) var_r6 < 7U) {
            goto loop_1;
        }
    }
    return var_r5;
}
