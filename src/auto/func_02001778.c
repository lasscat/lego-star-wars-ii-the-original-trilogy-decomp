#include "m2c.h"

extern M2C_UNK data_020fcc68;
extern M2C_UNK data_021019f4;

M2C_UNK func_02001778(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s8 *temp_r0;
    M2C_FIELD(arg0, s32 *, 4)      = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fcc68;
    M2C_FIELD(arg0, s32 *, 8)      = 0;
    M2C_FIELD(arg0, u16 *, 0xc)    = arg1;
    M2C_FIELD(arg0, u8 *, 0xe)     = 0xff;
    M2C_FIELD(arg0, u8 *, 0xf)     = 0;
    if (arg2 == 0) {
        M2C_FIELD(arg0, s32 *, 8) = 0x80000000;
    }
    temp_r0 = (s8 *) &data_021019f4 + arg2 * 0x38;
    M2C_FIELD(M2C_FIELD(temp_r0 - (s8 *) 0, void **, 0), M2C_UNK(**)(s8 *, void *), 0x8)(temp_r0, arg0);
    return (M2C_UNK) arg0;
}
