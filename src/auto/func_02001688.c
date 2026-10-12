#include "m2c.h"

extern s32 data_027e02a0;
extern s32 data_027e02a4;
extern M2C_UNK data_027e02ac;

void func_02001688(s32 arg0) {
    s32 temp_r4;

    temp_r4 = data_027e02a0;
    data_027e02a0 = temp_r4 + 1;
    *((M2C_UNK *)((s8 *)&data_027e02ac + (temp_r4 * 4))) = data_027e02a4;
    data_027e02a4 = arg0;
}
