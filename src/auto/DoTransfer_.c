#include "m2c.h"

M2C_UNK DC_FlushRange(s32, s32);                    /* extern */
extern M2C_UNK data_020f87c0;

void DoTransfer_(void *arg0) {
    M2C_UNK (*temp_r4)(s32, s32, s32);

    temp_r4 = *((M2C_UNK *) ((s8 *) &data_020f87c0 + (M2C_FIELD(arg0, s32 *, 0) * 4)));
    DC_FlushRange(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 0xC));
    temp_r4(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0xC));
}
