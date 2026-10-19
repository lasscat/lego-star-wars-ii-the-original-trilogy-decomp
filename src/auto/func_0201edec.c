#include "m2c.h"

M2C_UNK func_020166c8();                            /* extern */

void func_0201edec(void *arg0) {
    u16 temp_r2;

    temp_r2 = M2C_FIELD(arg0, u16 *, 0x212);
    if ((temp_r2 == 0x112) || (temp_r2 == 0x40)) {
        if (M2C_FIELD(arg0, u8 *, 0x1BC) != 0) {
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x1BC) = 1U;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK(**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32), 0x24)(arg0, 0x56, 0, 1, 0);
    } else {
        func_020166c8();
    }
}
