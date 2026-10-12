#include "m2c.h"

M2C_UNK func_02063118(void *, M2C_UNK);             /* extern */

void func_02085dd0(void *arg0, void *arg1) {
    func_02063118(arg1, 0xC);
    M2C_FIELD(arg0, u8 *, 0x455D) = (u8) M2C_FIELD(arg1, u8 *, 8);
    M2C_FIELD(arg0, u8 *, 0x455E) = (u8) M2C_FIELD(arg1, u8 *, 9);
}
