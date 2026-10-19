/* Reconstructed from USA ARM9 at 0x0204c120 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_020ff9b4;

void func_0204c120(void *arg0) {
    void *temp_r1;
    void *temp_r3;

    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    temp_r1                    = M2C_FIELD(arg0, void **, 4);
    temp_r3                    = temp_r1 + 0x60;
    if (temp_r3 != &data_020ff9b4) {
        M2C_FIELD(temp_r3, s32 *, 0) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
        M2C_FIELD(temp_r3, s32 *, 4) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
        M2C_FIELD(temp_r3, s32 *, 8) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x1AD) = 1;
}
