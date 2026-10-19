#include "m2c.h"
M2C_UNK func_020ced40(s32, M2C_UNK, s32, s32, s32, s32);
M2C_UNK func_020cf1f0(M2C_UNK, s32, s32);
extern s32 data_0210153c;
extern M2C_UNK data_021153a0;
void func_020cc580(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 off = M2C_FIELD(&data_021153a0, s32 *, 8) + arg1;
    if (data_0210153c != -1) {
        func_020ced40(data_0210153c, arg0, off, arg2, 0, 0);
        return;
    }
    func_020cf1f0(arg0, off, arg2);
}
