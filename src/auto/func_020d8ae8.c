#include "m2c.h"

extern void *data_0211e40c;

void func_020d8ae8(s32 arg0, s32 arg1, s32 arg2) {
    M2C_UNK (*temp_r3)(arg0, arg1, arg2);

    temp_r3 = M2C_FIELD(data_0211e40c, M2C_UNK (**)(), 0x14E4);
    if (temp_r3 == NULL) {
        return;
    }
    temp_r3(arg0, arg1, arg2);
}
