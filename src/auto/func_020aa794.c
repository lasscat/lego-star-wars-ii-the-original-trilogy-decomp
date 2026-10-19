/* Reconstructed from USA ARM9 at 0x020aa794 (44 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_020aa794(void *arg0, void *arg1) {
    void *temp_r0 = M2C_FIELD(arg0, void **, 0x1D0);
    void *temp_r2 = temp_r0 + 0xB0;
    if (arg1 == temp_r2) {
        return;
    }
    M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(temp_r2, s32 *, 0);
    M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(temp_r2, s32 *, 4);
    M2C_FIELD(arg1, s32 *, 8) = (s32) M2C_FIELD(temp_r2, s32 *, 8);
}
