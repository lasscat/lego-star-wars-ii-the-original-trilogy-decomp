#include "m2c.h"

s32 func_02062a7c(s32, s32);   /* extern */
void func_02007f24(s32 *, double); /* extern */

void func_02096374(void *arg0, s32 *arg1) {
    s32 temp_r8;
    s32 temp_r4;
    s32 temp_r0;
    s32 x;

    if (arg1 != &M2C_FIELD(arg0, s32 *, 4)) {
        arg1[0] = M2C_FIELD(arg0, s32 *, 4);
        arg1[1] = M2C_FIELD(arg0, s32 *, 8);
        arg1[2] = M2C_FIELD(arg0, s32 *, 0xC);
    }
    x = M2C_FIELD(arg0, s32 *, 0x10) >> 12;
    func_02007f24(&temp_r8, 0.01 * (double) func_02062a7c(-x * 50, x * 50));
    arg1[0] += temp_r8;
    x = M2C_FIELD(arg0, s32 *, 0x18) >> 12;
    func_02007f24(&temp_r4, 0.01 * (double) func_02062a7c(-x * 50, x * 50));
    arg1[2] += temp_r4;
    if (M2C_FIELD(arg0, u8 *, 0x1F) == 0) {
        x = M2C_FIELD(arg0, s32 *, 0x14) >> 12;
        func_02007f24(&temp_r0, 0.01 * (double) func_02062a7c(-x * 50, x * 50));
        arg1[1] += temp_r0;
    }
}
