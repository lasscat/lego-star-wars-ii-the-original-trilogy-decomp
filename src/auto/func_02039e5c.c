#include "engine.h"
#include "m2c.h"

void func_020675d8(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0210930c;

void func_02039e5c(s32 arg0) {
    u8 temp_r1;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;

    temp_r2                                                = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r2, s32 *, 8)                           = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | 0x200);
    temp_r2_2                                              = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r2_2, s32 *, 8)                         = (s32) (M2C_FIELD(temp_r2_2, s32 *, 8) | 0x20);
    temp_r2_3                                              = M2C_FIELD(arg0, void **, 0x1C);
    M2C_FIELD(temp_r2_3, s32 *, 8)                         = (s32) (M2C_FIELD(temp_r2_3, s32 *, 8) | 2);
    M2C_FIELD(arg0, void **, 0x1C)                         = NULL;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x6BA)    = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x1AD)    = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s8 *, 0x1AD) = 0;
    temp_r1                                                = M2C_FIELD(arg0, u8 *, 0x6C);
    if (temp_r1 != 0) {
        func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                      (s32) temp_r1);
    }
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
}
