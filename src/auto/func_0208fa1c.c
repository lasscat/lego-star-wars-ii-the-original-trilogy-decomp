#include "m2c.h"

void func_0208fa1c(void *arg0, s8 arg1, s8 arg2, s16 arg3) {
    M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 0x47C) * 4)), s16 *, 0x47E) = arg3;
    M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 0x47C) * 4)), s8 *, 0x480)  = arg1;
    M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 0x47C) * 4)), s8 *, 0x481)  = arg2;
    M2C_FIELD(arg0, u8 *, 0x47C)                                         = (u8) (M2C_FIELD(arg0, u8 *, 0x47C) + 1);
}
