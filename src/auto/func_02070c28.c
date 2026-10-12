#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02065be8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 func_02066708(M2C_UNK);                         /* extern */
extern M2C_UNK data_02104d2c;

void func_02070c28(s32 arg0) {
    func_0206574c(arg0 + 0x5C, 6, -2);
    func_02065be8(arg0 + 0x5C, 1, 0x7F, 0xC, func_02066708(0x7A), 1);
    func_0206574c(arg0 + 0x5C, 0, -2);
    M2C_FIELD(&data_02104d2c, s16 *, 2) = 0;
}
