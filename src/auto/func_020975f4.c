#include "m2c.h"

M2C_UNK func_02096278();                            /* extern */
extern M2C_UNK data_020ff8ec;

void *func_020975f4(void *arg0) {
    func_02096278();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff8ec;
    M2C_FIELD(arg0, s8 *, 0x2C) = 0;
    M2C_FIELD(arg0, s8 *, 0x2D) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0x80000000;
    M2C_FIELD(arg0, s8 *, 0x38) = 0;
    M2C_FIELD(arg0, s8 *, 0x39) = 0;
    M2C_FIELD(arg0, s8 *, 0x3A) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = 5;
    return arg0;
}
