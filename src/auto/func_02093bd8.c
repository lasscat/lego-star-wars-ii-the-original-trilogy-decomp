#include "m2c.h"

s32 func_0205d0d0(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02102900;
extern s32 data_027e02a8;

s32 func_02093bd8(s32 arg0) {
    s32 var_r1;
    s32 var_r0;
    u8 var_field;

    if (!(data_027e02a8 & 0x30) && (func_0205d0d0(&data_021027f8, 8, 4) != 0)) {
        var_field = M2C_FIELD(M2C_FIELD((arg0 + (M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 4)), void **, 0x4C), u8 *, 0x5D6);
        if (M2C_FIELD(&data_02102900, void **, 4) != NULL) {
            var_r1 = M2C_FIELD(M2C_FIELD(&data_02102900, void **, 4), s32 *, 4);
        } else {
            var_r1 = 0;
        }
        if ((var_r1 == 0x30) && (var_field == 0)) {
            return 1;
        }
        if (M2C_FIELD(&data_02102900, void **, 4) != NULL) {
            var_r0 = M2C_FIELD(M2C_FIELD(&data_02102900, void **, 4), s32 *, 4);
        } else {
            var_r0 = 0;
        }
        if (var_r0 == 0x35) {
            return 1;
        }
    }
    return 0;
}
