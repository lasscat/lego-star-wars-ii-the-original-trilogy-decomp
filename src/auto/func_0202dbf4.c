#include "m2c.h"

typedef struct {
    u16 v;
} S16;

M2C_UNK func_0202c118(s32, s32, M2C_UNK, M2C_UNK);
s32 func_02032a30(s32, s32, M2C_UNK, s16, S16, s32);
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);

s32 func_0202dbf4(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    S16 sp8;
    s32 temp_r0;
    s32 var_r4;
    temp_r0 = func_0205e80c(0x1C, 1, 4);
    var_r4  = temp_r0;
    if (var_r4 != 0) {
        sp8.v  = 0x38E;
        var_r4 = func_02032a30(temp_r0, arg0, arg2, 0xF5, sp8, 0);
    }
    func_0202c118(arg0 + 0x5E0, var_r4, arg1, 1);
    return var_r4;
}
