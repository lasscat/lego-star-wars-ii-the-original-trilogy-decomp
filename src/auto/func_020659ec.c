#include "m2c.h"

s32 func_02065af8(void *, s32, s32, s32, s32, u8 **, s32, s32 *); /* extern */

s32 func_020659ec(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 **arg6, s32 arg7) {
    s32 sp10;
    s32 *sp10p;
    s32 var_r1;
    s32 var_r8;

    sp10p  = &sp10;
    sp10   = 0x7FFFFFFF;
    var_r1 = arg1;
    var_r8 = arg3;
    while ((**arg6 != 0) && (arg5 >= (s32) M2C_FIELD(arg0, s32 *, 0x18))) {
        var_r1 = func_02065af8(arg0, var_r1, arg2, var_r8, arg4, arg6, arg7, sp10p);
        var_r8 += M2C_FIELD(arg0, s32 *, 0x18);
        arg5 -= M2C_FIELD(arg0, s32 *, 0x18);
    }
    return var_r1;
}
