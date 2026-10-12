#include "m2c.h"

M2C_UNK func_0202f864(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020c3c34(void *, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_020fdda8;
extern M2C_UNK func_02031e64;

void *func_02031a5c(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_0202f864(arg0, arg1, arg2, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdda8;
    M2C_FIELD(arg0, s16 *, 0x30) = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x120) = arg0;
    func_020c3c34(M2C_FIELD(arg0, void **, 4) + 0xF4, &func_02031e64, 0, 6, 2);
    return arg0;
}
