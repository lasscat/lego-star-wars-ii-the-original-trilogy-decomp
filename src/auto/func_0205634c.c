#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);               /* extern */

void func_0205634c(M2C_UNK arg0, void *arg1) {
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    if (M2C_FIELD(arg1, u8 *, 2) != 0) {
        M2C_FIELD(temp_r0, s32 *, 8) = (s32) (M2C_FIELD(temp_r0, s32 *, 8) | 0x20);
        return;
    }
    M2C_FIELD(temp_r0, s32 *, 8)   = (s32) (M2C_FIELD(temp_r0, s32 *, 8) & ~0x20);
    M2C_FIELD(temp_r0, s8 *, 0x40) = 0;
}
