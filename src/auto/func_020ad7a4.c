/* Reconstructed from USA ARM9 at 0x020ad7a4 (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020ad528(M2C_UNK *, s32);              /* extern */
extern M2C_UNK data_020ffd20;
extern M2C_UNK data_020fffb0;
extern M2C_UNK data_020fffb8;
extern M2C_UNK data_0210b320;

void func_020ad7a4(s32 arg0) {
    s32 t;

    func_020ad528(&data_020fffb0, *((M2C_UNK *) ((s8 *) &data_020ffd20 + (M2C_FIELD(&data_0210b320, s32 *, 0x20) * 4))));
    t                                      = *((M2C_UNK *) ((s8 *) &data_020ffd20 + (arg0 * 4)));
    M2C_FIELD(&data_0210b320, s32 *, 0x20) = arg0;
    func_020ad528(&data_020fffb8, t);
}
