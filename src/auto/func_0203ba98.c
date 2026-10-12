#include "m2c.h"

M2C_UNK func_0203babc(void *, M2C_UNK);             /* extern */

void func_0203ba98(void *arg0) {
    void *temp_r1;

    func_0203babc(arg0, 1);
    temp_r1 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r1, s32 *, 8) = (s32) (M2C_FIELD(temp_r1, s32 *, 8) & ~0x20);
}
