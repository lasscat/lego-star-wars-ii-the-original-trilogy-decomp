#include "m2c.h"

M2C_UNK func_02055b24(u16, s32, u16, u16, s32);     /* extern */

void func_02055978(void *arg0) {
    s16 temp_r1;
    u16 temp_r1_2;

    if (M2C_FIELD(arg0, u8 *, 0) == 0) {
        return;
    }
    temp_r1                   = M2C_FIELD(arg0, s16 *, 4);
    M2C_FIELD(arg0, s16 *, 4) = (s16) (temp_r1 - 1);
    if (temp_r1 != 0) {
        return;
    }
    M2C_FIELD(arg0, s16 *, 4) = (s16) M2C_FIELD(arg0, u16 *, 6);
    temp_r1_2                 = M2C_FIELD(arg0, u16 *, 8);
    if (M2C_FIELD(arg0, u16 *, 0x12) == temp_r1_2) {
        M2C_FIELD(arg0, u16 *, 0x12) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
    } else {
        M2C_FIELD(arg0, u16 *, 0x12) = temp_r1_2;
    }
    func_02055b24(M2C_FIELD(arg0, u16 *, 2), M2C_FIELD(arg0, u16 *, 0x12) * 2, M2C_FIELD(arg0, u16 *, 0xE),
                  M2C_FIELD(arg0, u16 *, 0xC), M2C_FIELD(arg0, s32 *, 0x14));
}
