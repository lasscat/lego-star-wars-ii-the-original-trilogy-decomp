#include "m2c.h"

M2C_UNK func_020a3458(s32, M2C_UNK);                /* extern */
s32 func_020aaeb4();                                /* extern */
M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0210794c;
extern s32 data_027e02a8;

void func_020576d8(void) {
    if (data_027e02a8 & 0x40) {
        func_020b04f0(&data_0210794c, 0x3E, 0, 0xFF);
    }
    func_020a3458(func_020aaeb4(), 1);
}
