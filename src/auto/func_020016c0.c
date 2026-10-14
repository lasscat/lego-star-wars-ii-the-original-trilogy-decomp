#include "m2c.h"

extern s32 data_027e02a0;
extern s32 data_027e02a4;
extern M2C_UNK data_027e02ac;

void func_020016c0(void) {
    s32 temp_r3;

    temp_r3       = data_027e02a0 - 1;
    data_027e02a0 = temp_r3;
    data_027e02a4 = *((M2C_UNK *) ((s8 *) &data_027e02ac + (temp_r3 * 4)));
}
