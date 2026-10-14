#include "m2c.h"

M2C_UNK func_0206b868(void *, s32);                 /* extern */

void func_0206b828(void *arg0, void *arg1, s16 arg2, s16 arg3, u8 arg4) {
    s32 temp_r4;
    void *temp_r5;

    temp_r4                         = M2C_FIELD(arg1, s32 *, 0);
    temp_r5                         = arg0 + (temp_r4 << 5);
    M2C_FIELD(temp_r5, s32 *, 0xC)  = temp_r4;
    M2C_FIELD(temp_r5, s32 *, 0x10) = (s32) M2C_FIELD(arg1, s32 *, 4);
    M2C_FIELD(temp_r5, s16 *, 0x16) = arg2;
    M2C_FIELD(temp_r5, s16 *, 0x14) = arg3;
    M2C_FIELD(arg0, s32 *, 0x60)    = 0;
    if (arg4 != 0) {
        return;
    }
    func_0206b868(arg0, M2C_FIELD(arg1, s32 *, 0));
}
