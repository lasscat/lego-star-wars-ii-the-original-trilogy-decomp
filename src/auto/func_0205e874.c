#include "m2c.h"

M2C_UNK func_0205e624(s32, M2C_UNK, s32);           /* extern */
s32 func_0205e818(s32, M2C_UNK, M2C_UNK);           /* extern */

void *func_0205e874(void *arg0, u16 arg1) {
    s32 temp_r0;

    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, u16 *, 4) = arg1;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    temp_r0 = func_0205e818(M2C_FIELD(arg0, u16 *, 4) * 4, 0, 4);
    M2C_FIELD(arg0, s32 *, 0) = temp_r0;
    func_0205e624(temp_r0, 0, M2C_FIELD(arg0, u16 *, 4) * 4);
    return arg0;
}
