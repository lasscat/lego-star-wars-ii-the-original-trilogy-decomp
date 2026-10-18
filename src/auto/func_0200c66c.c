/* Reconstructed from USA ARM9 at 0x0200c66c (104 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern u8 data_027e02bc;

void func_0200c66c(void *arg0) {
    u32 var_r4;
    u8 temp_ip;
    s32 var_r5;
    void *var_r0;

    var_r0 = arg0;
    var_r4 = 0;
    var_r5 = 0x18;
    do {
        if (M2C_FIELD(var_r0, u8 *, 0x3CD) == 1) {
            if ((s32) M2C_FIELD(var_r0, s8 *, 0x3CF) < 0) {
                M2C_FIELD(var_r0, s8 *, 0x3CC) = 0;
                goto block_6;
            }
            temp_ip                        = var_r5;
            M2C_FIELD(var_r0, s8 *, 0x3CE) = var_r5;
            var_r5 += 1;
            (&data_027e02bc)[M2C_FIELD(var_r0, s8 *, 0x3CF)] = temp_ip;
        }
        M2C_FIELD(var_r0, s8 *, 0x3CC) = 0;
    block_6:
        var_r4 += 1;
        var_r0 += 0x38;
    } while (var_r4 < 0xAU);
}
