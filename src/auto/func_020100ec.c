#include "m2c.h"

M2C_UNK func_02010a24(void *, u16);                 /* extern */
s32 func_0205c324();                                /* extern */
M2C_UNK func_0205c628(s32, M2C_UNK);                /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0209f55c(s32, u16);                    /* extern */
extern M2C_UNK data_020eb7b8;

void func_020100ec(void *arg0, void *arg1, s32 arg2) {
    s32 var_r0;
    void *temp_r2;
    void *temp_r2_2;

    func_0209f55c(arg0 + 0xD4, M2C_FIELD(arg1, u16 *, 4));
    if ((M2C_FIELD(arg0, u16 *, 0xC) != 0x40) && (M2C_FIELD(arg0, s32 *, 0x190) == 0)) {
        var_r0 = func_0205e80c(0x30, 0, 4);
        if (var_r0 != 0) {
            var_r0 = func_0205c324();
        }
        M2C_FIELD(arg0, s32 *, 0x190) = var_r0;
        func_02010a24(arg0, M2C_FIELD(*((M2C_UNK *) ((s8 *) &data_020eb7b8 + (arg2 * 8))), u16 *, 4));
        if (M2C_FIELD(arg0, u16 *, 0xC) & 3) {
            func_0205c628(M2C_FIELD(arg0, s32 *, 0x190), 1);
        }
    }
    temp_r2                       = M2C_FIELD(arg0, void **, 0xDC);
    temp_r2_2                     = temp_r2 + M2C_FIELD((temp_r2 + M2C_FIELD(temp_r2, u16 *, 0xE)), s32 *, 0xC);
    M2C_FIELD(arg0, s32 *, 0x1A4) = (s32) M2C_FIELD(temp_r2_2, s32 *, 0x38);
    M2C_FIELD(arg0, s16 *, 0x198) = (s16) M2C_FIELD(temp_r2_2, s16 *, 0x2C);
    M2C_FIELD(arg0, s16 *, 0x19A) = (s16) M2C_FIELD(temp_r2_2, s16 *, 0x2E);
    M2C_FIELD(arg0, s16 *, 0x19C) = (s16) M2C_FIELD(temp_r2_2, s16 *, 0x30);
    M2C_FIELD(arg0, s16 *, 0x19E) = (s16) M2C_FIELD(temp_r2_2, s16 *, 0x32);
    M2C_FIELD(arg0, s16 *, 0x1A0) = (s16) M2C_FIELD(temp_r2_2, s16 *, 0x34);
    M2C_FIELD(arg0, s16 *, 0x1A2) = (s16) M2C_FIELD(temp_r2_2, s16 *, 0x36);
    M2C_FIELD(arg0, u16 *, 0x1A8) = (u16) (M2C_FIELD(arg0, u16 *, 0x1A8) | 1);
}
