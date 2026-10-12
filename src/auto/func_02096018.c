#include "m2c.h"

M2C_UNK func_020975f4();                            /* extern */
extern M2C_UNK data_020ff858;

void *func_02096018(void *arg0) {
    func_020975f4();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff858;
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
    M2C_FIELD(arg0, s8 *, 0x1C) = 8;
    M2C_FIELD(arg0, s8 *, 0x3B) = 0;
    return arg0;
}
