#include "m2c.h"

extern M2C_UNK data_021027f8;
extern M2C_UNK data_02109358;

void func_0205723c(void) {
    M2C_FIELD(*((M2C_UNK *)((s8 *)&data_02109358 + (M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 4))), s32 *, 0x804) = 0;
}
