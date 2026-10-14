#include "m2c.h"

M2C_UNK func_02028398(s32, s32, s32);               /* extern */
s32 func_02028534(s32);                             /* extern */

void func_02028ea8(void *arg0, s32 arg1, s32 arg2) {
    void *temp_r2;

    if ((arg1 != 0) && (arg2 != 0)) {
        if (func_02028534(M2C_FIELD(arg0, s32 *, 0x10)) != 0) {
            return;
        }
        func_02028398(M2C_FIELD(arg0, s32 *, 0x10), arg1, arg2);
        temp_r2 = M2C_FIELD(arg0, void **, 0x14);
        if (temp_r2 == NULL) {
            return;
        }
        M2C_FIELD(temp_r2, s32 *, 8)   = (s32) (M2C_FIELD(temp_r2, s32 *, 8) | 2);
        M2C_FIELD(arg0, void **, 0x14) = NULL;
    }
}
