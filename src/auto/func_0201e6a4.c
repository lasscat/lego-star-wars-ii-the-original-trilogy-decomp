#include "m2c.h"

extern M2C_UNK data_020f0214;

void func_0201e6a4(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    u16 temp_r1;

    if (*((u8 *) ((s8 *) &data_020f0214 + (arg3 * 2))) == 0) {
        return;
    }
    temp_r1 = M2C_FIELD(arg1, u16 *, 0xC);
    if ((temp_r1 != 0x10) && (temp_r1 != 0x8000)) {
        return;
    }
    if ((u32) M2C_FIELD(arg0, u8 *, 0x1BC) <= 2U) {
        M2C_FIELD(arg0, u8 *, 0x1BC) = 3U;
    }
}
