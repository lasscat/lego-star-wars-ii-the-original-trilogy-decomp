#include "m2c.h"

s32 func_02018420(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_0202d900();                            /* extern */
extern M2C_UNK data_020fdd84;
extern M2C_UNK data_02101ae4;

void *func_0202f864(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp0;
    void **temp_r1;

    func_0202d900();
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdd84;
    M2C_FIELD(arg0, s32 *, 0x10)   = 0;
    M2C_FIELD(arg0, s32 *, 0x14)   = 0;
    M2C_FIELD(arg0, s16 *, 0x18)   = 0;
    M2C_FIELD(arg0, s16 *, 0x1A)   = 0;
    M2C_FIELD(arg0, s8 *, 0x1C)    = 1;
    M2C_FIELD(arg0, s8 *, 0x1D)    = 1;
    M2C_FIELD(arg0, s8 *, 0x1E)    = 0;
    M2C_FIELD(arg0, s8 *, 0x1F)    = 0;
    M2C_FIELD(arg0, s8 *, 0x20)    = 0;
    M2C_FIELD(arg0, s32 *, 0x24)   = 0;
    M2C_FIELD(arg0, s32 *, 0x28)   = 0;
    M2C_FIELD(arg0, s32 *, 0x2C)   = 0;
    temp_r1                        = M2C_FIELD(arg0, void ***, 4);
    M2C_FIELD(*temp_r1, M2C_UNK(**)(s32 *, void **, M2C_UNK), 0x3C)(&sp0, temp_r1, 6);
    M2C_FIELD(arg0, s32 *, 0x14) = sp0;
    if (arg3 != 0) {
        M2C_FIELD(arg0, s32 *, 0x24) = func_02018420(&data_02101ae4, 1);
        M2C_FIELD(arg0, s32 *, 0x28) = func_02018420(&data_02101ae4, 2);
    }
    return arg0;
}
