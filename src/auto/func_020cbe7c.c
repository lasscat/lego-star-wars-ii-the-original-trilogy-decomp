#include "m2c.h"

s32 func_020cacc4();                                /* extern */
M2C_UNK func_020ceb20(s32, M2C_UNK, s32, u32);      /* extern */
M2C_UNK func_020cf1f0(M2C_UNK, s32, u32);           /* extern */
extern s32 data_0210153c;

void func_020cbe7c(M2C_UNK arg0, s32 arg1, u32 arg2) {
    s32 temp_ip;

    temp_ip = func_020cacc4();
    if ((data_0210153c != -1) && (arg2 > 0x30U)) {
        func_020ceb20(data_0210153c, arg0, temp_ip + arg1, arg2);
        return;
    }
    func_020cf1f0(arg0, temp_ip + arg1, arg2);
}
