#include "m2c.h"
M2C_UNK func_02018620(void *);
void func_02018680(void *arg0) {
    s32 temp_r0;
    s32 var_r5;
    temp_r0 = M2C_FIELD(arg0, u8 *, 7);
    if (temp_r0 != 0) {
        temp_r0                  = temp_r0 - 1;
        M2C_FIELD(arg0, u8 *, 7) = temp_r0;
        if ((temp_r0 & 0xFF) == 0) {
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x39C) = 0;
        }
    }
    var_r5 = M2C_FIELD(arg0, u8 *, 8);
    if (var_r5 == 0) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 7) != 0) {
        return;
    }
    M2C_FIELD(arg0, u8 *, 8) = 0;
    if (var_r5 <= 0) {
        return;
    }
    do {
        var_r5 -= 1;
        func_02018620(arg0);
    } while (var_r5 > 0);
}
