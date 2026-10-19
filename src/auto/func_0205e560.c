#include "engine.h"
#include "m2c.h"

void NNS_FndAllocFromExpHeapEx(M2C_UNK, M2C_UNK, M2C_UNK);
void func_020c292c(M2C_UNK, M2C_UNK);

extern M2C_UNK data_02102848;
extern s32 data_027e02a4;

void func_0205e560(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r4;
    s32 var_r5;

    temp_r4 = *((M2C_UNK *) ((s8 *) &data_02102848 + (arg0 << 5)));
    var_r5  = arg2;
    func_020c292c(temp_r4, (s32) (u16) arg0);
    if (data_027e02a4 != 0) {
        var_r5 = 0 - var_r5;
    }
    NNS_FndAllocFromExpHeapEx(temp_r4, arg1, var_r5);
}
