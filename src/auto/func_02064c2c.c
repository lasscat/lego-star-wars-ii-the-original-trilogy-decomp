#include "m2c.h"
M2C_UNK func_02064cd8(s32, u32, s32, s32);
M2C_UNK func_02064d88(u16, u16, s32);
u16 func_02064eac(M2C_UNK *, u32, s32);
extern u8 data_021044fc[];

u32 func_02064c2c(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    u32 var_r8;
    u32 temp_r0;
    if (arg2 == 0) {
        var_r8 = arg1 >> 6;
    } else {
        var_r8 = arg1 >> 5;
    }
    temp_r0 = func_02064eac((M2C_UNK *) (data_021044fc + (arg3 << 7)), var_r8, 0);
    if (temp_r0 == 0xFFFFU) {
        return 0xFFFFU;
    }
    func_02064d88((u16) temp_r0, (u16) var_r8, arg3);
    if (arg0 != 0) {
        func_02064cd8(arg0, temp_r0, arg2, arg3);
    }
    return temp_r0;
}
