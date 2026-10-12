#include "m2c.h"

s32 func_020c9268(s32, s32);                        /* extern */

void func_020939ac(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x95C) = func_020c9268(arg1 << 0xC, 0x64000);
    if (arg2 == 0) {
        M2C_FIELD(arg0, s32 *, 0x958) = (s32) M2C_FIELD(arg0, s32 *, 0x95C);
        M2C_FIELD(arg0, s32 *, 0x960) = 0;
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x960) = func_020c9268(M2C_FIELD(arg0, s32 *, 0x95C) - M2C_FIELD(arg0, s32 *, 0x958), arg2 << 0xC);
}
