#include "m2c.h"

M2C_UNK func_0205365c(s32, M2C_UNK);                /* extern */
M2C_UNK func_0206574c(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_02065be8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
s32 func_02066708(s32);                             /* extern */
M2C_UNK func_0207e8ac(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_02104d50;
extern s32 data_027e02a8;

s32 func_0207e050(void *arg0) {
    if (((s32) M2C_FIELD(&data_02104d50, s32 *, 0x10) > 0) || (data_027e02a8 & 0x40)) {
        func_0205365c(M2C_FIELD(arg0, s32 *, 0x10), 0);
        func_0206574c(M2C_FIELD(arg0, s32 *, 0xC), 9, -2);
        func_02065be8(M2C_FIELD(arg0, s32 *, 0xC), 0x8C, 0x80, 0x38, func_02066708(0x153), 1);
        if (M2C_FIELD(&data_02104d50, s32 *, 0x10) == 0) {
            func_0207e8ac(arg0, 0);
        }
        M2C_FIELD(arg0, s8 *, 0x27) = 0xB;
        return 1;
    }
    return 0;
}
