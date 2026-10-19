#include "m2c.h"

M2C_UNK func_0205ecc4(); /* extern */
M2C_UNK func_020601ac(); /* extern */
extern M2C_UNK data_02102900;

void func_0207c118(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0xDD) == 0) {
        func_0205ecc4(&data_02102900, 4, 0, 4, 0xE, 1);
        func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
        return;
    }
    func_020601ac(&data_02102900, 1, 0x36, -1, 2, 0);
    M2C_FIELD(arg0, s8 *, 0xDE) = 1;
}
