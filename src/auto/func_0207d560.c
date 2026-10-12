#include "m2c.h"

void *func_020aaeb4();                              /* extern */
M2C_UNK func_020cb0ac(M2C_UNK, M2C_UNK, s32, M2C_UNK, s32); /* extern */

void func_0207d560(void) {
    void *temp_r0;

    temp_r0 = func_020aaeb4();
    M2C_FIELD(temp_r0, s8 *, 0x1B0) = 0;
    M2C_FIELD(temp_r0, s32 *, 0x1AC) = (s32) (M2C_FIELD(temp_r0, s32 *, 0x1AC) | 4);
    func_020cb0ac(0, 0x1F, 0x7FFF, 0x3F, 0);
}
