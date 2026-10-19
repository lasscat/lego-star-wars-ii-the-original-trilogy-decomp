/* Reconstructed from USA ARM9 at 0x02066238 (160 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02066238(void *arg0, u8 *arg1) {
    u8 temp_r2;
    u8 *var_ip_2;
    u8 temp_r3;
    u8 *var_ip;
    u8 temp_r3_2;
    u8 temp_r2_2;
    s32 var_lr;
    s32 var_lr_2;
    s32 var_r5;
    s32 var_r4;

    if (M2C_FIELD(arg0, s32 *, 0x2C) == 1) {
        var_lr = 8;
        do {
            var_r4 = 4;
            var_ip = arg1 + 7;
            do {
                temp_r2 = *arg1;
                var_r4 -= 1;
                *arg1 = *var_ip;
                arg1 += 1;
                *var_ip = temp_r2;
                var_ip -= 1;
            } while (var_r4 > 0);
            var_lr -= 1;
            arg1 += 4;
        } while (var_lr > 0);
        return;
    }
    var_lr_2 = 8;
    do {
        var_r5   = 2;
        var_ip_2 = arg1 + 3;
        do {
            temp_r2_2 = *var_ip_2;
            temp_r3_2 = *arg1;
            var_r5 -= 1;
            *arg1 = (temp_r2_2 * 0x10) | ((s32) temp_r2_2 >> 4);
            arg1 += 1;
            *var_ip_2 = (temp_r3_2 * 0x10) | ((s32) temp_r3_2 >> 4);
            var_ip_2 -= 1;
        } while (var_r5 > 0);
        var_lr_2 -= 1;
        arg1 += 2;
    } while (var_lr_2 > 0);
}
