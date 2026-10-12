#include "m2c.h"

M2C_UNK func_020601ac(M2C_UNK *, M2C_UNK, s32, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_02060204(M2C_UNK *, M2C_UNK, u8, u8);  /* extern */
extern M2C_UNK data_02102900;

void func_02059710(s32 arg0, void *arg1) {
    func_020601ac(&data_02102900, 0, M2C_FIELD(arg1, u8 *, 0) + 0x2AE, -1, 2, 0);
    func_02060204(&data_02102900, 0, M2C_FIELD(arg1, u8 *, 1), M2C_FIELD(arg1, u8 *, 2));
}
