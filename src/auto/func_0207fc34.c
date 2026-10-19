#include "m2c.h"

M2C_UNK func_02005854(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

s32 func_0207fc34(void *arg0) {
    s32 temp_r1;

    if (M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 8) & 0x802) {
        return 1;
    }
    temp_r1 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_r1 < (s32) M2C_FIELD(arg0, u16 *, 0xC)) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_r1 + 1);
    } else {
        M2C_FIELD(arg0, s32 *, 8)   = 0;
        M2C_FIELD(arg0, s16 *, 0xE) = (s16) (M2C_FIELD(arg0, s16 *, 0xE) - 1);
        func_02005854(M2C_FIELD(arg0, void **, 4), 0, 0, 5, 0);
        if ((s32) M2C_FIELD(arg0, s16 *, 0xE) <= 0) {
            return 1;
        }
    }
    return 0;
}
