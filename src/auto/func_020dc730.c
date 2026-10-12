#include "m2c.h"

M2C_UNK func_020d6b1c(s32);                         /* extern */
s32 func_020d7134(s32, s32, u16);                   /* extern */
M2C_UNK func_020db378();                            /* extern */
M2C_UNK func_020dcc94(M2C_UNK);                     /* extern */
extern M2C_UNK data_0211e400;

s32 func_020dc730(void) {
    s32 temp_r0;

    M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s16 *, 0x528) = 0;
    M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s16 *, 0x52A) = 0;
    M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s16 *, 0x526) = 0;
    M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s16 *, 0x548) = 0;
    func_020dcc94(0xA);
    if (M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 0xC), s32 *, 0x1320) == 0) {
        do {
            temp_r0 = func_020d7134(M2C_FIELD(&data_0211e400, s32 *, 4), M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s32 *, 0x508), M2C_FIELD(&data_0211e400, u16 *, 0));
        } while (temp_r0 == 4);
        if (temp_r0 != 2) {
            return 8;
        }
        func_020d6b1c(M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s32 *, 0x508));
        M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s8 *, 0x50D) = 1;
        return 0;
    }
    func_020d6b1c(M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s32 *, 0x508));
    M2C_FIELD(M2C_FIELD(&data_0211e400, void **, 8), s8 *, 0x50D) = 1;
    func_020db378();
    return 0;
}
