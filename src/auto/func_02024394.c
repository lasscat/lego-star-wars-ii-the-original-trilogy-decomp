/* Reconstructed from USA ARM9 at 0x02024394 (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void func_02024394(void *arg0, void **arg1) {
    void *temp_r2;

    temp_r2 = *arg1;
    switch (M2C_FIELD(temp_r2, u16 *, 0xC)) {
        case 1:
            if (!(M2C_FIELD(temp_r2, s32 *, 0x1B8) & 0x02000000)) {
                return;
            }
            M2C_FIELD(arg0, void **, 0x218) = temp_r2;
            M2C_FIELD(arg0, s32 *, 0x220)   = M2C_FIELD(arg0, s32 *, 0x220) + 1;
            break;
        case 4:
            break;
    }
}
