#include "m2c.h"

M2C_UNK func_020976d0(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_02097b98(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    func_020976d0(arg0, 5, 1, 1);
    M2C_FIELD(arg0, s8 *, 0x3B) = arg1;
    M2C_FIELD(arg0, s8 *, 0x3C) = arg2;
    M2C_FIELD(arg0, s8 *, 0x3D) = arg3;
}
