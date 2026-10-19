#include "m2c.h"

s32 func_020c2700(s32, s32, M2C_UNK);
M2C_UNK func_020c2904(s32, M2C_UNK);
M2C_UNK func_020c2b6c(void *, s32, M2C_UNK);
extern volatile s32 data_02102844;
extern volatile s32 data_02102848[];
extern volatile s32 data_0210284c[];
extern volatile s32 data_0210285c[];
extern volatile s32 data_02102860[];
extern volatile s32 data_02102864[];
void func_0205e778(s32 arg0, s32 arg1, s32 arg2) {
    s32 t = arg2 - arg1;
    s32 p = func_020c2700(arg1, t, 2);
    func_020c2b6c((void *) &data_0210284c[arg0 * 8], p, 4);
    func_020c2904(p, 1);
    data_02102848[arg0 * 8] = p;
    data_0210285c[arg0 * 8] = arg1;
    data_02102860[arg0 * 8] = arg2;
    data_02102864[arg0 * 8] = t;
    data_02102844 += 1;
}
