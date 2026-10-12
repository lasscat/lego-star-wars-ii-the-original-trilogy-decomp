#include "m2c.h"

s32 func_0204a880(void *);                          /* extern */

void func_02016090(void *arg0, void **arg1) {
    void *temp_r1;

    temp_r1 = *arg1;
    if (M2C_FIELD(temp_r1, u16 *, 0xC) != 1) {
        return;
    }
    if (func_0204a880(temp_r1 + 0x5CE) == 0) {
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0x212) != 0x1B) {
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0x210) & 2) {
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x1BE) = 0xF;
    M2C_FIELD(arg0, u16 *, 0x210) = (u16) (M2C_FIELD(arg0, u16 *, 0x210) | 2);
}
