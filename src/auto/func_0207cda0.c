#include "m2c.h"

M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
s32 func_02065be8(s32, s32, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_020661b4(s32, s32);                    /* extern */
s32 func_02066708(s32);                             /* extern */
s32 func_020855a4(M2C_UNK *);                       /* extern */
extern M2C_UNK data_02104d94;

void func_0207cda0(void *arg0) {
    func_0206574c(arg0 + 0x40, 6, -1);
    func_020661b4(arg0 + 0x40, func_020855a4(&data_02104d94));
    M2C_FIELD(arg0, s32 *, 0xA0) = func_02065be8(arg0 + 0x40, M2C_FIELD(arg0, s32 *, 0xA0), 0xB4, 5, func_02066708(0x157), 1);
}
