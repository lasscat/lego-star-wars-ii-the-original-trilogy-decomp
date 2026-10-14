#include "engine.h"
#include "m2c.h"

s32 func_0205d0d0(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r2;

    var_r2 = arg2;
    if (var_r2 == 4) {
        var_r2 = (s32) M2C_FIELD(arg0, u8 *, 0x2A);
    }
    if (M2C_FIELD(((var_r2 * 0xA) + arg0), u16 *, 4) & (u16) arg1) {
        return 1;
    }
    return 0;
}
