#include "m2c.h"

M2C_UNK func_02096b44();                            /* extern */
extern M2C_UNK data_020ff8d4;

void *func_02097590(void *arg0) {
    func_02096b44();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff8d4;
    M2C_FIELD(arg0, s16 *, 0x2E)   = 0;
    M2C_FIELD(arg0, s8 *, 0x30)    = 0;
    M2C_FIELD(arg0, s8 *, 0x1C)    = 4;
    return arg0;
}
