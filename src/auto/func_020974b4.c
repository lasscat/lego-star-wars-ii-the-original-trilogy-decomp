#include "m2c.h"

M2C_UNK func_02096b44();                            /* extern */
extern M2C_UNK data_020ff8a4;

void *func_020974b4(void *arg0) {
    func_02096b44();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020ff8a4;
    M2C_FIELD(arg0, s8 *, 0x2E) = 0;
    M2C_FIELD(arg0, s8 *, 0x2F) = 0;
    M2C_FIELD(arg0, s16 *, 0x30) = -1;
    M2C_FIELD(arg0, s8 *, 0x32) = 0;
    M2C_FIELD(arg0, s8 *, 0x1C) = 2;
    return arg0;
}
