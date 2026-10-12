#include "m2c.h"

s32 func_020047d4(void *);                          /* extern */
M2C_UNK func_0200c848(void *, M2C_UNK);             /* extern */

void func_02004b00(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x6C4);
    if (temp_r1 & 1) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x6C4) = (u8) (temp_r1 & ~2);
    func_0200c848(arg0, 5);
    if (func_020047d4(arg0) == 0) {
        return;
    }
    func_0200c848(arg0, 4);
}
