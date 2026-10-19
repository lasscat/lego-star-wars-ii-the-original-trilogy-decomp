#include "m2c.h"

s32 func_02053b14(s32);                             /* extern */
M2C_UNK MI_Copy64B(void *, s32);                 /* extern */

void func_0206cdf4(void *arg0) {
    s32 var_r4;
    s32 var_r5;
    void *var_r6;

    var_r4 = func_02053b14(arg0 + 0x54);
    var_r5 = 0;
    if ((s32) M2C_FIELD(arg0, s32 *, 0x64) <= 0) {
        return;
    }
    var_r6 = arg0 + 0x80;
    do {
        MI_Copy64B(var_r6, var_r4);
        var_r5 += 1;
        var_r4 += 0x40;
        var_r6 += 0x40;
    } while (var_r5 < (s32) M2C_FIELD(arg0, s32 *, 0x64));
}
