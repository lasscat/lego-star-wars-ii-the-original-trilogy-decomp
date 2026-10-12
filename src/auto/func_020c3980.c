#include "m2c.h"

M2C_UNK func_020cf1d8(M2C_UNK, void *, M2C_UNK);    /* extern */
extern s32 data_02101314;
extern s32 data_02101318;
extern s32 data_0210131c;

void func_020c3980(void *arg0, s32 arg1) {
    func_020cf1d8(0, arg0, 0x54);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) data_0210131c;
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) data_02101318;
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) data_02101314;
    M2C_FIELD(arg0, s32 *, 4) = arg1;
}
