#include "m2c.h"

M2C_UNK MIi_CpuClearFast(M2C_UNK, s32, M2C_UNK);       /* extern */

void func_02062944(void) {
    MIi_CpuClearFast(0xC0, 0x07000000, 0x400);
    MIi_CpuClearFast(0xC0, 0x07000400, 0x400);
}
