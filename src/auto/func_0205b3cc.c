#include "m2c.h"
M2C_UNK func_0205af6c(s32 *, s32, M2C_UNK);
M2C_UNK func_0205b488(M2C_UNK *, s32, s32);
s32 func_0205b3cc(s32 arg0, M2C_UNK arg1) {
    s32 sp8;
    M2C_UNK sp4;
    volatile s32 sp0;
    func_0205af6c(&sp8, arg0, arg1);
    if (sp8 == (arg0 + 4)) {
        return 0;
    }
    sp0 = sp8;
    func_0205b488(&sp4, arg0, sp8);
    return 1;
}
