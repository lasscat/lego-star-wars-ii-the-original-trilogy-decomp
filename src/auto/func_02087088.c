/* Reconstructed from USA ARM9 at 0x02087088 (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_02104d84;
extern M2C_UNK data_0210930c;

void func_02087088(void) {
    u32 var_r3;
    void *temp_r1;
    void **p;

    p                                     = (void **) &data_0210930c;
    var_r3                                = 0;
    M2C_FIELD(&data_02104d84, s32 *, 0xC) = (s32) ((M2C_FIELD(&data_02104d84, s32 *, 0xC) & ~1) | 1);
    do {
        temp_r1 = p[0x13 + var_r3];
        var_r3 += 1;
        if (temp_r1 != NULL) {
            M2C_FIELD(temp_r1, s8 *, 0x5D6) = 1;
        }
    } while (var_r3 < 4U);
}
