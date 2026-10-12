#include "m2c.h"

void func_02029398(void *arg0, void *arg1) {
    void *temp_r2;

    if (arg1 == NULL) {
        M2C_FIELD(arg0, s32 *, 0) = 0;
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 8) = 0;
        return;
    }
    temp_r2 = M2C_FIELD(arg1, void **, 0x20);
    if (temp_r2 == NULL) {
        M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(arg1, s32 *, 0xB0);
        M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg1, s32 *, 0xB4);
        M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(arg1, s32 *, 0xB8);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0) = (s32) M2C_FIELD(temp_r2, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(temp_r2, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 8) = (s32) M2C_FIELD(temp_r2, s32 *, 0xC);
}
