/* Reconstructed from USA ARM9 at 0x020609ac (128 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_02103374;
extern M2C_UNK data_02103a74;
extern M2C_UNK data_02103a94;

void func_020609ac(u16 arg0, s32 arg1) {
    u8 *temp_r2;
    u16 var_r0;

    var_r0                                                             = arg0;
    *((volatile u8 *) ((s8 *) &data_02103a74 + arg1 * 0x724) + var_r0) = 0;
    if (var_r0 != (*((volatile u8 *) ((s8 *) &data_02103a94 + arg1 * 0x724)) - 1)) {
        return;
    }
    temp_r2 = (u8 *) ((s8 *) &data_02103374 + arg1 * 0x724);
    while ((M2C_FIELD(temp_r2, volatile u8 *, 0x720) != 0) && (M2C_FIELD((temp_r2 + var_r0), volatile u8 *, 0x700) == 0)) {
        M2C_FIELD(temp_r2, volatile u8 *, 0x720) = (u8) (M2C_FIELD(temp_r2, volatile u8 *, 0x720) - 1);
        var_r0                                   = var_r0 - 1;
    }
}
