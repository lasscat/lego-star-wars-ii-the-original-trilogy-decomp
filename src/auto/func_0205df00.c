#include "m2c.h"

M2C_UNK func_0205dfe8();                            /* extern */
extern M2C_UNK data_020fe6a0;

void *func_0205df00(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe6a0;
    M2C_FIELD(arg0, s8 *, 0x21)    = arg1;
    M2C_FIELD(arg0, s8 *, 0x20)    = 2;
    func_0205dfe8(arg0);
    return arg0;
}
