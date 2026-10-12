#include "m2c.h"
#include "engine.h"

s32 func_0205d0f8(s32 arg0, s32 arg1) {
    u8 var_ip;
    u8 var_lr;

    var_ip = 0;
loop_1:
    var_lr = var_ip;
    if (var_ip == 4) {
        var_lr = M2C_FIELD(arg0, u8 *, 0x2A);
    }
    if (M2C_FIELD(((var_lr * 0xA) + arg0), u16 *, 4) & (u16) arg1) {
        return 1;
    }
    var_ip += 1;
    if ((u32) var_ip >= 4U) {
        return 0;
    }
    goto loop_1;
}
