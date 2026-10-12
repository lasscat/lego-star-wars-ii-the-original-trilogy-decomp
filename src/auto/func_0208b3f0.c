#include "m2c.h"

M2C_UNK func_020601ac(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_020601d8(M2C_UNK *, void *, s32, M2C_UNK, s32); /* extern */
extern M2C_UNK data_02102900;

void func_0208b3f0(void *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x78) & 0x14) {
        return;
    }
    func_020601d8(&data_02102900, arg0 + 8, 0x12A, 5, 1);
    func_020601ac(&data_02102900, 0, arg1, -1, 0, 1);
}
