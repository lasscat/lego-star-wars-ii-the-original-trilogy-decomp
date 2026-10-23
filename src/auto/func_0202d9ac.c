#include "m2c.h"

typedef struct {
    u16 v;
} S16;
typedef struct {
    s32 v;
} S32;

M2C_UNK func_0202c1a8(s32, s32);                       /* extern */
M2C_UNK func_02031f24(M2C_UNK, M2C_UNK, M2C_UNK, S32, s32, s32, S16); /* extern */
M2C_UNK func_0205e80c(u32, s32, s32);                 /* extern */

s32 func_0202d9ac(s32 arg0, M2C_UNK arg1, S32 arg2, ...) {
    s32 temp_r0;
    s32 var_r7;
    S16 sp8;

    temp_r0 = func_0205e80c(0x24, 1, 4);
    var_r7  = temp_r0;
    if (var_r7 != 0) {
        sp8.v  = 0;
        var_r7 = func_02031f24(temp_r0, arg0, arg1, arg2, 0, 1, sp8);
    }
    func_0202c1a8(arg0 + 0x5E0, var_r7);
    return var_r7;
}
