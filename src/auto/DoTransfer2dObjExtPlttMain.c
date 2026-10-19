#include "m2c.h"

M2C_UNK GX_BeginLoadOBJExtPltt();                            /* extern */
M2C_UNK GX_LoadOBJExtPltt(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK GX_EndLoadOBJExtPltt();                            /* extern */

void DoTransfer2dObjExtPlttMain(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    GX_BeginLoadOBJExtPltt();
    GX_LoadOBJExtPltt(arg0, arg1, arg2);
    GX_EndLoadOBJExtPltt();
}
