#include "m2c.h"

s32 func_020d8968(u16);                             /* extern */
extern M2C_UNK data_0210da80;

s32 func_020b006c(void) {
    u16 var_r6;

    if (M2C_FIELD(&data_0210da80, u16 *, 0xA) == 0) {
        return 0;
    }
    var_r6 = 1;
loop_3:
    if ((M2C_FIELD(&data_0210da80, u16 *, 0xA) & (1 << var_r6)) && (func_020d8968(var_r6) == 0)) {
        return 0;
    }
    var_r6 += 1;
    if ((u32) var_r6 >= 0x10U) {
        return 1;
    }
    goto loop_3;
}
