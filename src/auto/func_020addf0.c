/* Reconstructed from USA ARM9 at 0x020addf0 (116 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_020ce868(s32);                         /* extern */
extern M2C_UNK data_0210b320;

s32 func_020addf0(s32 arg0) {
    s32 var_r6;

    var_r6 = M2C_FIELD(&data_0210b320, volatile s32 *, 0x14);
    while ((M2C_FIELD(&data_0210b320, volatile s32 *, 0x48) != arg0) &&
           (M2C_FIELD(&data_0210b320, volatile s32 *, 0x30) == 0) && (var_r6 > 0)) {
        func_020ce868(0x101D0);
        var_r6 -= 1;
    }
    if ((M2C_FIELD(&data_0210b320, volatile s32 *, 0x30) != 0) || (var_r6 == 0)) {
        return 0;
    }
    return 1;
}
