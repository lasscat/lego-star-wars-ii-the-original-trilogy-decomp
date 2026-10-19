/* Reconstructed from USA ARM9 at 0x020508b4 (68 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02067080(s32, u8, u8);                     /* extern */
extern M2C_UNK data_0210930c;

s32 func_020508b4(void *arg0) {
    s32 var_r2;
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0);
    if (!((temp_r1 != 0xFF) && (M2C_FIELD(arg0, u8 *, 1) != 0))) {
        var_r2 = 0;
    } else {
        var_r2 = 1;
    }
    if (var_r2 == 0) {
        return 0;
    }
    return func_02067080(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), s32 *, 0x38C), temp_r1, M2C_FIELD(arg0, u8 *, 1));
}
