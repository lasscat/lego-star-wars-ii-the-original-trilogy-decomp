#include "m2c.h"

M2C_UNK func_020ba9b0(s32);                         /* extern */
extern M2C_UNK data_0210dd98;
extern M2C_UNK data_0210e0b4;

void func_020ba948(s32 arg0) {
    M2C_UNK *var_r4;
    s32 var_r3;
    u8 temp_r2;

    if (arg0 == 0xFFFF) {
        return;
    }
    var_r4 = &data_0210e0b4;
    var_r3 = 0x1F;
loop_3:
    if (M2C_FIELD(var_r4, u16 *, 0) == arg0) {
        temp_r2 = M2C_FIELD(var_r4, u8 *, 2);
        if (temp_r2 != 0xFF) {
            func_020ba9b0((temp_r2 * 0x1C) + (s32) &data_0210dd98);
            M2C_FIELD(var_r4, u8 *, 2) = 0xFFU;
            return;
        }
    }
    var_r4 = (M2C_UNK *) ((s8 *) var_r4 - 4);
    var_r3 -= 1;
    if (var_r3 < 0) {
        return;
    }
    goto loop_3;
}
