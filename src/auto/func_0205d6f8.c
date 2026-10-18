/* Reconstructed from USA ARM9 at 0x0205d6f8 (52 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

/* WIP reconstruction from USA ARM9 at 0x0205d6f8 (52 bytes).
 * Inferred types and declarations need review; not integrated into the ROM.
 * compiler: 2.0/sp1p5; extra flags: (none)
 * See batch.json and tools/check_wip.py for byte-comparison results.
 */
#include "m2c.h"

M2C_UNK func_0205d378(M2C_UNK **, s32);             /* extern */
M2C_UNK func_0205df00(M2C_UNK **, M2C_UNK);         /* extern */
extern M2C_UNK data_020fe5dc;

M2C_UNK **func_0205d6f8(M2C_UNK **arg0, M2C_UNK arg1) {
    func_0205d378(arg0, (M2C_UNK **) ((s8 *) arg0 + 0x14));
    *arg0 = &data_020fe5dc;
    func_0205df00((M2C_UNK **) ((s8 *) arg0 + 0x14), arg1);
    return arg0;
}
