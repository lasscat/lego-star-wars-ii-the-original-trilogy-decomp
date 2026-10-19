#include "m2c.h"

M2C_UNK GetRegionOfMBlock(M2C_UNK *, s32);              /* extern */
M2C_UNK RemoveMBlock(s32, s32);                    /* extern */
M2C_UNK RecycleRegion(s32, M2C_UNK *);              /* extern */

void NNS_FndFreeToExpHeap(s32 arg0, s32 arg1) {
    u8 sp0[8];
    s32 temp_r4;

    temp_r4 = arg1 - 0x10;
    GetRegionOfMBlock(sp0, temp_r4);
    RemoveMBlock(arg0 + 0x2C, temp_r4);
    RecycleRegion(arg0 + 0x24, sp0);
}
