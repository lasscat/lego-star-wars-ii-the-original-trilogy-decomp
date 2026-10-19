#include "m2c.h"

void func_020291d4(void *arg0, u32 arg1) {
    u16 temp_r1;
    u16 temp_r1_2;

    if (arg0 == NULL) {
        return;
    }
    M2C_FIELD(arg0, u16 *, 0x5CE) = (u16) (M2C_FIELD(arg0, u16 *, 0x5CE) | (arg1 & 0xFFFF));
    temp_r1                       = M2C_FIELD(arg0, u16 *, 0x5CE);
    M2C_FIELD(arg0, s16 *, 0x5D2) = (s16) (temp_r1 & (temp_r1 ^ M2C_FIELD(arg0, u16 *, 0x5D0)));
    temp_r1_2                     = M2C_FIELD(arg0, u16 *, 0x5D0);
    M2C_FIELD(arg0, s16 *, 0x5D4) = (s16) (temp_r1_2 & (M2C_FIELD(arg0, u16 *, 0x5CE) ^ temp_r1_2));
}
