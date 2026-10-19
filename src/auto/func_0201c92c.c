#include "m2c.h"

void *func_0205ab58(u16);                           /* extern */
s32 func_020ab65c(M2C_UNK, s32);                    /* extern */
s32 func_020ab704(M2C_UNK, s32);                    /* extern */
M2C_UNK func_020ab770(M2C_UNK, s32, void *, s32, s32); /* extern */
M2C_UNK func_020ab828(M2C_UNK, s32, void *, s32, s32, s32); /* extern */

void func_0201c92c(u16 *arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    void *var_r5;
    s32 var_r6;

    if (!(*arg0 & (1 << arg2))) {
        return;
    }
    var_r5 = func_0205ab58(M2C_FIELD((arg0 + arg2), u16 *, 2));
    var_r6 = func_020ab704(arg1, arg2);
    if (M2C_FIELD(var_r5, s32 *, 0) == 0x41475454) {
        var_r6 = M2C_FIELD(var_r5, s32 *, 4);
        var_r5 += 8;
    }
    func_020ab770(arg1, arg2, var_r5 + var_r6, func_020ab65c(arg1, arg2), arg3);
    func_020ab828(arg1, arg2, var_r5, var_r6, 0, arg3);
    *arg0 &= ~(1 << arg2);
}
