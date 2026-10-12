#include "m2c.h"

M2C_UNK func_02059efc(u32 *, s32);                  /* extern */
s32 func_0205e818(u32, M2C_UNK, M2C_UNK);           /* extern */

s32 func_02066dec(s32 arg0, u32 *arg1) {
    s32 temp_r0;

    temp_r0 = func_0205e818((u32) *arg1 >> 8, 3, 4);
    func_02059efc(arg1, temp_r0);
    return temp_r0;
}
