#include "m2c.h"

M2C_UNK func_020ad528(M2C_UNK *, s32);
M2C_UNK func_020ad7a4(M2C_UNK);
s32 func_020ae910();
M2C_UNK func_020cdd40(M2C_UNK *, M2C_UNK);
M2C_UNK func_020cf3dc(M2C_UNK, M2C_UNK *, M2C_UNK);
extern M2C_UNK data_02100014;
extern M2C_UNK data_0210b320;
extern M2C_UNK data_0210b460;

s32 func_020adbcc(s32 arg0, s32 arg1, M2C_UNK arg2, s8 arg3) {
    M2C_FIELD(&data_0210b320, s32 *, 0x44) = arg1;
    M2C_FIELD(&data_0210b320, s8 *, 0)     = arg3;
    func_020ad7a4(3);
    if ((arg1 == 1) || (arg1 == 3) || (arg1 == 5)) {
        func_020cf3dc(arg2, &data_0210b460, 0xC0);
        func_020cdd40(&data_0210b460, 0xC0);
        return func_020ae910();
    }
    func_020ad528(&data_02100014, arg1);
    return 1;
}
