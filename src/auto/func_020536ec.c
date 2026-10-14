#include "m2c.h"

void *func_020531d8();                       /* extern */
s32 func_02053964();                         /* extern */
s32 func_020539c8();                         /* extern */

void func_020536ec(M2C_UNK arg0, void *arg1) {
    void *temp_r0;
    void *temp_r0_2;
    void *temp_r0_3;

    temp_r0                        = func_020531d8();
    M2C_FIELD(temp_r0, s32 *, 8)   = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(temp_r0, s32 *, 0xC) = (s32) M2C_FIELD(arg1, s32 *, 4);
    if ((func_020539c8(arg0) != 0) || (func_02053964(arg0) != 0)) {
        temp_r0_2                      = func_020531d8(arg0);
        M2C_FIELD(temp_r0_2, s32 *, 4) = (s32) (M2C_FIELD(temp_r0_2, s32 *, 4) | 1);
        return;
    }
    temp_r0_3                      = func_020531d8(arg0);
    M2C_FIELD(temp_r0_3, s32 *, 4) = (s32) (M2C_FIELD(temp_r0_3, s32 *, 4) | 2);
}
