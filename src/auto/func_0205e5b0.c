#include "m2c.h"

M2C_UNK NNS_FndFreeToExpHeap(s32, M2C_UNK);                /* extern */
s32 func_020c293c(M2C_UNK);                         /* extern */
s32 func_020c2944();                                /* extern */
extern M2C_UNK data_02102848;

s32 func_0205e5b0(M2C_UNK arg0) {
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = *((M2C_UNK *) ((s8 *) &data_02102848 + (func_020c2944() << 5)));
    temp_r4 = func_020c293c(arg0);
    NNS_FndFreeToExpHeap(temp_r5, arg0);
    return temp_r4;
}
