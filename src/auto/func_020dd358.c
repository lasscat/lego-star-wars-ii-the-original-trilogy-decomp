#include "m2c.h"
#include "engine.h"

M2C_UNK func_020e2c20(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0211e444;

void func_020dd358(s32 arg0) {
    s32 temp_r1;

    temp_r1 = arg0 - 2;
    M2C_FIELD(&data_0211e444, s32 *, 8) = temp_r1;
    M2C_FIELD(&data_0211e444, s32 *, 0xC) = func_020e2c20(0x1E, temp_r1);
    M2C_FIELD(&data_0211e444, s32 *, 0x10) = 0x1E;
}
