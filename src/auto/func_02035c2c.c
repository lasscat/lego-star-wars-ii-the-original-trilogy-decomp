#include "m2c.h"

M2C_UNK func_0205e624(s32, M2C_UNK, M2C_UNK);       /* extern */
s8 func_020935f8(M2C_UNK *, s8, void *);            /* extern */
extern M2C_UNK data_0210930c;

void func_02035c2c(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    s32 sp4;
    s32 sp0;
    void **temp_r1;

    func_0205e624(arg0 + 0x54, 0, 0x10);
    M2C_FIELD(arg0, s8 *, 0x30) = 6;
    temp_r1                     = M2C_FIELD(arg0, void ***, 4);
    M2C_FIELD(*temp_r1, M2C_UNK(**)(s32 *, void **, M2C_UNK), 0x3C)(&sp4, temp_r1, 6);
    M2C_FIELD(arg0, s32 *, 0x10) = sp4;
    temp_r1                      = M2C_FIELD(arg0, void ***, 4);
    M2C_FIELD(*temp_r1, M2C_UNK(**)(s32 *, void **, M2C_UNK), 0x3C)(&sp0, temp_r1, 6);
    M2C_FIELD(arg0, s32 *, 0x14) = sp0;
    M2C_FIELD(arg0, s8 *, 0x1C)  = arg3;
    M2C_FIELD(arg0, s8 *, 0x1D)  = 0;
    M2C_FIELD(arg0, s8 *, 0x5C)  = arg1;
    M2C_FIELD(arg0, s8 *, 0x5D)  = func_020935f8(&data_0210930c, arg1, (u8 *) M2C_FIELD(arg0, void **, 4) + 0xB0);
    M2C_FIELD(arg0, s8 *, 0x5E)  = arg2;
}
