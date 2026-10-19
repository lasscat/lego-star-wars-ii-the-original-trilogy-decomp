#include "m2c.h"

M2C_UNK func_020ba4b8(M2C_UNK *, M2C_UNK *, u32);   /* extern */
M2C_UNK DC_FlushRange(s32, M2C_UNK);                /* extern */
extern M2C_UNK data_0210dc20;
extern M2C_UNK data_0210e0bc;
extern M2C_UNK data_0210e0e8;
extern M2C_UNK data_0210e118;

void func_020ba0a4(void) {
    u32 var_r4;

    var_r4 = (u32) M2C_FIELD(&data_0210dc20, u32 *, 0x52C) >> 1;
    if (M2C_FIELD(&data_0210dc20, s32 *, 0x498) & 4) {
        var_r4 = var_r4 >> 1;
    }
    func_020ba4b8(&data_0210e0bc, &data_0210e0e8, var_r4);
    func_020ba4b8(&data_0210e0bc, &data_0210e118, var_r4);
    DC_FlushRange(M2C_FIELD(&data_0210dc20, s32 *, 0x528), 0x2000);
}
