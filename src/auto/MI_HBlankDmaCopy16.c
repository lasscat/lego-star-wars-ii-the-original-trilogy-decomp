#include "m2c.h"

M2C_UNK MIi_DmaSetParams(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK MI_WaitDma(M2C_UNK);                     /* extern */
M2C_UNK MIi_CheckAnotherAutoDMA(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK MIi_CheckDma0SourceAddress(M2C_UNK, M2C_UNK, u32, M2C_UNK); /* extern */

void MI_HBlankDmaCopy16(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, u32 arg3) {
    MIi_CheckAnotherAutoDMA(arg0, 0x10000000);
    MIi_CheckDma0SourceAddress(arg0, arg1, arg3, 0);
    if (arg3 == 0) {
        return;
    }
    MI_WaitDma(arg0);
    MIi_DmaSetParams(arg0, arg1, arg2, 0x92600000 | (arg3 >> 1));
}
