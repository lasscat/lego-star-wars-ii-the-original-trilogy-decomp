/* Reconstructed from USA ARM9 at 0x0208c588 (100 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02053b14(M2C_UNK);                         /* extern */
M2C_UNK func_020cedd8(M2C_UNK, s32, M2C_UNK, s32, s32, s32); /* extern */

void func_0208c588(s32 arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_r4;
    void *temp_r1;

    temp_r1 = arg0 + (arg1 * 4);
    if (M2C_FIELD(temp_r1, u8 *, 0xC) == 0) {
        return;
    }
    M2C_FIELD(temp_r1, u8 *, 0xC) = 0U;
    temp_r4                       = ((u32) M2C_FIELD(temp_r1, u8 *, 0xF) >> 3) - 2;
    func_020cedd8(1, func_02053b14(arg2) + (temp_r4 << 6), 0x40, (0x20 - temp_r4) << 6, 0, 0);
}
