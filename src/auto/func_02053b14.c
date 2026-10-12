#include "m2c.h"

u16 *func_020531d8();                               /* extern */
extern s32 data_027e02a8;

s32 func_02053b14(s32 *arg0) {
    s32 var_r4;

    if (data_027e02a8 & 0x200) {
        var_r4 = 0;
    } else {
        var_r4 = *arg0;
    }
    return (var_r4 << 0x15) + 0x06000000 + (((u32) (*func_020531d8() << 0x13) >> 0x1B) << 0xB);
}
