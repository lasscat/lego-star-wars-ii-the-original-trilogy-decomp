#include "engine.h"
#include "m2c.h"

void func_020ceb20(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020cf1f0(M2C_UNK, M2C_UNK, M2C_UNK);

extern s32 data_0210153c;

void func_020cb894(s32 arg0, s32 arg1, s32 arg2) {
    if ((data_0210153c != -1) && ((u32) arg2 > 0x30U)) {
        func_020ceb20(data_0210153c, arg0, arg1 + 0x07000400, arg2);
        return;
    }
    func_020cf1f0(arg0, arg1 + 0x07000400, arg2);
}
