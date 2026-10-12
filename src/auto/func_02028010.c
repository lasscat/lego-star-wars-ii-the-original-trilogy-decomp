#include "m2c.h"
#include "engine.h"

void func_02028010(s32 arg0, s32 arg1, s32 arg2) {
    u16 temp_r2;
    u16 temp_r2_2;

    if (M2C_FIELD(arg0, s32 *, 0) & arg2) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | arg2);
    M2C_FIELD(arg1, u16 *, 0x5CE) = (u16) (M2C_FIELD(arg1, u16 *, 0x5CE) | (u16) arg2);
    temp_r2 = M2C_FIELD(arg1, u16 *, 0x5CE);
    M2C_FIELD(arg1, s16 *, 0x5D2) = (s16) (temp_r2 & (temp_r2 ^ M2C_FIELD(arg1, u16 *, 0x5D0)));
    temp_r2_2 = M2C_FIELD(arg1, u16 *, 0x5D0);
    M2C_FIELD(arg1, s16 *, 0x5D4) = (s16) (temp_r2_2 & (M2C_FIELD(arg1, u16 *, 0x5CE) ^ temp_r2_2));
}
