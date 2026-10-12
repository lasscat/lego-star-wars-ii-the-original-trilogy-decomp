#include "m2c.h"

M2C_UNK func_020601f4(M2C_UNK *, M2C_UNK, s32);     /* extern */
extern M2C_UNK data_020fe870;
extern M2C_UNK data_02102900;

void *func_0206d10c(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe870;
    func_020601f4(&data_02102900, 0, M2C_FIELD(arg0, s32 *, 4));
    return arg0;
}
