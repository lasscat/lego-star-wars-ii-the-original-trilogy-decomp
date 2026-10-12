#include "m2c.h"

M2C_UNK func_020975f4();                            /* extern */
extern M2C_UNK data_020ff98c;

void *func_02098344(void *arg0) {
    func_020975f4();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff98c;
    M2C_FIELD(arg0, s8 *, 0x2C) = 1;
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
    return arg0;
}
