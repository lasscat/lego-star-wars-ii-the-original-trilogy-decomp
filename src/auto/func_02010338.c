#include "m2c.h"

M2C_UNK func_020c61e0(void *, M2C_UNK, M2C_UNK);    /* extern */

void func_02010338(void *arg0, s32 arg1) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(arg0, void **, 0xDC);
    if (arg1 != 0) {
        func_020c61e0(temp_r3 + M2C_FIELD((temp_r3 + M2C_FIELD(temp_r3, volatile u16 *, 0xE)), s32 *, 0xC), 0, 0x400);
        return;
    }
    func_020c61e0(temp_r3 + M2C_FIELD((temp_r3 + M2C_FIELD(temp_r3, volatile u16 *, 0xE)), s32 *, 0xC), 1, 0x400);
}
