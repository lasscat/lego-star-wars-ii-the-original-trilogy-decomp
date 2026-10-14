#include "m2c.h"

M2C_UNK func_0201b318(void *, M2C_UNK);             /* extern */

void func_0201b28c(void *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x20) != arg1) {
        M2C_FIELD(arg0, s32 *, 0x20) = arg1;
        M2C_FIELD(arg0, s32 *, 8)    = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x40);
    }
    func_0201b318(arg0, 0);
}
