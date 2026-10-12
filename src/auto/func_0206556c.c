#include "m2c.h"

M2C_UNK func_0205ab6c(u16);                         /* extern */
extern M2C_UNK data_021047fc;

void func_0206556c(s32 arg0, s32 arg1) {
    s32 temp_r4;
    u16 temp_r0;

    temp_r4 = (arg1 * 0x1C) + ((arg0 * 0x38) + (s32) &data_021047fc);
    temp_r0 = M2C_FIELD(temp_r4, u16 *, 2);
    if (temp_r0 == 0) {
        return;
    }
    M2C_FIELD(temp_r4, u16 *, 2) = (u16) (temp_r0 - 1);
    func_0205ab6c(M2C_FIELD(temp_r4, u16 *, 0));
    if (M2C_FIELD(temp_r4, u16 *, 2) != 0) {
        return;
    }
    M2C_FIELD(temp_r4, s16 *, 0xA) = 0;
    M2C_FIELD(temp_r4, s16 *, 0xC) = 0;
    M2C_FIELD(temp_r4, s8 *, 8) = 0;
    M2C_FIELD(temp_r4, s8 *, 0xE) = 0;
    M2C_FIELD(temp_r4, s32 *, 0x10) = 0;
    M2C_FIELD(temp_r4, s32 *, 0x14) = 0;
    M2C_FIELD(temp_r4, s32 *, 0x18) = 0;
    M2C_FIELD(temp_r4, s32 *, 4) = 0;
}
