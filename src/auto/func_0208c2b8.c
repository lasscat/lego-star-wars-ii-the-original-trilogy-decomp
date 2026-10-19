#include "m2c.h"

M2C_UNK func_0208c360(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32);

void func_0208c2b8(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4) {
    s32 var_lr;

    if (arg4 < 0x15) {
        func_0208c360(arg0, 0, arg1, arg2, arg3, 1, 0x535, arg4 + 0x115);
        return;
    }
    var_lr = 0x2D9;
    if (arg4 == 0x17) {
        var_lr = 0x2DC;
    } else if (arg4 == 0x18) {
        var_lr += 6;
    } else if (arg4 == 0x19) {
        var_lr = 0x294;
    }
    func_0208c360(arg0, 0, arg1, arg2, arg3, 1, var_lr, 0x535);
}
