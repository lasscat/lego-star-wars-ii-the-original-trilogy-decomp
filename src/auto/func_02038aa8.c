#include "m2c.h"

void func_02038aa8(void *arg0) {
    s32 temp_r1;
    void *temp_r0;

    M2C_FIELD(arg0, s8 *, 0x19) = 1;
    temp_r0 = M2C_FIELD(arg0, void **, 0x10);
    temp_r1 = M2C_FIELD(temp_r0, s32 *, 0x194);
    if (temp_r1 & 0x01400000) {
        return;
    }
    if (temp_r1 == 0) {
        return;
    }
    if (M2C_FIELD(temp_r0, u16 *, 0xC) != 4) {
        return;
    }
    M2C_FIELD(M2C_FIELD(temp_r0, void **, 0), M2C_UNK (**)(void *, s32), 0x3C)(temp_r0, M2C_FIELD(arg0, s32 *, 4));
}
