#include "m2c.h"

void *func_0205dcf8(void *, void *, M2C_UNK);       /* extern */

s32 func_0205dc90(void *arg0, void *arg1, s32 arg2) {
    s32 var_r0;
    void *var_r1;

    var_r1 = arg1;
    if (var_r1 == NULL) {
        return 0;
    }
    if (var_r1 != NULL) {
        var_r1 -= 4;
    }
    var_r0 = M2C_FIELD(var_r1, s32 *, 0x10);
    if (var_r0 == 0) {
        var_r0 = M2C_FIELD(func_0205dcf8(arg0, var_r1, 2), s32 *, 0xC);
        if (var_r0 != 0) {
            var_r0 -= 4;
        }
    }
    if ((arg2 != 0) && (var_r0 == 0)) {
        var_r0 = M2C_FIELD(arg0, s32 *, 8);
        if (var_r0 != 0) {
            var_r0 -= 4;
        }
    }
    if (var_r0 != 0) {
        var_r0 += 4;
    }
    return var_r0;
}
