#include "m2c.h"

M2C_UNK MIi_CpuClearFast(M2C_UNK, s32, M2C_UNK);       /* extern */

void func_02062970(void) {
    MIi_CpuClearFast(0, 0x05000000, 0x400);
    MIi_CpuClearFast(0, 0x05000400, 0x400);
}
