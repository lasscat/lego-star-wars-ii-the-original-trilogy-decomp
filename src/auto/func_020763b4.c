#include "m2c.h"

s32 func_0205d0d0(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_02063ae0(M2C_UNK, M2C_UNK);            /* extern */
s32 func_020765e4();                                /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02102900;

void func_020763b4(void) {
    if ((func_020765e4() == 0) && (func_0205d0d0(&data_021027f8, 0x400, 4) == 0)) {
        return;
    }
    func_02063ae0(0, 0);
    func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
}
