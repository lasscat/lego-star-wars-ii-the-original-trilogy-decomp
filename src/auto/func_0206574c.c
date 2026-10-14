#include "m2c.h"

void func_0206574c(void *arg0, s32 arg1, s32 arg2) {
    if (arg1 != -2) {
        if (M2C_FIELD(arg0, s32 *, 0x2C) == 1) {
            M2C_FIELD(arg0, s32 *, 0xC)  = arg1;
            M2C_FIELD(arg0, s32 *, 0x14) = 0;
        } else {
            M2C_FIELD(arg0, s32 *, 0xC)  = (s32) (arg1 & 0xF);
            M2C_FIELD(arg0, s32 *, 0x14) = (s32) ((arg1 >> 4) << 0xC);
        }
    }
    if (arg2 != -2) {
        M2C_FIELD(arg0, s32 *, 0x10) = arg2;
    }
}
