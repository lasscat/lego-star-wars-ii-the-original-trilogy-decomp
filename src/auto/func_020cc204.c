#include "m2c.h"

M2C_UNK func_020ced40(s32, M2C_UNK, s32, s32, s32, s32); /* extern */
M2C_UNK func_020cf1f0(M2C_UNK, s32);                /* extern */
extern s32 data_0210153c;

void func_020cc204(M2C_UNK arg0, s32 arg1, s32 arg2) {
    if (data_0210153c != -1) {
        func_020ced40(data_0210153c, arg0, arg1 + 0x06898000, arg2, 0, 0);
        return;
    }
    func_020cf1f0(arg0, arg1 + 0x06898000);
}
