#include "engine.h"
#include "m2c.h"

void func_02006ad0(s32 arg0, s32 arg1) {
    s16 temp_r2;

    M2C_FIELD(arg0, s16 *, 0x6B6) = (s16) (M2C_FIELD(arg0, s16 *, 0x6B6) + (u8) arg1);
    temp_r2                       = M2C_FIELD(arg0, s16 *, 0x6B8);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x6B6) > (s32) temp_r2) {
        M2C_FIELD(arg0, s16 *, 0x6B6) = temp_r2;
    }
}
