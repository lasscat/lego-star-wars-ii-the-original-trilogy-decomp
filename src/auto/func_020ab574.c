#include "m2c.h"

s32 func_0201c814(s32);                             /* extern */
M2C_UNK func_0201c8a0(s32, void *);                 /* extern */
s32 func_0201c9e8(s32);                             /* extern */
M2C_UNK func_02064f6c();                            /* extern */
M2C_UNK func_020ab614(void *, s32);                 /* extern */
M2C_UNK func_020abc14(M2C_UNK *, u16);              /* extern */
s32 func_020abe14(M2C_UNK *, s32, s32);             /* extern */
extern M2C_UNK data_0210a07c;
extern M2C_UNK data_0210a0b4;

s32 func_020ab574(void *arg0, s32 arg1, s32 arg2) {
    if (func_0201c9e8(arg1) == 0) {
        return arg1;
    }
    func_020ab614(arg0, arg0 + 8);
    M2C_FIELD(arg0, s32 *, 8) = func_020abe14(&data_0210a0b4, M2C_FIELD(arg0, s32 *, 0xC), arg1);
    func_02064f6c();
    M2C_FIELD(arg0, u16 *, 0x14) = (u16) (M2C_FIELD(arg0, u16 *, 0x14) | 2);
    func_020abc14(&data_0210a07c, M2C_FIELD(arg0, u16 *, 0x10));
    if ((arg2 != 0) && (func_0201c814(M2C_FIELD(arg0, s32 *, 8) + 0x14) == 0)) {
        func_0201c8a0(M2C_FIELD(arg0, s32 *, 8) + 0x14, arg0);
    }
    return M2C_FIELD(arg0, s32 *, 8) + 0x14;
}
