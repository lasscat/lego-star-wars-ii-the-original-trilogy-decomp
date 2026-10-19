#include "m2c.h"

s32 func_0205e824(s32);                             /* extern */
M2C_UNK func_02075b1c();                            /* extern */
M2C_UNK abort();                            /* extern */
M2C_UNK func_020e0ad4(M2C_UNK *);                   /* extern */
extern M2C_UNK data_020fec6c;

void func_02075b34(void *arg0, u32 arg1) {
    s32 temp_r0;

    if (arg1 > 0x3FFFFFFFU) {
        func_02075b1c();
    }
    temp_r0 = func_0205e824(arg1 * 4);
    if (temp_r0 == 0) {
        func_020e0ad4(&data_020fec6c);
        abort();
    }
    M2C_FIELD(arg0, s32 *, 0) = temp_r0;
    M2C_FIELD(arg0, u32 *, 8) = arg1;
}
