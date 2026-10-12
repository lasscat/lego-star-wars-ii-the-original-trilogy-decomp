#include "m2c.h"

M2C_UNK func_02063118(M2C_UNK *, M2C_UNK);          /* extern */
s32 func_0206316c(s8);                              /* extern */
M2C_UNK func_02085948();                            /* extern */
M2C_UNK func_02085dd0(s32, s32);                    /* extern */
M2C_UNK func_0208c830(s32);                         /* extern */
M2C_UNK func_0208f108(s32);                         /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02104364;
extern M2C_UNK data_02104388;
extern s32 data_027e02a8;

s32 func_02085e88(s32 arg0, s8 arg1) {
    M2C_UNK sp0;

    func_02085948();
    data_027e02a8 |= 0x100;
    M2C_FIELD(&data_02104364, s8 *, 0x4E) = arg1;
    if (func_0206316c(arg1) == 0) {
        return 0;
    }
    func_02085dd0(arg0, (arg1 * 0xC) + (s32) &data_02104388);
    func_0208f108((M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 0xC) + (arg0 + 4));
    func_0208c830(arg0 + 0x34);
    func_02063118(arg0 + 0x52, 0x12);
    func_02063118(arg0 + 0x4488, 8);
    func_02063118(arg0 + 0x44CC, 0xD);
    func_02063118(arg0 + 0x44DC, 0xD);
    func_02063118(arg0 + 0x44EC, 0x20);
    func_02063118(arg0 + 0x450C, 5);
    func_02063118(arg0 + 0x4514, 4);
    func_02063118(arg0 + 0x4518, 4);
    func_02063118(arg0 + 0x451C, 3);
    func_02063118(arg0 + 0x4520, 3);
    func_02063118(&sp0, 4);
    return 1;
}
