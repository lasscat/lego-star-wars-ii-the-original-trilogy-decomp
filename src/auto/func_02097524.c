#include "m2c.h"

M2C_UNK func_02096b44();                            /* extern */
extern M2C_UNK data_020ff8bc;

void *func_02097524(void *arg0) {
    func_02096b44();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff8bc;
    M2C_FIELD(arg0, s32 *, 0x30)   = 0;
    M2C_FIELD(arg0, s32 *, 0x34)   = 0;
    M2C_FIELD(arg0, s32 *, 0x38)   = 0;
    M2C_FIELD(arg0, s8 *, 0x3C)    = 0;
    M2C_FIELD(arg0, s8 *, 0x1C)    = 3;
    return arg0;
}
