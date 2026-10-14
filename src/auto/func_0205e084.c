#include "m2c.h"

void func_0205e084(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    M2C_FIELD(arg2, s32 *, 4)    = (s32) M2C_FIELD(arg0, s32 *, 0x18);
    M2C_FIELD(arg0, s32 *, 0x18) = arg1;
    M2C_FIELD(arg0, u16 *, 0x1E) = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + arg3);
}
