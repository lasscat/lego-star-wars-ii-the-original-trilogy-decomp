#include "m2c.h"

extern M2C_UNK data_0210daf0;

void func_020b5ba8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r4;

    if (M2C_FIELD(&data_0210daf0, M2C_UNK(**)(), 4) == NULL) {
        return;
    }
    temp_r4 = M2C_FIELD(&data_0210daf0, s32 *, 0);
    M2C_FIELD(&data_0210daf0, M2C_UNK(**)(), 4)(arg0, arg1, arg2);
    M2C_FIELD(&data_0210daf0, s32 *, 0) = temp_r4;
}
