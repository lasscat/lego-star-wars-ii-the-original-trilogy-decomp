#include "m2c.h"

M2C_UNK NNS_GfdInitLnkTexVramManager(s32, s32, M2C_UNK *, M2C_UNK, s32); /* extern */
M2C_UNK NNS_GfdInitLnkPlttVramManager(s32, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
s32 GX_GetSizeOfTex();                                /* extern */
s32 GX_GetSizeOfTexPltt();                                /* extern */
extern M2C_UNK data_0210a30c;
extern M2C_UNK data_0210ab0c;

void func_020ac624(void *arg0, s32 arg1) {
    s32 temp_r4;
    s32 temp_r5;

    temp_r5                      = GX_GetSizeOfTex();
    temp_r4                      = GX_GetSizeOfTexPltt();
    M2C_FIELD(arg0, s32 *, 0x4C) = arg1;
    NNS_GfdInitLnkTexVramManager(temp_r5, M2C_FIELD(arg0, s32 *, 0x4C), &data_0210a30c, 0x800, 1);
    NNS_GfdInitLnkPlttVramManager(temp_r4, &data_0210ab0c, 0x800, 1);
}
