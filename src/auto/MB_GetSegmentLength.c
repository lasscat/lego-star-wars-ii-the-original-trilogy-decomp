#include "m2c.h"

u32 func_020d2cbc(void *, M2C_UNK *, M2C_UNK);      /* extern */
M2C_UNK FS_SeekFile(void *, s32, M2C_UNK);        /* extern */

u32 MB_GetSegmentLength(void *arg0) {
    u8 sp0[96];
    M2C_UNK *var_r4;
    u32 var_r5;
    s32 temp_r6;

    var_r4 = NULL;
    var_r5 = 0;
    if (arg0 != NULL) {
        temp_r6 = M2C_FIELD(arg0, s32 *, 0x2C) - M2C_FIELD(arg0, s32 *, 0x24);
        if (func_020d2cbc(arg0, sp0, 0x60) >= 0x60U) {
            var_r4 = sp0;
        }
        FS_SeekFile(arg0, temp_r6, 0);
    } else {
        var_r4 = (M2C_UNK *) 0x027FFE00;
    }
    if (var_r4 != NULL) {
        var_r5 = M2C_FIELD(var_r4, s32 *, 0x2C) + 0x268 + M2C_FIELD(var_r4, s32 *, 0x3C);
        if (var_r5 < 0x10000U) {
            var_r5 = 0x10000;
        }
    }
    return var_r5;
}
