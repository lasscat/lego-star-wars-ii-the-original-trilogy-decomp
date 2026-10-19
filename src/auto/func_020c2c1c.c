#include "m2c.h"

M2C_UNK GX_BeginLoadTexPltt();                            /* extern */
M2C_UNK GX_LoadTexPltt(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK GX_EndLoadTexPltt();                            /* extern */

void func_020c2c1c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(arg0, arg1, arg2);
    GX_EndLoadTexPltt();
}
