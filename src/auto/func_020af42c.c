#include "m2c.h"

M2C_UNK DC_FlushRange(s32, M2C_UNK);                /* extern */
M2C_UNK MI_CpuCopy8(s32, s32, M2C_UNK);           /* extern */

void func_020af42c(s32 arg0) {
    DC_FlushRange(arg0 + 0x40, 0x200);
    MI_CpuCopy8(arg0 + 0x640, arg0 + 0x40, 0x70);
    DC_FlushRange(arg0 + 0x40, 0x70);
}
