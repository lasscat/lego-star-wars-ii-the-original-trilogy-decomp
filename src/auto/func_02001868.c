#include "m2c.h"

M2C_UNK func_020bba04();
M2C_UNK func_0205e84c();
extern M2C_UNK data_020fcc68;
extern M2C_UNK data_021019f4;
extern M2C_UNK data_02101a64;

void *func_02001868(void *arg0) {
    s32 temp_r1;
    s32 var_r2;
    s8 *temp_r0;

    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fcc68;
    if (M2C_FIELD(arg0, s32 *, 8) & 0x80000000) {
        var_r2 = 0;
    } else {
        var_r2 = 1;
    }
    temp_r0 = (s8 *) &data_021019f4 + var_r2 * 0x38;
    M2C_FIELD(M2C_FIELD(temp_r0 - (s8 *) 0, void **, 0), M2C_UNK(**)(s8 *, void *), 0xC)(temp_r0, arg0);
    temp_r1 = M2C_FIELD(arg0, s32 *, 8);
    if ((temp_r1 & 4) == 4) {
        if (temp_r1 & 0x80000000) {
            var_r2 = 0;
        } else {
            var_r2 = 1;
        }
        temp_r0 = (s8 *) &data_02101a64 + var_r2 * 0x38;
        M2C_FIELD(M2C_FIELD(temp_r0 - (s8 *) 0, void **, 0), M2C_UNK(**)(s8 *, void *), 0xC)(temp_r0, arg0);
    }
    func_020bba04((s8 *) arg0 + 4);
    func_0205e84c(arg0);

    return arg0;
}
