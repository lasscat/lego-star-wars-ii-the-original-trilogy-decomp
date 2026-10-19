/* Reconstructed from USA ARM9 at 0x02065798 (168 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020e0db0(void *);                          /* extern */
M2C_UNK strcpy(u8 *, void *);                /* extern */
extern M2C_UNK data_021046fc;

s32 func_02065798(s32 arg0, u8 *arg1, u8 *arg2) {
    s32 var_r5;
    u8 *var_r6;
    u8 *var_r7;
    u8 var_r0;
    void *temp_r8;

    var_r7 = arg1;
    var_r0 = *var_r7;
    var_r6 = arg2;
    var_r5 = 0;
    if (var_r0 != 0) {
        do {
            if (var_r0 == 0x40) {
                strcpy(var_r6, (s8 *) &data_021046fc + ((M2C_FIELD(var_r7, u8 *, 1) - 0x31) << 6));
                temp_r8 = (s8 *) &data_021046fc + ((M2C_FIELD(var_r7, u8 *, 1) - 0x31) << 6);
                var_r5 += func_020e0db0(temp_r8);
                var_r6 = &var_r6[func_020e0db0(temp_r8)];
                var_r7 += 2;
            } else {
                *var_r6 = var_r0;
                var_r5 += 1;
                if ((u32) M2C_FIELD(var_r7, u8 *, 0) >= 0xF0U) {
                    var_r7 += 1;
                    var_r6 += 1;
                    *var_r6 = *var_r7;
                }
                var_r7 += 1;
                var_r6 += 1;
            }
            var_r0 = *var_r7;
        } while (var_r0 != 0);
    }
    *var_r6 = 0;
    return var_r5;
}
