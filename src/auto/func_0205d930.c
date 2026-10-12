#include "m2c.h"
#include "engine.h"

void func_0205d57c(M2C_UNK, M2C_UNK, M2C_UNK);
void func_0205d9a8(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_0205e2a4(M2C_UNK);

void func_0205d930(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r1;
    s32 var_r5;

    var_r5 = arg2;
    var_r1 = func_0205e2a4(M2C_FIELD(arg0, s32 *, 0x14));
    if (var_r1 != 0) {
        var_r1 += 4;
    }
    *(M2C_UNK *)var_r1 = arg1;
    switch (arg3) {                                 /* irregular */
    case 0:
        if (var_r5 != 0) {
            var_r5 += 4;
        }
        func_0205d57c(arg0, var_r1, var_r5);
        break;
    case 1:
        if (var_r1 != 0) {
            var_r1 -= 4;
        }
        func_0205d9a8(arg0, var_r1, var_r5);
        break;
    }
    M2C_FIELD(arg0, u16 *, 0xC) = (u16) (M2C_FIELD(arg0, u16 *, 0xC) + 1);
}
