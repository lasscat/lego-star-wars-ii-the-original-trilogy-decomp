#include "m2c.h"

M2C_UNK func_020cd4e4(void *);                      /* extern */
s32 func_020ce804();                                /* extern */
M2C_UNK func_020ce818(s32);                         /* extern */
s32 func_020d14ac(void *, s32);                     /* extern */
void *func_020d2088(s32);                           /* extern */

void func_020d229c(void *arg0) {
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r0;
    void *var_r6;

    var_r6  = arg0;
    temp_r4 = M2C_FIELD(var_r6, volatile s32 *, 8);
    if (var_r6 == NULL) {
        return;
    }
loop_3:
    temp_r5                                = func_020ce804();
    M2C_FIELD(var_r6, volatile s32 *, 0xC) = (s32) (M2C_FIELD(var_r6, volatile s32 *, 0xC) | 0x40);
    if (M2C_FIELD(var_r6, volatile s32 *, 0xC) & 4) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        func_020cd4e4(var_r6 + 0x18);
        func_020ce818(temp_r5);
        return;
    }
    M2C_FIELD(var_r6, volatile s32 *, 0xC) = (s32) (M2C_FIELD(var_r6, volatile s32 *, 0xC) | 8);
    func_020ce818(temp_r5);
    if (func_020d14ac(var_r6, M2C_FIELD(var_r6, volatile s32 *, 0x10)) == 6) {
        return;
    }
    var_r6 = func_020d2088(temp_r4);
    if (var_r6 == NULL) {
        return;
    }
    goto loop_3;
}
