#include "m2c.h"

void func_020aa76c(void *arg0, void *arg1) {
    if (arg1 == (arg0 + 0x3CC)) {
        return;
    }
    M2C_FIELD(arg1, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x3CC);
    M2C_FIELD(arg1, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0x3D0);
    M2C_FIELD(arg1, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 0x3D4);
}
