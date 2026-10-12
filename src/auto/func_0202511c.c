#include "m2c.h"

M2C_UNK func_020166c8();                            /* extern */

void func_0202511c(void *arg0) {
    if ((M2C_FIELD(arg0, u16 *, 0x212) == 0x2B) && ((s32) M2C_FIELD(arg0, s8 *, 0x1D8) < (s32) M2C_FIELD(arg0, u8 *, 0x1DC))) {
        M2C_FIELD(arg0, s8 *, 0x232) = 0;
    }
    func_020166c8();
}
