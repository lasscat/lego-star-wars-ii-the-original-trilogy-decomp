#include "m2c.h"

M2C_UNK func_02004acc(void *);
extern M2C_UNK data_020f6bc2;
extern M2C_UNK data_020ff9b4;

void func_0203a3b4(void *arg0) {
    void *temp_r0;
    void *temp_r2;

    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    temp_r0                    = M2C_FIELD(arg0, void **, 4);
    temp_r2                    = temp_r0 + 0x60;
    if (temp_r2 != &data_020ff9b4) {
        M2C_FIELD(temp_r2, s32 *, 0) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 0);
        M2C_FIELD(temp_r2, s32 *, 4) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 4);
        M2C_FIELD(temp_r2, s32 *, 8) = (s32) M2C_FIELD(&data_020ff9b4, s32 *, 8);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x6BA) = 1;
    temp_r0                                             = M2C_FIELD(arg0, void **, 4);
    if (!(*((u16 *) ((s8 *) &data_020f6bc2 + (M2C_FIELD(temp_r0, u8 *, 0x6C3) * 0x24))) & 0x40)) {
        func_02004acc(temp_r0);
    }
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 4), u8 *, 0x5DA);
}
