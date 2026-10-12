#include "m2c.h"

s32 func_0205a348(void *);                          /* extern */
M2C_UNK func_0205a868(void *);                      /* extern */
s32 func_0205e818(s32, M2C_UNK, M2C_UNK);           /* extern */

void *func_02059fb4(void *arg0, s16 arg1, s16 arg2, s32 arg3) {
    s32 temp_r0;

    M2C_FIELD(arg0, s32 *, 0) = 0;
    M2C_FIELD(arg0, s16 *, 4) = arg1;
    M2C_FIELD(arg0, s16 *, 6) = arg2;
    M2C_FIELD(arg0, s8 *, 8) = 0;
    M2C_FIELD(arg0, s8 *, 9) = 0;
    M2C_FIELD(arg0, s32 *, 0xC) = arg3;
    if ((arg3 != 2) && (arg3 != 3) && (arg3 != 4)) {
        M2C_FIELD(arg0, s32 *, 0xC) = 4;
    }
    temp_r0 = func_0205a348(arg0);
    M2C_FIELD(arg0, s32 *, 0) = func_0205e818((temp_r0 * 2) - temp_r0, 3, 4);
    func_0205a868(arg0);
    return arg0;
}
