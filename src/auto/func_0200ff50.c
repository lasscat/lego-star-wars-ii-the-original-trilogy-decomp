#include "m2c.h"

M2C_UNK func_020101cc(void *, s32);                 /* extern */
M2C_UNK func_02017908(void *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_0209f404(void *);                      /* extern */
extern M2C_UNK data_020fcf78;
extern s32 data_02101ad4;

void *func_0200ff50(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    s32 temp_r3;

    func_02017908(arg0, arg1, arg3, arg4);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fcf78;
    func_0209f404(arg0 + 0xD4);
    M2C_FIELD(arg0, s32 *, 0x190) = 0;
    M2C_FIELD(arg0, s32 *, 0x194) = 0;
    M2C_FIELD(arg0, s32 *, 0x1A4) = 0;
    M2C_FIELD(arg0, s16 *, 0x1A8) = 0;
    M2C_FIELD(arg0, s16 *, 0x1AA) = 0x3C;
    M2C_FIELD(arg0, s8 *, 0x1AC) = 0x32;
    M2C_FIELD(arg0, s8 *, 0x1AD) = 0;
    M2C_FIELD(arg0, s8 *, 0x1AE) = 0x1F;
    M2C_FIELD(arg0, s8 *, 0x1AF) = 1;
    M2C_FIELD(arg0, s8 *, 0x1B2) = 3;
    M2C_FIELD(arg0, s32 *, 0x1B8) = 0;
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x100001);
    if (arg2 != 0x276) {
        func_020101cc(arg0, arg2);
    }
    temp_r3 = data_02101ad4;
    data_02101ad4 = temp_r3 + 1;
    M2C_FIELD(arg0, s32 *, 0x1B4) = temp_r3;
    return arg0;
}
