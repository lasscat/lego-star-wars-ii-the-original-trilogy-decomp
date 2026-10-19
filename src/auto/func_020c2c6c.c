#include "m2c.h"

M2C_UNK GX_BeginLoadClearImage();                            /* extern */
M2C_UNK GX_LoadClearImageDepth(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK GX_EndLoadClearImage();                            /* extern */

void func_020c2c6c(M2C_UNK arg0, s32 arg1, M2C_UNK arg2) {
    GX_BeginLoadClearImage();
    GX_LoadClearImageDepth(arg0, arg2);
    GX_EndLoadClearImage();
}
