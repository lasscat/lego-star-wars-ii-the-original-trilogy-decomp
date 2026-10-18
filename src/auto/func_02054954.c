/* Reconstructed from USA ARM9 at 0x02054954 (144 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_02054da8();                                /* extern */
M2C_UNK func_02055b64(s32, s32, s32, s32);          /* extern */
M2C_UNK func_02055d58(s32, s32, s32, s32, s32, s32); /* extern */

void func_02054954(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 var_r4;
    u32 var_r5;
    u32 var_r6;

    var_r5 = arg6;
    var_r6 = arg5;
    var_r4 = arg1 - var_r5;
    if (var_r4 >= arg2) {
        var_r4 = arg2;
    }
    if (var_r4 <= 0) {
        return;
    }
    if (arg3 != 0) {
        func_02055d58(func_02054da8() + (var_r5 * 2), arg4, var_r6, var_r4, 0, arg7);
        return;
    }
    if (var_r6 == 0) {
        var_r5 += 1;
        var_r4 -= 1;
        var_r6 = 1;
    }
    func_02055b64(func_02054da8() + (var_r5 * 2), var_r6, var_r4, arg7);
}
