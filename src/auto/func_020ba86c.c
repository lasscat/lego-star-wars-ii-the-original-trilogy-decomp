#include "m2c.h"

extern u32 data_0210db84[];
extern void func_020ba778();
extern void func_020ba798();

u8 func_020ba86c(s32 a0) {
    u8 buf[0x24];

    if (a0 == 0xffff) {
        return 0;
    }
    func_020ba778(M2C_FIELD(&data_0210db84, s32 *, 0x7c) + a0 * 0x24, 0);
    func_020ba798(buf, 0x24);
    return (buf[5] & 0x10) ? 1 : 0;
}
