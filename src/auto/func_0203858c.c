#include "m2c.h"

void func_0203858c(void *arg0) {
    void *temp_r1;

    M2C_FIELD(arg0, s8 *, 0xD)                          = 0;
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), s8 *, 0x1AD) = 1;
    temp_r1                                             = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r1, s32 *, 8)                        = (s32) (M2C_FIELD(temp_r1, s32 *, 8) | 0x200);
}
