#include "engine.h"
#include "m2c.h"

void func_020063d4(M2C_UNK, M2C_UNK, M2C_UNK);
void func_02006a50(M2C_UNK, M2C_UNK);
M2C_UNK func_0207b33c(M2C_UNK);

void func_0207b370(s32 arg0, s32 arg1, s32 arg2) {
    if (func_0207b33c(arg0) == 0) {
        return;
    }
    if (arg2 == 0xFA) {
        func_02006a50(arg0, (s32) (u8) arg1);
        return;
    }
    func_020063d4(arg0, (s32) (u16) arg2, 0);
}
