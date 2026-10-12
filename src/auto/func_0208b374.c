#include "m2c.h"

s32 func_02086e4c(M2C_UNK *);                       /* extern */
M2C_UNK func_0208b458(void *, u32);                 /* extern */
M2C_UNK func_0208c2b8(void *, void *, void *, s32, u32); /* extern */
extern M2C_UNK data_02104d90;

void func_0208b374(void *arg0, u32 arg1) {
    u32 var_r4;

    if (M2C_FIELD(arg0, s32 *, 0x78) & 0x14) {
        return;
    }
    var_r4 = arg1;
    if ((arg1 < 0x15U) && (func_02086e4c(&data_02104d90) == 0)) {
        var_r4 = 0x19;
    }
    func_0208c2b8(arg0 + 0x40, arg0 + 8, arg0 + 0x10, 0x12A, var_r4);
    if (var_r4 >= 0x15U) {
        return;
    }
    func_0208b458(arg0, arg1);
}
