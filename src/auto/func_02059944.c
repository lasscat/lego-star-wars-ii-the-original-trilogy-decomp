#include "m2c.h"

void *func_02067080(M2C_UNK, u8, u8);               /* extern */

void func_02059944(M2C_UNK arg0, void *arg1) {
    void *temp_r0;

    temp_r0 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    if (temp_r0 == NULL) {
        return;
    }
    if (((M2C_FIELD(temp_r0, u16 *, 0xC) & 1) | 2) == 0) {
        return;
    }
    M2C_FIELD(temp_r0, s16 *, 0x6B6) = (s16) M2C_FIELD(arg1, u8 *, 2);
    M2C_FIELD(temp_r0, s16 *, 0x6B8) = (s16) M2C_FIELD(arg1, u8 *, 2);
}
