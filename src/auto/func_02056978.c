#include "m2c.h"

extern M2C_UNK data_02106d90;

void func_02056978(s32 arg0, u8 *arg1) {
    M2C_FIELD(&data_02106d90, u8 *, 0xBB4) = (u8) *arg1;
}
