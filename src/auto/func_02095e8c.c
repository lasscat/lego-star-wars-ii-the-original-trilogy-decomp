#include "m2c.h"

M2C_UNK func_0205e624(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK memcpy(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK data_020f722c;

void func_02095e8c(s32 arg0) {
    memcpy(arg0, &data_020f722c, 0x64);
    func_0205e624(arg0 + 0x64, 0, 0x64);
}
