/* Reconstructed from USA ARM9 at 0x020c2950 (92 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020cf1d8(M2C_UNK, u32, s32);           /* extern */

s32 func_020c2950(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r5;
    u32 temp_r3;
    u32 temp_r6;
    u32 diff;

    temp_r3 = M2C_FIELD(arg0, u32 *, 0);
    temp_r0 = arg2 - 1;
    temp_r5 = ~temp_r0 & (temp_r0 + temp_r3);
    temp_r6 = arg1 + temp_r5;
    if (temp_r6 > (u32) M2C_FIELD(arg0, u32 *, 4)) {
        return 0;
    }
    diff = temp_r6 - temp_r3;
    if ((u8) M2C_FIELD(arg0, s32 *, -4) & 1) {
        func_020cf1d8(0, temp_r3, diff);
    }
    M2C_FIELD(arg0, u32 *, 0) = temp_r6;
    return temp_r5;
}
