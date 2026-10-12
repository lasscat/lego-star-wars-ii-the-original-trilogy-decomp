#include "m2c.h"

void *func_020531d8(M2C_UNK);                       /* extern */

void func_02053aac(void *arg0, M2C_UNK arg1) {
    void *temp_r0;

    temp_r0 = func_020531d8(arg1);
    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(temp_r0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(temp_r0, s32 *, 0xC);
}
