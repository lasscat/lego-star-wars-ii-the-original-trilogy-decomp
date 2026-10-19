#include "m2c.h"

M2C_UNK MI_DmaFill16(M2C_UNK, s32, u16, s32);      /* extern */

void func_020660e4(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    if (arg1 > arg3) {
        return;
    }
    MI_DmaFill16(3, M2C_FIELD(arg0, s32 *, 0x1C) + ((arg1 + (arg2 << 5)) * 2), arg4, ((arg3 - arg1) + 1) * 2);
}
