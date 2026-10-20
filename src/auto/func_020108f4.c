#include "m2c.h"

extern void func_020c6240(void *, M2C_UNK, M2C_UNK);

void func_020108f4(void *arg0, s32 arg1, s32 arg2) {
    void *temp_r3;
    s32 temp_r4;

    M2C_FIELD(arg0, u8 *, 0x1b2) = arg2;
    M2C_FIELD(arg0, u8 *, 0x1b1) = arg1;
    M2C_FIELD(arg0, u8 *, 0x1b0) = M2C_FIELD(arg0, u8 *, 0x1b1);
    M2C_FIELD(arg0, s8 *, 0x1af) = -1;
    if (M2C_FIELD(arg0, u8 *, 0x1ae) == 0) {
        M2C_FIELD(arg0, s8 *, 0x1af) = 1;
    }
    M2C_FIELD(arg0, u16 *, 0x1a8) |= 0x20;
    temp_r3 = M2C_FIELD(arg0, void **, 0xdc);
    temp_r4 = M2C_FIELD((u8 *) temp_r3 + M2C_FIELD(temp_r3, u16 *, 0xe), s32 *, 0xc);
    func_020c6240((u8 *) temp_r3 + temp_r4, 0, 0x1f0000);
}
