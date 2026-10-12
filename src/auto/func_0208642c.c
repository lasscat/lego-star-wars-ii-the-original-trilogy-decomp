#include "m2c.h"

void func_0208642c(s32 arg0) {
    u8 var_r2;
    void *temp_r1;

    var_r2 = 0;
    do {
        temp_r1 = arg0 + (var_r2 * 2);
        M2C_FIELD(temp_r1, s8 *, 0x4374) = 0;
        var_r2 += 1;
        M2C_FIELD(temp_r1, s8 *, 0x4375) = 0;
    } while ((u32) var_r2 < 0x64U);
}
