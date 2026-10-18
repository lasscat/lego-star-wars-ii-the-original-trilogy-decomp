/* Reconstructed from USA ARM9 at 0x02062d7c (112 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* WIP reconstruction from USA ARM9 at 0x02062d7c (112 bytes).
 * Inferred types and declarations need review; not integrated into the ROM.
 * compiler: 2.0/sp1p5; extra flags: (none)
 * See batch.json and tools/check_wip.py for byte-comparison results.
 */
#include "m2c.h"

extern M2C_UNK data_02104344;

s32 func_02062d7c(void) {
    s32 temp_r1;
    s32 temp_r2_2;
    s32 temp_r2_3;
    u32 *temp_ip;
    u32 temp_r0;
    u32 temp_r2;

    temp_r1                             = M2C_FIELD(&data_02104344, s32 *, 4) - 1;
    M2C_FIELD(&data_02104344, s32 *, 4) = temp_r1;
    if (temp_r1 < 0) {
        M2C_FIELD(&data_02104344, s32 *, 4)     = 0x26F;
        M2C_FIELD(&data_02104344, u32 **, 0x14) = (u32 *) (M2C_FIELD(&data_02104344, s32 *, 0x10) + 4);
    }
    temp_ip                                 = M2C_FIELD(&data_02104344, u32 **, 0x14);
    M2C_FIELD(&data_02104344, u32 **, 0x14) = (u32 *) ((s8 *) temp_ip + 4);
    temp_r2                                 = *temp_ip;
    temp_r2_2                               = temp_r2 ^ (temp_r2 >> 0xB);
    temp_r2_3                               = temp_r2_2 ^ (0x9D2C5680 & (temp_r2_2 << 7));
    temp_r0                                 = temp_r2_3 ^ (0xEFC60000 & (temp_r2_3 << 0xF));
    return temp_r0 ^ (temp_r0 >> 0x12);
}
