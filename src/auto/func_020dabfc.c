/* Reconstructed from USA ARM9 at 0x020dabfc (112 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020cf1b8(M2C_UNK, s32, s32);           /* extern */

void func_020dabfc(void *arg0, M2C_UNK arg1, s32 arg2, s16 arg3) {
    s32 var_r2;
    u8 var_r7;

    var_r7 = 1;
    func_020cf1b8(arg1, arg0 + 0x35E, 0x14A);
    var_r2 = 0;
    do {
        if (arg2 & (2 << var_r2)) {
            var_r7 += 1;
        }
        var_r2 += 1;
    } while (var_r2 < 0xF);
    M2C_FIELD(arg0, u8 *, 0x358)  = var_r7;
    M2C_FIELD(arg0, s16 *, 0x35A) = (s16) (arg2 | 1);
    M2C_FIELD(arg0, s16 *, 0x35C) = arg3;
    M2C_FIELD(arg0, u8 *, 0x4B4)  = (u8) (M2C_FIELD(arg0, u8 *, 0x4B4) + 1);
}
