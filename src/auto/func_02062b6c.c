/* Reconstructed from USA ARM9 at 0x02062b6c (72 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_02104344;

void func_02062b6c(s32 arg0) {
    s32 *ip;
    s32 var_r3;
    s32 var_r2;

    ip                                  = M2C_FIELD(&data_02104344, s32 **, 0x10);
    M2C_FIELD(&data_02104344, s32 *, 8) = 0;
    var_r2                              = 0x270;
    var_r3                              = arg0 | 1;
    *ip++                               = var_r3;
    var_r2 -= 1;
    do {
        var_r3 = var_r3 * 0x10DCD;
        *ip++  = var_r3;
        var_r2 -= 1;
    } while (var_r2 > 0);
}
