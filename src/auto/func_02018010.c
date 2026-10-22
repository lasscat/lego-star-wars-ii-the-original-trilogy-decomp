#include "m2c.h"

M2C_UNK func_0201811c(M2C_UNK, M2C_UNK, s32, s32);  /* extern */

s32 func_02018010(void *arg0, u16 arg1, u16 arg2) {
    u16 buf[2];
    s32 diff;

    func_0201811c(&buf[1], arg0, arg1, 0);
    buf[0] = M2C_FIELD(arg0, u16 *, 0xca);
    diff   = (s16) (u16) (buf[1] - buf[0]);
    if (diff < 0) {
        diff = -diff;
    }
    return *(volatile u16 *) &arg2 > (u16) diff;
}
