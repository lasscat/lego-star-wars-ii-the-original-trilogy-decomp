#include "m2c.h"

extern M2C_UNK data_020f0214;

void func_0201db88(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s8 temp_r1;
    u8 temp_r2;

    temp_r2 = *((u8 *) ((s8 *) &data_020f0214 + (arg3 * 2)));
    if ((s32) temp_r2 <= 0) {
        return;
    }
    if ((M2C_FIELD(arg1, u16 *, 0xC) == 0x10) && (M2C_FIELD(arg0, u8 *, 0x216) == 0)) {
        temp_r1 = M2C_FIELD(arg0, s8 *, 0x1C1);
        if ((s32) temp_r1 > 0) {
            M2C_FIELD(arg0, s8 *, 0x1C1) = (s8) (temp_r1 - temp_r2);
        }
        if ((s32) M2C_FIELD(arg0, s8 *, 0x1C1) <= 0) {
            M2C_FIELD(arg0, s8 *, 0x1BC) = 1;
        }
    }
}
