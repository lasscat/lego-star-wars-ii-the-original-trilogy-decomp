#include "m2c.h"
M2C_UNK func_0200c7dc(s32);
void *func_0208dad8(u16);
void func_02006a50(s32 arg0, s32 arg1) {
    s32 temp_r0;
    void *temp_r0_2;
    temp_r0 = M2C_FIELD((arg0 + (arg1 * 2)), u16 *, 0x6E8);
    if (temp_r0 == 0xFA) {
        return;
    }
    temp_r0_2 = func_0208dad8((u16) temp_r0);
    if (M2C_FIELD(((M2C_FIELD(temp_r0_2, u8 *, 9) * 0x28) + arg0), s32 *, 0x1D0) != 0) {
        func_0200c7dc(arg0);
    }
    M2C_FIELD((arg0 + (M2C_FIELD(temp_r0_2, u8 *, 8) * 2)), s16 *, 0x6E8) = 0xFA;
}
