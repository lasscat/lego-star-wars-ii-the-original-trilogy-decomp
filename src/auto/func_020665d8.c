/* Reconstructed from USA ARM9 at 0x020665d8 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_02055b24(s32, s32, s32, s32, s32);      /* extern */
M2C_UNK func_02055ba4(s32, s32, s32, s32, s32);      /* extern */

void func_020665d8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r1;

    temp_r1 = arg1 * 3;
    if (arg3 != 0) {
        func_02055ba4(0x8F9, temp_r1 << 1, arg2 + 1, 3, arg0);
        return;
    }
    func_02055b24(0x8F9, temp_r1 << 1, arg2 + 1, 3, arg0);
}
