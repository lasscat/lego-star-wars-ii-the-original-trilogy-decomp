#include "m2c.h"

u8 func_020832b0(s32 arg0, s32 arg1) {
    s32 temp_r1;
    void *temp_r2;

    temp_r2 = arg0 + (arg1 * 4);
    temp_r1 = M2C_FIELD(temp_r2, s32 *, 0xEC);
    if (temp_r1 == -1) {
        return 0xFAU;
    }
    return *(s8 *) (M2C_FIELD(temp_r2, s32 *, 0x134) + temp_r1);
}