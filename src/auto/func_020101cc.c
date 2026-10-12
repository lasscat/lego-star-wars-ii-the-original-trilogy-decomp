#include "m2c.h"
#include "engine.h"

void func_020100ec(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_020eb7b8;

void func_020101cc(s32 arg0, s32 arg1) {
    func_020100ec(arg0, (s32) ((M2C_UNK *)((s8 *)&data_020eb7b8 + (arg1 * 8))), arg1);
}
