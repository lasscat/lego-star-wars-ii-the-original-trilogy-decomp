#include "m2c.h"

M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK data_02102900;

void func_0206b5c4(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x18) != 2) {
        return;
    }
    func_0205ecc4(&data_02102900, 0xF, 0, 0, 0, 0);
    func_0205ecc4(&data_02102900, 0x1C, 1, 0x1A, 0x4A, 0);
}
