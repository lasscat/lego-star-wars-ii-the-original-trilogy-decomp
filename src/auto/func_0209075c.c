#include "m2c.h"

M2C_UNK func_020675d8(s32, u8);                     /* extern */
M2C_UNK func_0206763c(s32, u8);                     /* extern */

void func_0209075c(void *arg0, s32 arg1) {
    u8 *p = (u8 *) arg0 + 0x3E8 + (arg1 * 8);

    if (--*(s32 *) p == 0) {
        if (p[6] != 0) {
            func_0206763c(M2C_FIELD(M2C_FIELD(arg0, void **, 0x38C), s32 *, 4) + 0x28, p[6]);
        }
        if (p[7] != 0) {
            func_020675d8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x38C), s32 *, 4) + 0x28, p[7]);
        }
    }
    if (p[5] != 0) {
        func_020675d8(M2C_FIELD(M2C_FIELD(arg0, void **, 0x38C), s32 *, 4) + 0x28, p[5]);
    }
}
