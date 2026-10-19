/* Reconstructed from USA ARM9 at 0x02062d10 (108 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* WIP reconstruction from USA ARM9 at 0x02062d10 (108 bytes).
 * Inferred types and declarations need review; not integrated into the ROM.
 * compiler: 2.0/sp1p5; extra flags: (none)
 * See batch.json and tools/check_wip.py for byte-comparison results.
 */
#include "m2c.h"

s8 func_02062bb4();                                 /* extern */
extern M2C_UNK data_02104344;

void func_02062d10(void) {
    s32 temp_r0;
    s32 temp_r3_3;
    s32 temp_r3_4;
    u32 *temp_r3;
    u32 temp_r0_2;
    u32 temp_r3_2;

    temp_r0                             = M2C_FIELD(&data_02104344, s32 *, 8) - 1;
    M2C_FIELD(&data_02104344, s32 *, 8) = temp_r0;
    if (temp_r0 < 0) {
        M2C_FIELD(&data_02104344, s8 *, 0) = func_02062bb4();
        return;
    }
    temp_r3                                = M2C_FIELD(&data_02104344, u32 **, 0xC);
    M2C_FIELD(&data_02104344, u32 **, 0xC) = (u32 *) ((s8 *) temp_r3 + 4);
    temp_r3_2                              = *temp_r3;
    temp_r3_3                              = temp_r3_2 ^ (temp_r3_2 >> 0xB);
    temp_r3_4                              = temp_r3_3 ^ (0x9D2C5680 & (temp_r3_3 << 7));
    temp_r0_2                              = temp_r3_4 ^ (0xEFC60000 & (temp_r3_4 << 0xF));
    M2C_FIELD(&data_02104344, s8 *, 0)     = (s8) (temp_r0_2 ^ (temp_r0_2 >> 0x12));
}
