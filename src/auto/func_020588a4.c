#include "m2c.h"

s32 func_02062b3c(u8);                              /* extern */
M2C_UNK func_0206763c(s32, u8);                     /* extern */
M2C_UNK func_020675d8(s32, u8);                     /* extern */

void func_020588a4(void *arg0, void *arg1) {
    if (func_02062b3c(M2C_FIELD(arg1, u8 *, 0)) != 0) {
        func_0206763c(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 2));
        func_020675d8(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 1));
        return;
    }
    func_0206763c(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 4));
    func_020675d8(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 3));
}
