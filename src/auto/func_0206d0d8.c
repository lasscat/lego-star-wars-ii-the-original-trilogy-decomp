#include "m2c.h"

extern M2C_UNK data_020fe870;
extern M2C_UNK data_02102900;

M2C_UNK func_020601f4(M2C_UNK *, M2C_UNK *, s32);

void *func_0206d0d8(M2C_UNK *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK *, 0) = &data_020fe870;
    M2C_FIELD(arg0, s32 *, 4)     = arg1;
    func_020601f4(&data_02102900, arg0, M2C_FIELD(arg0, s32 *, 4));
    return arg0;
}
