#include "m2c.h"

M2C_UNK func_0205e624(s32, M2C_UNK, M2C_UNK);

void func_02034bd0(void *arg0, s8 arg1) {
    s32 sp8;
    s32 sp4;
    u16 sp0;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;

    func_0205e624(arg0 + 0x54, 0, 1);
    M2C_FIELD(arg0, s8 *, 0x30) = 1;
    temp_r1                     = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r1, void **, 0), M2C_UNK(**)(s32 *, void *, M2C_UNK), 0x3C)(&sp8, temp_r1, 6);
    M2C_FIELD(arg0, s32 *, 0x10) = sp8;
    temp_r1_2                    = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(M2C_FIELD(temp_r1_2, void **, 0), M2C_UNK(**)(s32 *, void *, M2C_UNK), 0x3C)(&sp4, temp_r1_2, 6);
    M2C_FIELD(arg0, s32 *, 0x14) = sp4;
    M2C_FIELD(arg0, s8 *, 0x1D)  = 1;
    M2C_FIELD(arg0, s8 *, 0x54)  = arg1;
    M2C_FIELD(&sp0, u16 *, 0)    = M2C_FIELD(arg0, u16 *, 0x18);
    temp_r1_3                    = M2C_FIELD(arg0, void **, 4);
    if (M2C_FIELD(temp_r1_3, u16 *, 0xCA) != sp0) {
        M2C_FIELD(temp_r1_3, u16 *, 0xCA) = sp0;
        M2C_FIELD(temp_r1_3, s8 *, 0xD0)  = 1;
    }
}
