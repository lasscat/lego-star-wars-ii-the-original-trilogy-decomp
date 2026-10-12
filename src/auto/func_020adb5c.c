#include "m2c.h"

M2C_UNK func_020ad7a4(M2C_UNK);                     /* extern */
s32 func_020ae63c();                                /* extern */
extern M2C_UNK data_0210b320;
extern M2C_UNK func_020adca4;

s32 func_020adb5c(s32 arg0, void *arg1, s16 arg2) {
    func_020ad7a4(2);
    M2C_FIELD(&data_0210b320, M2C_UNK **, 0x34) = &func_020adca4;
    M2C_FIELD(&data_0210b320, s16 *, 6) = arg2;
    M2C_FIELD(&data_0210b320, s16 *, 0x64) = 0;
    M2C_FIELD(&data_0210b320, s16 *, 4) = 0;
    M2C_FIELD(&data_0210b320, u16 *, 0x6C) = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(&data_0210b320, u16 *, 0x6A) = (u16) M2C_FIELD(arg1, u16 *, 2);
    M2C_FIELD(&data_0210b320, u16 *, 0x68) = (u16) M2C_FIELD(arg1, u16 *, 0);
    if (func_020ae63c() != 0) {
        return 1;
    }
    func_020ad7a4(9);
    return 0;
}
