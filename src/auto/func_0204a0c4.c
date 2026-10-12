#include "m2c.h"

M2C_UNK func_020aa7c0(s32, s32);                    /* extern */
s32 func_020aaeb4();                                /* extern */

void *func_0204a0c4(void *arg0) {
    s32 temp_r0;
    s32 temp_r5;
    s32 var_r2;
    void *temp_r1;
    void *var_r3;

    temp_r5 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r5 != 0) {
        func_020aa7c0(func_020aaeb4(), temp_r5);
    }
    var_r2 = 0;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x68) > 0) {
        var_r3 = arg0;
        do {
            temp_r1 = M2C_FIELD(var_r3, void **, 8);
            var_r2 += 1;
            temp_r0 = M2C_FIELD(temp_r1, s32 *, 8);
            var_r3 += 0xC;
            M2C_FIELD(temp_r1, s32 *, 8) = (s32) (temp_r0 | 2);
        } while (var_r2 < (s32) M2C_FIELD(arg0, u8 *, 0x68));
    }
    return arg0;
}
