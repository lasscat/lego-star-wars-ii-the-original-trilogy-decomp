/* Reconstructed from USA ARM9 at 0x020aca80 (80 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020acad0(M2C_UNK, M2C_UNK);            /* extern */
extern u32 data_0210a0ec[];

void func_020aca80(M2C_UNK arg0) {
    s32 temp_lr;
    u8 var_r4;

    var_r4 = 0;
    do {
        temp_lr               = var_r4 * 0xA;
        data_0210a0ec[var_r4] = temp_lr | ((temp_lr + 2) << 8) | ((temp_lr + 4) << 0x10) | ((temp_lr + 8) << 0x18);
        var_r4 += 1;
    } while (var_r4 < 8U);
    func_020acad0(arg0, 0);
}
