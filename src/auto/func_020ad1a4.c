#include "m2c.h"

M2C_UNK MIi_CpuClearFast(M2C_UNK, void *, M2C_UNK);    /* extern */

void *func_020ad1a4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x60) = 0;
    MIi_CpuClearFast(0, arg0, 0x70);
    return arg0;
}
