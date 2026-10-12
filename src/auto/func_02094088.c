#include "m2c.h"

M2C_UNK func_020626d8(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_020ff7d4;

void *func_02094088(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    func_020626d8(arg0, 1);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff7d4;
    M2C_FIELD(arg0, s8 *, 6) = arg1;
    M2C_FIELD(arg0, s8 *, 7) = arg2;
    M2C_FIELD(arg0, s8 *, 8) = arg3;
    return arg0;
}
