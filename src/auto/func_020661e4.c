/* Reconstructed from USA ARM9 at 0x020661e4 (84 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_020661e4(void *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 var_r0;
    s32 var_r0_2;

    if (M2C_FIELD(arg0, s32 *, 0x2C) == 1) {
        var_r0 = arg3 + (arg3 << 24);
        var_r0 = var_r0 + (arg3 << 16);
        arg3   = var_r0 + (arg3 << 8);
        var_r0 = arg2 << 4;
    } else {
        var_r0 = arg3 & 0xF;
        var_r0 = var_r0 + (var_r0 << 4);
        var_r0 = var_r0 + (var_r0 << 8);
        arg3   = var_r0 + (var_r0 << 16);
        var_r0 = arg2 << 3;
    }
    var_r0_2 = var_r0 - 1;
    if (var_r0 == 0) {
        return;
    }
    do {
        *arg1++ = arg3;
    } while (var_r0_2--);
}
