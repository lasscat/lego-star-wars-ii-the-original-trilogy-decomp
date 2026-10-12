#include "m2c.h"

M2C_UNK func_020dc804();                            /* extern */
extern M2C_UNK data_0211e400;

void func_020dc9e8(s32 arg0) {
    M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 0xC), s32 *, 0x1320) = 1;
    func_020dc804(arg0);
}
