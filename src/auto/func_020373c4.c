#include "m2c.h"

M2C_UNK func_0202c374(s32, void *);                 /* extern */

void func_020373c4(void *arg0) {
    u16 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u16 *, 0xE);
    if (temp_r1 == 0) {
        return;
    }
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) (temp_r1 - 1);
    if ((u32) temp_r1 > 1U) {
        return;
    }
    func_0202c374(M2C_FIELD(arg0, s32 *, 4) + 0x5E0, arg0);
    M2C_FIELD(arg0, u8 *, 0xC) = (u8) (M2C_FIELD(arg0, u8 *, 0xC) | 1);
}
