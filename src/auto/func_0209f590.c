#include "m2c.h"

M2C_UNK func_0209f5d0();                            /* extern */
M2C_UNK func_020acba8(void *);                      /* extern */

void func_0209f590(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, u16 *, 0xB2) << 0x1F) >> 0x1F) == 0) {
        return;
    }
    func_0209f5d0(arg0);
    func_020acba8(arg0);
    M2C_FIELD(arg0, s16 *, 0xAC) = 0x276;
    M2C_FIELD(arg0, u16 *, 0xB2) = (u16) (M2C_FIELD(arg0, u16 *, 0xB2) & ~1);
}
