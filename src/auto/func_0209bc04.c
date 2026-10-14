#include "m2c.h"

s16 func_0209bc04(void *arg0, s32 arg1) {
    s16 var_r3;
    u32 temp_r2;
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;

    temp_r2 = M2C_FIELD(arg0, u32 *, 0x34);
    var_r3  = 0;
    switch (temp_r2) {
        default:
            break;
        case 0:
            temp_r0 = arg0 + (arg1 * 2);
            var_r3  = M2C_FIELD(temp_r0, s16 *, 0x1C) - M2C_FIELD(temp_r0, s16 *, 0x24);
            break;
        case 1:
            var_r3 = M2C_FIELD((arg0 + (arg1 * 2)), s16 *, 0x14);
            break;
        case 2:
            var_r3 = M2C_FIELD((arg0 + (arg1 * 2)), s16 *, 0x1C);
            break;
        case 3:
            temp_r0_2 = arg0 + (arg1 * 2);
            var_r3 =
                (M2C_FIELD(temp_r0_2, s16 *, 0x14) + M2C_FIELD(temp_r0_2, s16 *, 0x1C)) - M2C_FIELD(temp_r0_2, s16 *, 0x24);
            break;
        case 4:
            temp_r0_3 = arg0 + (arg1 * 2);
            var_r3    = M2C_FIELD(temp_r0_3, s16 *, 0x14) - M2C_FIELD(temp_r0_3, s16 *, 0x24);
            break;
    }
    return var_r3;
}
