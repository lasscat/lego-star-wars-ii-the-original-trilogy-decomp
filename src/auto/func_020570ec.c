#include "m2c.h"

M2C_UNK func_020675d8(s32, u8);                     /* extern */
M2C_UNK func_0206763c(s32, u8);                     /* extern */
extern s32 data_027e02a8;

void func_020570ec(void *arg0, void *arg1) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 4);
    if (data_027e02a8 & 0x40) {
        func_0206763c(temp_r0 + 0x28, M2C_FIELD(arg1, u8 *, 0));
        func_020675d8(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 1));
        return;
    }
    func_0206763c(temp_r0 + 0x28, M2C_FIELD(arg1, u8 *, 2));
    func_020675d8(M2C_FIELD(arg0, s32 *, 4) + 0x28, M2C_FIELD(arg1, u8 *, 3));
}
