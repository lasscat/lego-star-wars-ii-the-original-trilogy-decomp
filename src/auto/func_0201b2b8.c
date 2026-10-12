#include "m2c.h"

M2C_UNK func_0201b07c();                            /* extern */

void func_0201b2b8(void *arg0, s16 arg1, s32 arg2) {
    M2C_FIELD(arg0, s16 *, 0x1E) = arg1;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    if (arg1 == 0xFFFF) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + arg2);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) + arg2);
    func_0201b07c(arg0);
    if (M2C_FIELD(arg0, u8 *, 0x1A) != M2C_FIELD(arg0, u8 *, 0x1B)) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x40);
    }
}
