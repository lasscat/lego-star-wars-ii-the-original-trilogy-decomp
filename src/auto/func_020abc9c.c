#include "m2c.h"

M2C_UNK func_0201c7a0(s32, M2C_UNK);                /* extern */
s32 func_0201c828(s32);                             /* extern */
M2C_UNK func_02064f48();                            /* extern */
M2C_UNK func_02064ff0(void *, void *);              /* extern */

void *func_020abc9c(void *arg0, void *arg1, M2C_UNK arg2) {
    s32 var_r4;

    func_02064f48();
    func_0201c7a0(arg0 + 0x14, arg2);
    M2C_FIELD(arg0, volatile s32 *, 0x10) = func_0201c828(arg0 + 0x14);
    if (M2C_FIELD(arg1, volatile u16 *, 0x10) & 1) {
        var_r4 = 1;
    } else {
        var_r4 = 0;
    }
    if (var_r4 != 0) {
        M2C_FIELD(arg1, volatile u16 *, 0x10) = (u16) (M2C_FIELD(arg1, volatile u16 *, 0x10) & ~1);
        M2C_FIELD(arg1, volatile u16 *, 0x20) = (u16) (M2C_FIELD(arg1, volatile u16 *, 0x20) & ~1);
        M2C_FIELD(arg1, volatile u16 *, 0x32) = (u16) (M2C_FIELD(arg1, volatile u16 *, 0x32) & ~1);
    }
    func_02064ff0(arg0, arg1);
    if (var_r4 != 0) {
        M2C_FIELD(arg1, volatile u16 *, 0x10) = (u16) (M2C_FIELD(arg1, volatile u16 *, 0x10) | 1);
        M2C_FIELD(arg1, volatile u16 *, 0x20) = (u16) (M2C_FIELD(arg1, volatile u16 *, 0x20) | 1);
        M2C_FIELD(arg1, volatile u16 *, 0x32) = (u16) (M2C_FIELD(arg1, volatile u16 *, 0x32) | 1);
    }
    M2C_FIELD(arg0, volatile u16 *, 0x14) = (u16) (M2C_FIELD(arg0, volatile u16 *, 0x14) | 0x20);
    return arg0;
}
