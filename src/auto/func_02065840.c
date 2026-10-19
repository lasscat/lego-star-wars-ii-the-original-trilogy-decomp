#include "m2c.h"

s32 func_02066434(void *, s32, u16);                /* extern */
extern M2C_UNK data_021046fc;

s32 func_02065840(void *arg0, u8 *arg1) {
    s32 var_r1;
    s32 var_r5;
    u8 *var_r6;
    u16 var_r2;

    var_r6 = arg1;
    var_r2 = *var_r6;
    var_r5 = 0;
    if (var_r2 != 0) {
        do {
            if (var_r2 == 0x40) {
                var_r6 += 1;
                var_r5 += func_02065840(arg0, (u8 *) ((s8 *) &data_021046fc + ((*var_r6 - 0x31) << 6)));
            } else {
                if ((u32) var_r2 < 0xF0U) {
                    var_r1 = M2C_FIELD(arg0, s32 *, 4);
                } else {
                    var_r6 += 1;
                    var_r1 = M2C_FIELD(arg0, s32 *, 8);
                    var_r2 = (u16) (*var_r6 * 0x101);
                }
                var_r5 += func_02066434(arg0, var_r1, var_r2);
            }
            var_r6 += 1;
            var_r2 = *var_r6;
        } while (var_r2 != 0);
    }
    return var_r5;
}
