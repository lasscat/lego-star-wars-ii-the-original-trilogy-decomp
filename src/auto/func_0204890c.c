#include "m2c.h"

M2C_UNK func_0202f864(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_020fe3cc;

void *func_0204890c(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_0202f864(arg0, arg1, arg2, 1);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe3cc;
    M2C_FIELD(arg0, s8 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    return arg0;
}
