#include "m2c.h"

void func_02016bf4(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x1D8) = (s8) (M2C_FIELD(arg0, s8 *, 0x1D8) - 1);
    if (M2C_FIELD(arg0, u16 *, 0x212) != 0x143) {
        return;
    }
    if ((s32) M2C_FIELD(arg0, s8 *, 0x1D8) < 0) {
        M2C_FIELD(arg0, s8 *, 0x1D8) = 0;
    }
}
