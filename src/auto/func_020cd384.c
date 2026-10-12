#include "m2c.h"

M2C_UNK func_020cd3a4(s32, M2C_UNK);                /* extern */
M2C_UNK func_020ce804();                            /* extern */
extern M2C_UNK data_02115424;

void func_020cd384(void) {
    func_020ce804();
    func_020cd3a4(M2C_FIELD(&data_02115424, s32 *, 0x28), 0);
}
