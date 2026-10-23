#include "m2c.h"

extern M2C_UNK data_020ff9b4;
extern M2C_UNK data_02102900;

void func_02063ae0(s32, s32);
void func_0205ecc4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);

void func_0203aa54(void *arg0) {
    void *temp_r0;
    void *temp_r2;
    u16 v;

    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    temp_r0                    = M2C_FIELD(arg0, void **, 4);
    temp_r2                    = temp_r0 + 0x60;
    if (temp_r2 != &data_020ff9b4) {
        M2C_FIELD(temp_r2, s32 *, 0) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
        M2C_FIELD(temp_r2, s32 *, 4) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
        M2C_FIELD(temp_r2, s32 *, 8) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
    }
    temp_r0                         = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r0, s8 *, 0x1AD) = 1;
    temp_r2                         = M2C_FIELD(arg0, void **, 0x10);
    if ((M2C_FIELD(temp_r2, u32 *, 0x194) & 0x1c000) != 0 || M2C_FIELD(temp_r2, u16 *, 0x212) == 0xd) {
        M2C_FIELD(arg0, s8 *, 0x14) = 1;
    }
    v = M2C_FIELD(temp_r2, u16 *, 0x212);
    if (v == 0xa) {
        M2C_FIELD(arg0, s8 *, 0x15) = 1;
        return;
    }
    if (v < 0x1a3u) {
        return;
    }
    if (v > 0x1afu) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 0xD) = 3;
    func_02063ae0(0, 0);
    func_0205ecc4(&data_02102900, 0x32, 1, 0, 0, 0);
}
