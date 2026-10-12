#include "m2c.h"

M2C_UNK func_0201ab20();                            /* extern */
extern M2C_UNK data_020fd164;

void *func_0201c1f8(void *arg0) {
    func_0201ab20();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd164;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, s32 *, 0x84) = 0;
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    M2C_FIELD(arg0, s32 *, 0x90) = 0;
    return arg0;
}
