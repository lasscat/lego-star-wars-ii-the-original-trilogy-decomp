/* Reconstructed from USA ARM9 at 0x0203aea4 (60 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_020ff9b4;

void func_0203aea4(void *arg0) {
    void *temp_r0;
    void *temp_r2;

    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    temp_r0 = M2C_FIELD(arg0, void **, 4);
    temp_r2 = temp_r0 + 0x60;
    if (temp_r2 == &data_020ff9b4) {
        return;
    }
    M2C_FIELD(temp_r2, s32 *, 0) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
    M2C_FIELD(temp_r2, s32 *, 4) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
    M2C_FIELD(temp_r2, s32 *, 8) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
}
