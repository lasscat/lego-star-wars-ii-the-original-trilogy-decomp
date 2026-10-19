#include "m2c.h"

M2C_UNK GX_BeginLoadBGExtPltt();                            /* extern */
M2C_UNK GX_LoadBGExtPltt(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK GX_EndLoadBGExtPltt();                            /* extern */

void DoTransfer2dBGExtPlttMain(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(arg0, arg1, arg2);
    GX_EndLoadBGExtPltt();
}
