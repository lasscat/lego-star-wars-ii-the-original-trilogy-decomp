/* Reconstructed from USA ARM9 at 0x020b87f8 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_020b87f8(volatile u8 *arg0, u32 arg1, u32 arg2) {
    u8 temp_r2;
    u32 temp_r3;

    if (!(arg1 & 0xF0)) {
        temp_r2 = *arg0;
        if ((u32) temp_r2 > arg1) {
            *arg0 = temp_r2 - arg1;
        } else {
            *arg0 = 0;
        }
        return;
    }
    if (arg1 & 0xF) {
        return;
    }
    temp_r3 = *arg0 + ((s32) arg1 >> 4);
    *arg0   = temp_r3;
    if ((temp_r3 & 0xFF) > arg2) {
        *arg0 = (u8) arg2;
    }
}
