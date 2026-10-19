#include "m2c.h"

M2C_UNK GX_BeginLoadTex();                            /* extern */
M2C_UNK GX_LoadTex(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK GX_EndLoadTex();                            /* extern */

void func_020c2bf0(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    GX_BeginLoadTex();
    GX_LoadTex(arg0, arg1, arg2);
    GX_EndLoadTex();
}
