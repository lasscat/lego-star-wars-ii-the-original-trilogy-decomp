#include "m2c.h"

M2C_UNK func_020ced40(s32, M2C_UNK, s32, s32, s32, s32); /* extern */
M2C_UNK func_020cf1f0(M2C_UNK, s32, s32);                /* extern */
extern s32 data_0210153c;
extern M2C_UNK data_021153a0;

void func_020cc728(M2C_UNK arg0, M2C_UNK arg1) {
    s32 off = M2C_FIELD(&data_021153a0, s32 *, 0x10) + 0x20000;
    if (data_0210153c != -1) {
        func_020ced40(data_0210153c, arg0, off, arg1, 0, 0);
        return;
    }
    func_020cf1f0(arg0, off, arg1);
}
