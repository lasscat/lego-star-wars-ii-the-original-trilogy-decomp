/* Reconstructed from USA ARM9 at 0x02068154 (56 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* WIP reconstruction from USA ARM9 at 0x02068154 (56 bytes).
 * Inferred types and declarations need review; not integrated into the ROM.
 * compiler: 2.0/sp1p5; extra flags: (none)
 * See batch.json and tools/check_wip.py for byte-comparison results.
 */
#include "m2c.h"

s32 func_02062ab4();                        /* extern */
extern M2C_UNK data_020ee044;
extern M2C_UNK data_020ee046;

void func_02068154(void *arg0) {
    s32 temp_r3;

    temp_r3 = M2C_FIELD(arg0, u8 *, 0) * 0x1A;
    M2C_FIELD(arg0, s32 *, 4) =
        func_02062ab4(*(u16 *) ((s8 *) &data_020ee044 + temp_r3), *(u16 *) ((s8 *) &data_020ee046 + temp_r3));
}
