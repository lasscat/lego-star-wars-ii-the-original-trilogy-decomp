#include "m2c.h"

M2C_UNK func_020cf27c(s32, s32);                    /* extern */
M2C_UNK MI_CpuCopy8(s32, s32);                    /* extern */

s32 func_0205e6e0(s32 arg0, s32 arg1, s32 arg2) {
    if (!(arg0 & 3) && !(arg1 & 3) && !(arg2 & 3)) {
        func_020cf27c(arg1, arg0);
    } else {
        MI_CpuCopy8(arg1, arg0);
    }
    return arg0;
}
