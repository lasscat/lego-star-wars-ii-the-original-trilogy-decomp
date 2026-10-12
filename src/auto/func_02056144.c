#include "m2c.h"

M2C_UNK func_02018200(s32, s32, M2C_UNK);           /* extern */
s32 func_02067080(M2C_UNK, u8, u8);                 /* extern */

void func_02056144(M2C_UNK arg0, void *arg1) {
    s32 temp_r1;
    s32 temp_r4;

    temp_r4 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 0), M2C_FIELD(arg1, u8 *, 1));
    temp_r1 = func_02067080(arg0, M2C_FIELD(arg1, u8 *, 2), M2C_FIELD(arg1, u8 *, 3));
    if ((temp_r4 != 0) && (temp_r1 != 0)) {
        func_02018200(temp_r4, temp_r1, 0);
    }
}
