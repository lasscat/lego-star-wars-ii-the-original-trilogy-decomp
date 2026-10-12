#include "m2c.h"

M2C_UNK func_020aa7c0(s32, s32);                    /* extern */
s32 func_020aaeb4();                                /* extern */
extern M2C_UNK data_020fe240;

void *func_02042d30(void *arg0) {
    s32 temp_r4;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fe240;
    temp_r4 = M2C_FIELD(arg0, s32 *, 0x14);
    if (temp_r4 != 0) {
        func_020aa7c0(func_020aaeb4(), temp_r4);
    }
    return arg0;
}
