#include "m2c.h"

M2C_UNK DC_StoreRange(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK MI_DmaCopy32(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK MI_DmaCopy16(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_0205e724(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    DC_StoreRange(arg1, arg3);
    if (arg4 == 0x20) {
        MI_DmaCopy32(arg0, arg1, arg2, arg3);
        return;
    }
    MI_DmaCopy16(arg0, arg1, arg2, arg3);
}
