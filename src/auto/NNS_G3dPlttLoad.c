#include "m2c.h"

M2C_UNK GX_BeginLoadTexPltt();                            /* extern */
M2C_UNK GX_LoadTexPltt(void *, u32, s32);            /* extern */
M2C_UNK GX_EndLoadTexPltt();                            /* extern */

void NNS_G3dPlttLoad(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        GX_BeginLoadTexPltt();
    }
    GX_LoadTexPltt(arg0 + M2C_FIELD(arg0, s32 *, 0x38), (u32) (M2C_FIELD(arg0, s32 *, 0x2C) << 0x10) >> 0xD,
                   M2C_FIELD(arg0, u16 *, 0x30) * 8);
    M2C_FIELD(arg0, u16 *, 0x32) = (u16) (M2C_FIELD(arg0, u16 *, 0x32) | 1);
    if (arg1 == 0) {
        return;
    }
    GX_EndLoadTexPltt();
}
