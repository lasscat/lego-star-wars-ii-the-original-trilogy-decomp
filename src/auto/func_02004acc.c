#include "m2c.h"

M2C_UNK func_0200c834(void *, M2C_UNK);             /* extern */

void func_02004acc(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 0x6C4);
    if (temp_r1 & 1) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x6C4) = (u8) (temp_r1 | 2);
    func_0200c834(arg0, 5);
    func_0200c834(arg0, 4);
}
