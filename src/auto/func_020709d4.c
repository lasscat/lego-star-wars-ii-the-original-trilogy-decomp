#include "m2c.h"

extern void **data_0210b348;

void func_020709d4(void) {
    s32 temp_r0;
    s32 temp_r2;
    s32 temp_r3;
    s32 var_ip;

    if (M2C_FIELD(*data_0210b348, s32(**)(), 0x5C)(data_0210b348) == 0) {
        return;
    }
    temp_r0 = M2C_FIELD(*data_0210b348, s32(**)(), 0x58)(data_0210b348);
    var_ip  = 0;
    do {
        temp_r3 = (var_ip * 0xC4) + temp_r0;
        temp_r2 = M2C_FIELD(temp_r3, s32 *, 0xC0);
        var_ip += 1;
        if (temp_r2 != 0) {
            M2C_FIELD(temp_r3, s32 *, 0xC0) = (s32) (temp_r2 - 1);
        }
    } while (var_ip < 0x10);
}
