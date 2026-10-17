#include "m2c.h"

s32 func_02083340();                                /* extern */
extern M2C_UNK data_020f6ba8;

s32 func_020833b0(void) {
    s32 temp_r0;
    u16 var_r1;

    temp_r0 = func_02083340();
    var_r1  = *((u16 *) ((s8 *) &data_020f6ba8 + (temp_r0 * 0x24)));
    if (temp_r0 == 0x14) {
        var_r1 = 0x263;
    } else if (temp_r0 == 0x1B) {
        var_r1 = 0x264;
    }
    return (s32) var_r1;
}
