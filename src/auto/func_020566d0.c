/* Reconstructed from USA ARM9 at 0x020566d0 (116 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020922f4(M2C_UNK *, s8, u8);           /* extern */
extern M2C_UNK data_0210930c;

void func_020566d0(s32 arg0, u8 *arg1) {
    s8 var_ip;
    s8 var_r1;

    var_r1 = -1;
    var_ip = 0;
loop_1:
    if (*arg1 == M2C_FIELD(((s32 *) &data_0210930c)[var_ip + 0x13], u8 *, 0x6BB)) {
        var_r1 = var_ip;
    } else {
        var_ip += 1;
        if ((s32) var_ip < 4) {
            goto loop_1;
        }
    }
    if (((s8) (var_ip - 1) != var_r1) && (var_r1 != -1)) {
        func_020922f4(&data_0210930c, var_r1, arg1[1]);
    }
}
