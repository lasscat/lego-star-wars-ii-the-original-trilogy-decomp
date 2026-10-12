#include "m2c.h"

M2C_UNK func_020975f4();                            /* extern */
extern M2C_UNK data_020ff908;

void *func_02097944(void *arg0) {
    func_020975f4();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff908;
    M2C_FIELD(arg0, s8 *, 0x1C) = 0xA;
    M2C_FIELD(arg0, s8 *, 0x2D) = 4;
    M2C_FIELD(arg0, s8 *, 0x39) = 1;
    M2C_FIELD(arg0, s8 *, 0x2C) = 0;
    return arg0;
}
