/* Reconstructed from USA ARM9 at 0x020c29ac (88 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK MIi_CpuClear32(M2C_UNK, u32, s32);           /* extern */

u32 func_020c29ac(void *arg0, s32 arg1, s32 arg2) {
    u32 temp_r3;
    u32 temp_r5;
    u32 diff;

    temp_r3 = M2C_FIELD(arg0, u32 *, 4);
    temp_r5 = ~(arg2 - 1) & (temp_r3 - arg1);
    if (temp_r5 < (u32) M2C_FIELD(arg0, u32 *, 0)) {
        return 0U;
    }
    diff = temp_r3 - temp_r5;
    if ((u8) M2C_FIELD(arg0, s32 *, -4) & 1) {
        MIi_CpuClear32(0, temp_r5, diff);
    }
    M2C_FIELD(arg0, u32 *, 4) = temp_r5;
    return temp_r5;
}
