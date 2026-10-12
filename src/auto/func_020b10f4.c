#include "m2c.h"

M2C_UNK func_02072900(s32);                         /* extern */
M2C_UNK func_020730d0(M2C_UNK);                     /* extern */

void func_020b10f4(void *arg0) {
    func_02072900(0x28D);
    func_020730d0(2);
    M2C_FIELD(arg0, s8 *, 7) = 1;
}
