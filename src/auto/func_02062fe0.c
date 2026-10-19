/* Reconstructed from USA ARM9 at 0x02062fe0 (116 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* WIP reconstruction from USA ARM9 at 0x02062fe0 (116 bytes).
 * Inferred types and declarations need review; not integrated into the ROM.
 * compiler: 2.0/sp1p5; extra flags: (none)
 * See batch.json and tools/check_wip.py for byte-comparison results.
 */
#include "m2c.h"

M2C_UNK func_020631fc();                            /* extern */
M2C_UNK func_0206325c(s32);                         /* extern */
M2C_UNK func_020632b4(void *, M2C_UNK);             /* extern */
s32 func_02063444(s32);                             /* extern */
M2C_UNK func_02085d94(M2C_UNK *, void *);           /* extern */
extern M2C_UNK data_02104388;
extern M2C_UNK data_021043ac;
extern M2C_UNK data_02104d90;

s32 func_02062fe0(s32 arg0) {
    s32 temp_r4;

    func_020631fc();
    temp_r4 = arg0 * 0xC;
    func_02085d94(&data_02104d90, (M2C_UNK *) ((s8 *) &data_02104388 + temp_r4));
    *((M2C_UNK *) ((s8 *) &data_02104388 + temp_r4)) = 0xFDDB597D;
    func_020632b4((M2C_UNK *) ((s8 *) &data_02104388 + temp_r4), 0xC);
    func_0206325c(arg0);
    *((u8 *) ((s8 *) &data_021043ac + arg0)) = 0;
    if (func_02063444(arg0) != 0) {
        return 0;
    }
    return 2;
}
