#include "m2c.h"

extern M2C_UNK data_021157d4;

void func_020d04c0(u16 arg0, u16 arg1) {
    s32 temp_r4;
    void *temp_r0;
    void *temp_r2;
    void *temp_r3;

    temp_r4                         = arg0 * 0x18;
    temp_r3                         = M2C_FIELD(&data_021157d4, s32 *, 0xC) + temp_r4;
    M2C_FIELD(temp_r3, s32 *, 0x10) = (s32) (M2C_FIELD(temp_r3, u8 *, 0x14) | (arg1 * 2));
    temp_r2                         = M2C_FIELD(&data_021157d4, s32 *, 0xC) + temp_r4;
    if (M2C_FIELD(temp_r2, u16 *, 0xE) == 0) {
        return;
    }
    func_020d04c0(M2C_FIELD(temp_r2, u16 *, 8), (u16) M2C_FIELD(temp_r2, s32 *, 0x10));
    temp_r0 = M2C_FIELD(&data_021157d4, s32 *, 0xC) + temp_r4;
    func_020d04c0(M2C_FIELD(temp_r0, u16 *, 0xA), (u16) M2C_FIELD(temp_r0, s32 *, 0x10));
}
