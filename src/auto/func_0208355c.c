#include "m2c.h"

s32 func_020838b8();                     /* extern */

void func_0208355c(s32 arg0, void *arg1) {
    u16 temp_r2;

    temp_r2 = M2C_FIELD(arg1, u16 *, 0xC);
    if (temp_r2 == 2) {
        if (func_020838b8(arg0, arg1) != 0) {
            M2C_FIELD(arg1, s32 *, 0x6B0) = arg0;
        }
        return;
    }
    if (temp_r2 != 4) {
        return;
    }
    temp_r2 = M2C_FIELD(arg1, u16 *, 0x212);
    if ((u32) temp_r2 <= 0x4AU) {
        if ((u32) temp_r2 < 0x4AU) {
            if ((u32) temp_r2 <= 0x18U) {
                if (temp_r2 != 0x18) {
                    return;
                }
                goto block_19;
            }
            if (temp_r2 != 0x2B) {
                return;
            }
            goto block_19;
        }
        goto block_19;
    }
    if ((u32) temp_r2 <= 0xA4U) {
        if (((u32) temp_r2 < 0xA4U) && (temp_r2 != 0x85)) {
            return;
        }
        goto block_19;
    }
    if (temp_r2 != 0x115) {
        return;
    }
block_19:
    if (func_020838b8(arg0, arg1) != 0) {
        M2C_FIELD(arg1, s32 *, 0x218) = arg0;
    }
}
