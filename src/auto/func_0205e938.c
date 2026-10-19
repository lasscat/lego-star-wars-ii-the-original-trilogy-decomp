/* Reconstructed from USA ARM9 at 0x0205e938 (76 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

M2C_UNK func_0205e984(void *, s32, s32, M2C_UNK);   /* extern */

void func_0205e938(void *arg0, s32 arg1, u32 arg2, M2C_UNK arg3) {
    s32 var_r8;
    u32 var_r4;
    s32 var_r5;

    var_r5 = M2C_FIELD(arg0, u16 *, 6);
    var_r8 = arg1;
    var_r4 = 0;
    if (arg2 == 0) {
        return;
    }
    do {
        func_0205e984(arg0, var_r8, var_r5, arg3);
        var_r4 += 1;
        var_r5 += 1;
        var_r8 += 0xC;
    } while (var_r4 < arg2);
}
