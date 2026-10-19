#include "m2c.h"

M2C_UNK func_020261fc();                            /* extern */

void func_02026318(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x1BC) == 1) {
        M2C_FIELD(arg0, u8 *, 0x1BC) = 0U;
        M2C_FIELD(arg0, s32 *, 8) |= 1;
        M2C_FIELD(arg0, s8 *, 0x217) = 1;
    } else {
        M2C_FIELD(arg0, u8 *, 0x1BC) = 1U;
        M2C_FIELD(arg0, s32 *, 8) &= ~1;
        M2C_FIELD(arg0, s8 *, 0x217) = 0;
    }
    func_020261fc();
}
