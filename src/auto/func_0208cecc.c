#include "m2c.h"

M2C_UNK func_0208ce8c();                            /* extern */
M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0210794c;
extern s32 data_027e02a8;

void func_0208cecc(s32 arg0) {
    if (!(data_027e02a8 & 0x40)) {
        func_0208ce8c(arg0);
        return;
    }
    func_020b04f0(&data_0210794c, 0x2B, 0, 0xFF);
}
