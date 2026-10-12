#include "m2c.h"

s32 func_020ca968();                                /* extern */
M2C_UNK func_020cec10(s32, M2C_UNK, s32, u32);      /* extern */
M2C_UNK func_020cf1b8(M2C_UNK, s32, u32);           /* extern */
extern s32 data_0210153c;

void func_020cb9fc(M2C_UNK arg0, s32 arg1, u32 arg2) {
    s32 temp_ip;

    temp_ip = func_020ca968();
    if ((data_0210153c != -1) && (arg2 > 0x1CU)) {
        func_020cec10(data_0210153c, arg0, temp_ip + arg1, arg2);
        return;
    }
    func_020cf1b8(arg0, temp_ip + arg1, arg2);
}
