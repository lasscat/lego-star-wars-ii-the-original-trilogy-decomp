#include "m2c.h"

void func_02033d24(void *arg0) {
    void *temp_r1;
    void *temp_r2;

    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    temp_r2 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r2, s32 *, 8) = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | 0x200);
    temp_r1 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r1, s32 *, 8) = (s32) (M2C_FIELD(temp_r1, s32 *, 8) | 0x800000);
}
