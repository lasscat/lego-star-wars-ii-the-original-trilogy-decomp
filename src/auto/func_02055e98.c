#include "m2c.h"

extern M2C_UNK data_020ed928;

void func_02055e98(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_UNK (*temp_r3)(M2C_UNK, M2C_UNK);

    temp_r3 = *((M2C_UNK *)((s8 *)&data_020ed928 + (arg0 * 4)));
    if (temp_r3 == NULL) {
        return;
    }
    temp_r3(arg1, arg2);
}
