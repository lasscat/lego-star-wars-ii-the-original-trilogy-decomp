#include "m2c.h"

M2C_UNK func_02001990(void *, M2C_UNK);             /* extern */
M2C_UNK func_02011384();                            /* extern */
extern M2C_UNK data_020fd260;
extern M2C_UNK func_0201db00;
extern M2C_UNK func_0201db50;

void *func_0201d98c(void *arg0) {
    func_02011384();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fd260;
    M2C_FIELD(arg0, s8 *, 0x1BC) = 0;
    M2C_FIELD(arg0, s16 *, 0x1BE) = 0x96;
    M2C_FIELD(arg0, s32 *, 0x84) = 0x16;
    M2C_FIELD(arg0, M2C_UNK **, 0x14) = &func_0201db50;
    M2C_FIELD(arg0, M2C_UNK **, 0x18) = &func_0201db00;
    func_02001990(arg0, 1);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) & ~1);
    M2C_FIELD(arg0, s8 *, 0x216) = 0;
    return arg0;
}
