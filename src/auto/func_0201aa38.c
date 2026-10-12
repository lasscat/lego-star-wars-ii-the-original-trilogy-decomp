#include "m2c.h"

M2C_UNK func_0201a934(void *, s32, s32, s16);       /* extern */

void func_0201aa38(void *arg0) {
    s32 temp_r2;

    M2C_FIELD(arg0, u16 *, 0x3E) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E) - 1);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + M2C_FIELD(arg0, s32 *, 0x34));
    temp_r2 = M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s32 *, 0x38);
    M2C_FIELD(arg0, s32 *, 0x30) = temp_r2;
    func_0201a934(arg0, M2C_FIELD(arg0, s32 *, 0x2C), temp_r2, M2C_FIELD(arg0, s16 *, 0x3C));
}
