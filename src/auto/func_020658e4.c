#include "m2c.h"

s32 func_02065840(void *, u8 *);                 /* extern */
s32 func_02066434(void *, s32, s32);             /* extern */
extern u8 data_021046fc[];

u8 *func_020658e4(void *arg0, u8 *arg1, s32 arg2) {
    u8 *var_r5 = 0;
    s32 var_r6 = 0;
    u8 var_r2;

    while ((var_r2 = *arg1) != 0 && var_r6 <= arg2) {
        if (var_r2 == 0xA) {
            var_r5 = arg1;
            break;
        }
        if (var_r2 == 0x40) {
            arg1++;
            var_r6 += func_02065840(arg0, (u8 *) ((s8 *) &data_021046fc + ((*arg1 - 0x31) << 6)));
        } else {
            if (var_r2 == 0x20 || var_r2 == 0x2D) {
                var_r5 = arg1;
            }
            var_r6 += func_02066434(arg0, M2C_FIELD(arg0, s32 *, 4), var_r2);
        }
        arg1++;
    }
    if (var_r2 == 0 && var_r6 <= arg2) {
        var_r5 = arg1;
    }
    return var_r5;
}
