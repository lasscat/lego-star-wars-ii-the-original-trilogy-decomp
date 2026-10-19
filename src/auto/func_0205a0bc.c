#include "m2c.h"

s32 func_0205a348();                          /* extern */
M2C_UNK NNS_GfdRegisterNewVramTransferTask();      /* extern */

void func_0205a0bc(void *arg0, s32 arg1) {
    s32 var_r4;
    u32 temp_r5;

    if (M2C_FIELD(arg0, u8 *, 9) == 0) {
        return;
    }
    var_r4 = M2C_FIELD(arg0, s32 *, 0);
    if (arg1 != 0) {
        var_r4 += arg1 * func_0205a348(arg0);
    }
    temp_r5 = (u32) (M2C_FIELD(arg0, s32 *, 0x10) << 0x10) >> 0xD;
    NNS_GfdRegisterNewVramTransferTask(0, temp_r5, var_r4, func_0205a348(arg0));
}
