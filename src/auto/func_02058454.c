#include "m2c.h"
M2C_UNK func_020675d8(s32, u8);
M2C_UNK func_0206763c(s32, u8);
void func_02058454(void *arg0, u32 arg1, u32 arg2, u32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    s32 temp_r0;
    s32 var_r0;
    switch (arg2) {
        case 2:
            var_r0 = (arg1 == arg3);
            break;
        case 5:
            var_r0 = (arg1 != arg3);
            break;
        case 4:
            var_r0 = (arg1 > arg3);
            break;
        case 3:
            var_r0 = (arg1 >= arg3);
            break;
        case 0:
            var_r0 = (arg1 < arg3);
            break;
        case 1:
            var_r0 = (arg1 <= arg3);
            break;
        case 6:
            var_r0 = 0;
            break;
        default:
            var_r0 = 0;
            break;
    }
    temp_r0 = M2C_FIELD(arg0, s32 *, 4);
    if (var_r0 != 0) {
        func_0206763c(temp_r0 + 0x28, arg6);
        if (arg4 == 0) {
            return;
        }
        func_020675d8(M2C_FIELD(arg0, s32 *, 4) + 0x28, arg4);
        return;
    }
    func_0206763c(temp_r0 + 0x28, arg7);
    if (arg5 == 0) {
        return;
    }
    func_020675d8(M2C_FIELD(arg0, s32 *, 4) + 0x28, arg5);
}
