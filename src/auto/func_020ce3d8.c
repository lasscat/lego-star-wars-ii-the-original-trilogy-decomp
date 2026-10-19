/* Reconstructed from USA ARM9 at 0x020ce3d8 (128 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_020cd8c0();                                /* extern */
extern M2C_UNK data_021156cc;
extern M2C_UNK func_020ce458;

void func_020ce3d8(void) {
    void *base;
    u32 temp_r1;

    temp_r1 = *(u32 *) 0x027FFD9C;
    if ((temp_r1 >= 0x02600000U) && (temp_r1 < 0x02800000U)) {
        M2C_FIELD(&data_021156cc, u32 *, 8) = temp_r1;
    } else {
        M2C_FIELD(&data_021156cc, u32 *, 8) = 0U;
    }
    if ((M2C_FIELD(&data_021156cc, u32 *, 8) == 0) && !(func_020cd8c0() & 0x40000000)) {
        *(M2C_UNK *) 0x027FFD9C            = (u32) &func_020ce458;
        base                               = (void *) 0x027E3000;
        M2C_FIELD(base, M2C_UNK **, 0xFDC) = &func_020ce458;
    }
    M2C_FIELD(&data_021156cc, s32 *, 0) = 0;
}
