#include "m2c.h"

void func_02090858(s32 arg0, s32 arg1, void *arg2) {
    void *temp_r1;

    temp_r1                          = arg0 + (arg1 * 8);
    M2C_FIELD(temp_r1, s32 *, 0x3E8) = (s32) M2C_FIELD(arg2, s32 *, 0);
    M2C_FIELD(temp_r1, u8 *, 0x3EC)  = (u8) M2C_FIELD(arg2, u8 *, 4);
    M2C_FIELD(temp_r1, u8 *, 0x3ED)  = (u8) M2C_FIELD(arg2, u8 *, 5);
    M2C_FIELD(temp_r1, u8 *, 0x3EE)  = (u8) M2C_FIELD(arg2, u8 *, 6);
    M2C_FIELD(temp_r1, u8 *, 0x3EF)  = (u8) M2C_FIELD(arg2, u8 *, 7);
}
