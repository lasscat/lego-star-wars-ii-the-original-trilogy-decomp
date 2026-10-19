#include "m2c.h"

s32 func_02052f9c();
M2C_UNK func_02052fd8();
s32 CARDi_RequestStreamCommand(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32);

s32 func_02052f0c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 var_r7;
    s32 var_r6;

    if (func_02052f9c() == 0) {
        return 0;
    }
    var_r6 = 2;
    do {
        var_r7 = CARDi_RequestStreamCommand(arg2, arg0, arg1, 0, 0, 0, 8, 0xA, 2) != 0;
    } while (var_r7 == 0 && var_r6-- > 0);
    func_02052fd8();
    return var_r7;
}
