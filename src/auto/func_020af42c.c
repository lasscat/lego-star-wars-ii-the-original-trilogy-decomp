#include "m2c.h"

M2C_UNK func_020cdd40(s32, M2C_UNK);                /* extern */
M2C_UNK func_020cf3dc(s32, s32, M2C_UNK);           /* extern */

void func_020af42c(s32 arg0) {
    func_020cdd40(arg0 + 0x40, 0x200);
    func_020cf3dc(arg0 + 0x640, arg0 + 0x40, 0x70);
    func_020cdd40(arg0 + 0x40, 0x70);
}
