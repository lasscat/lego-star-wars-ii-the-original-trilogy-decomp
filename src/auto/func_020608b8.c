#include "m2c.h"

M2C_UNK func_02060b44(M2C_UNK);                     /* extern */
M2C_UNK func_02060bd4(M2C_UNK);                     /* extern */
extern M2C_UNK data_02103374;

void func_020608b8(void) {
    func_02060b44(0);
    func_02060bd4(0);
    M2C_FIELD(&data_02103374, s8 *, 0x722) = 0;
    func_02060b44(1);
    func_02060bd4(1);
    M2C_FIELD(&data_02103374, s8 *, 0xE46) = 0;
}
