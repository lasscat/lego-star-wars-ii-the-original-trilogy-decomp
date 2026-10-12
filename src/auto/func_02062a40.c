#include "m2c.h"

M2C_UNK func_02062b6c();                            /* extern */
extern M2C_UNK data_02104344;

void func_02062a40(s32 arg0) {
    M2C_FIELD(&data_02104344, s32 *, 0x1C) = arg0;
    func_02062b6c();
    M2C_FIELD(&data_02104344, s32 *, 8) = 0x26F;
    M2C_FIELD(&data_02104344, s32 *, 0xC) = (s32) (M2C_FIELD(&data_02104344, s32 *, 0x10) + 4);
    M2C_FIELD(&data_02104344, s8 *, 0) = (s8) arg0;
}
