#include "m2c.h"

M2C_UNK GXS_BeginLoadOBJExtPltt();                            /* extern */
M2C_UNK GXS_LoadOBJExtPltt(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK GXS_EndLoadOBJExtPltt();                            /* extern */

void func_020c2e20(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    GXS_BeginLoadOBJExtPltt();
    GXS_LoadOBJExtPltt(arg0, arg1, arg2);
    GXS_EndLoadOBJExtPltt();
}
