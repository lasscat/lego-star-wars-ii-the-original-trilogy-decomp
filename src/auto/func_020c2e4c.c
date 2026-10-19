#include "m2c.h"

M2C_UNK GXS_BeginLoadBGExtPltt();                            /* extern */
M2C_UNK GXS_LoadBGExtPltt(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK GXS_EndLoadBGExtPltt();                            /* extern */

void func_020c2e4c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(arg0, arg1, arg2);
    GXS_EndLoadBGExtPltt();
}
