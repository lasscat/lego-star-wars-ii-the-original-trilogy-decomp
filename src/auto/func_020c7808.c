#include "m2c.h"
s32 func_020c6458(void *, void *);
M2C_UNK MIi_CpuClear16(M2C_UNK, void *, s32);
extern s32 data_02101308;
void func_020c7808(void *arg0, void *arg1, void *arg2) {
    s32 temp_r0_2;
    u32 var_r5;
    void *temp_r6;
    u8 temp_r0;
    void *temp_r2;
    temp_r6                     = arg2 + M2C_FIELD(arg2, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) data_02101308;
    temp_r0                     = M2C_FIELD(arg2, u8 *, 0x18);
    M2C_FIELD(arg0, u8 *, 0x19) = temp_r0;
    MIi_CpuClear16(0, arg0 + 0x1A, temp_r0 * 2);
    var_r5 = 0;
    while (var_r5 < (u32) M2C_FIELD(arg1, u8 *, 9)) {
        temp_r2   = arg1 + 8 + M2C_FIELD(arg1, u16 *, 0xE);
        temp_r0_2 = func_020c6458(temp_r6 + 4, temp_r2 + M2C_FIELD(temp_r2, u16 *, 2) + (var_r5 * 0x10));
        if (temp_r0_2 >= 0) {
            M2C_FIELD((arg0 + (temp_r0_2 * 2)), s16 *, 0x1A) = (s16) (var_r5 | 0x100);
        }
        var_r5 += 1;
    }
}
