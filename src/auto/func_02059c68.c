/* Reconstructed from USA ARM9 at 0x02059c68 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);               /* extern */

void func_02059c68(M2C_UNK arg0, void *arg1) {
    s32 temp_r1;
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    if (!(M2C_FIELD(temp_r0, u16 *, 0xC) & 3)) {
        return;
    }
    if (M2C_FIELD(arg1, u8 *, 2) != 0) {
        M2C_FIELD(temp_r0, s32 *, 8) = M2C_FIELD(temp_r0, s32 *, 8) | 0x10000000;
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 8) = M2C_FIELD(temp_r0, s32 *, 8) & ~0x10000000;
}
