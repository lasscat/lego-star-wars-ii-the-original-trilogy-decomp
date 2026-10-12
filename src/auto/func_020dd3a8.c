#include "m2c.h"

M2C_UNK func_020cf344(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_0211e444;

void func_020dd3a8(s32 arg0) {
    s32 temp_r4;

    if (M2C_FIELD(&data_0211e444, s32 *, 4) == 0) {
        return;
    }
    temp_r4 = arg0 - 1;
    func_020cf344(M2C_FIELD(&data_0211e444, s32 *, 4) + (temp_r4 << 5), 0, 0x1E);
    M2C_FIELD((M2C_FIELD(&data_0211e444, s32 *, 4) + (temp_r4 * 4)), s32 *, 0x1E0) = 0;
}
