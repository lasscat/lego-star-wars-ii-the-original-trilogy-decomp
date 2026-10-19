#include "m2c.h"

void func_0205e3f4(void *arg0, s32 arg1, s32 arg2) {
    s32 var_r3;
    u32 temp_lr;
    u32 var_r4;
    void *var_r5;
    void *var_r6;

    temp_lr = arg2 - 1;
    var_r5  = M2C_FIELD((arg0 + (arg1 * 4)), void **, 0x24);
    var_r4  = 0;
    if (temp_lr != 0) {
        var_r6 = var_r5;
        do {
            var_r3 = var_r5 + ((var_r4 + 1) * 0x18);
            if (var_r3 != 0) {
                var_r3 += 4;
            }
            var_r4 += 1;
            M2C_FIELD(var_r6, s32 *, 8) = var_r3;
            var_r6 += 0x18;
        } while (var_r4 < temp_lr);
    }
    M2C_FIELD(((arg2 * 0x18) + (s32) var_r5), void **, -0x10) = (void *) M2C_FIELD(arg0, void **, 0x18);
    if (var_r5 != NULL) {
        var_r5 += 4;
    }
    M2C_FIELD(arg0, void **, 0x18) = var_r5;
    M2C_FIELD(arg0, u16 *, 0x1E)   = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + arg2);
}
