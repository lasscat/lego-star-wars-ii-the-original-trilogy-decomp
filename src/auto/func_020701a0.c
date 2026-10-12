#include "m2c.h"

M2C_UNK func_0205365c(s32, M2C_UNK);                /* extern */
M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02065be8(void *, s32, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 func_02066708(M2C_UNK);                         /* extern */
extern M2C_UNK data_02104d2c;

void func_020701a0(void *arg0) {
    s32 temp_r4;

    func_0205365c(arg0 + 0x28, 0);
    func_0206574c(arg0 + 0x5C, 6, -2);
    temp_r4 = func_02065be8(arg0 + 0x5C, 1, 0x7F, 0xC, func_02066708(0x74), 1);
    func_0206574c(arg0 + 0x5C, 0, -2);
    M2C_FIELD(arg0, s32 *, 0x9C) = temp_r4;
    M2C_FIELD(arg0, s32 *, 0xA0) = func_02065be8(arg0 + 0x5C, M2C_FIELD(arg0, s32 *, 0x9C), 0x80, 0x98, func_02066708(0x69), 1);
    M2C_FIELD(&data_02104d2c, s16 *, 4) = 0;
}
